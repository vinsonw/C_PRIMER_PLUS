#include <stdio.h>

int bit_on(int, int);
char *dec_to_binstr(int d, char *s, int size);

int main(void)
{
    const static int size = 8 * sizeof(int);
    char bs[size+1];
    int d = 100;
    int pos = 5; // assume pos start from 1 and from right side
    printf("%d's binary form is:\n%s\nbit %d is %d\n", 
    d, dec_to_binstr(d, bs, size), pos, bit_on(d, pos));
}


int bit_on(int d, int pos)
{
    d >>= (pos-1);
    return 1 & d;
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
