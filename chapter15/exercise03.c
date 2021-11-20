#include <stdio.h>
#include <stdlib.h>

char *dec_to_binstr(int d, char *s, int size, int *on_bits_cnt);
void eatline(void);

int main(void)
{
    printf("Input a number to count the bits in it that're on.\n"
    "q to quit.\n"
    );

    char ch;
    scanf("%c", &ch);
    if ('q' == ch)
        exit(0);
    else
        ungetc(ch, stdin);

    const static int size = sizeof(int);
    char bs[size+1];

    int input_num;
    while ( scanf("%d", &input_num) != 1 )
    {
        eatline();
        printf("wrong input, try again?\n");
    }
    eatline();

    int on_bits_cnt=0;
    dec_to_binstr(input_num, bs, size, &on_bits_cnt);
    bs[size] = '\0';
    printf("binary form for %d:\n%s, %d bits on.\n", input_num, bs, on_bits_cnt);

}

char *dec_to_binstr(int d, char *s, int size, int *on_bits_cnt)
{
    char ch;
    for (int i=size-1; i>-1; i--)
    {
        ch = (1 & d) + '0';
        s[i] = ch;
        d >>= 1;
        if ('1' == ch)
            (*on_bits_cnt)++;
    }
    s[size] = '\0';
    return s;
}

void eatline(void)
{
    while ( getchar() != '\n' )
        continue;
}
