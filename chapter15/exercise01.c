#include <stdio.h>
#include <string.h>

int bin_to_dec(char *s);
int chr_to_num(char chr);
int two_to_power(int exp);

int main(void)
{
    char *pbin = "01001001";
    printf("%s is %d\n", pbin, bin_to_dec(pbin));

    return 0;
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
