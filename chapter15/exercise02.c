#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *dec_to_binstr(int d, char *s, int size);
// char *literal_tilde(int d, char *s, int size);
int bin_to_dec(char *s);
int chr_to_num(char chr);
int two_to_power(int exp);


int main(int argc, char *argv[])
{
    if ( argc != 3)
    {
        printf("wrong input, bye.\n");
        exit(0);
    }

    int a1 = bin_to_dec(argv[1]);
    int a2 = bin_to_dec(argv[2]);
    int a1_tilde = ~a1;
    int a2_tilde = ~a2;
    int r1_bit_and = a1 & a2;
    int r2_bit_or = a1 | a2;
    int r3_bit_xor = a1 ^ a2;

    const static int size = sizeof(int) * 8;
    char bs[size+1];
    char bs1[size+1];
    char bs2[size+1];
    char bs3[size+1];
    char bs4[size+1];

    // Bug version:
    // All calls to dec_to_binstr() are evaluated first, and the evaluation
    // order is undefined -- in this case, the calls are evaluated backwards,
    // then printf() prints the outcome. Since every call to dec_to_binstr() returns 
    // the fixed address of the first char in array "bs", only the last evaluated 
    // "dec_to_binstr(a1, bs, size)" has effect that was left in the array "bs", 
    // that why all the outcomes are the same result as "dec_to_binstr(a1, bs, size)"

    // printf(">>> OUTCOME <<<\n"
    // "~%s == %s\n"
    // "~%s == %s\n"
    // "%s & %s == %s\n"
    // "%s | %s == %s\n"
    // "%s ^ %s == %s\n",
    // argv[1], dec_to_binstr(a1, bs, size),
    // argv[2], dec_to_binstr(a2, bs, size),
    // argv[1], argv[2], dec_to_binstr(r1_bit_and, bs, size),
    // argv[1], argv[2], dec_to_binstr(r2_bit_or, bs, size),
    // argv[1], argv[2], dec_to_binstr(r3_bit_xor, bs, size)
    // );

    printf(">>> OUTCOME <<<\n"
    "%-s%-25s == %s\n"
    "%-s%-25s == %s\n"
    "%-s%-s%-19s == %s\n"
    "%-s%-s%-19s == %s\n"
    "%-s%-s%-19s == %s\n",
    "~", argv[1], dec_to_binstr(a1_tilde, bs, size),
    "~", argv[2], dec_to_binstr(a2_tilde, bs1, size),
    argv[1], " & ", argv[2], dec_to_binstr(r1_bit_and, bs2, size),
    argv[1], " | ", argv[2], dec_to_binstr(r2_bit_or, bs3, size),
    argv[1], " ^ ", argv[2], dec_to_binstr(r3_bit_xor, bs4, size)
    );



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

int bin_to_dec(char *s)
{
    int len = strlen(s);
    int rv=0;
    for (int i=0; i<len; i++)
        rv += chr_to_num(*(s+i)) * two_to_power(len-i-1);

    return rv;
}

int chr_to_num(char chr)
{
    return 1*('1' == chr);
}

int two_to_power(int exp)
{
    int rv=1;
    for (int i=0; i<exp; i++)
        rv *= 2;
    return rv;
}
