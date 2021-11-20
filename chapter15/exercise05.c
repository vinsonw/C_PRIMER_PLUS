#include <stdio.h>
#include <limits.h>

int rotate_l(unsigned int d, unsigned int offset);
char *dec_to_binstr(int d, char *s, int size);

int main(void)
{
    unsigned int d = 144987478;
    unsigned int toleft_offset = 5;
    const static int size_in_bit = CHAR_BIT * sizeof( int );
    char bs[size_in_bit+1];
    printf("%d's binary form is \n%s\n", d, dec_to_binstr(d, bs, size_in_bit));
    printf("rotate to left %d times, you get:\n%s\n", toleft_offset, 
    dec_to_binstr(rotate_l(d, toleft_offset), bs, size_in_bit));

    printf("Here are the steps:\n");
    unsigned int i=0;
    while (1)
    {
        // this code is somehow slow, and I thought it was a bug.
        printf("%s\n", dec_to_binstr(rotate_l(d, i++), bs, size_in_bit));
        if (i==toleft_offset+1)
            break;
    }
}



int rotate_l(unsigned int d, unsigned int offset)
{
    const static int size_in_bit = CHAR_BIT * sizeof( int );
    offset %= size_in_bit;
    int overflow;

    // prepare a mask that could 
    // get the digits that are to overflow out of high order side 
    int mask = 1;
    for (int i=0; i<offset-1; i++)
    {
        mask <<= 1;
        mask += 1;
    }
    mask <<= (size_in_bit - offset);

    // get the dights that are to overflow using the mask
    // and move them to the rightmost position 
    overflow = mask & d;
    overflow >>= (size_in_bit - offset);
    
    // do overflow
    d <<= offset; 

    // merge back the overflow
    d = (d | overflow);

    return d;
}

char *dec_to_binstr(int d, char *s, int size)
{
    char ch;
    for (int i=size-1; i>-1; i--)
    {
        ch = (1 & d) + '0';
        s[i] = ch;
        d >>= 1;
    }
    s[size] = '\0';
    return s;
}
