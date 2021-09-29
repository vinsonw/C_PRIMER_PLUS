#include <stdio.h>

void pound(int n); // the argument type "int n" helps automatic typecast.

int main(void)
{
    int times = 5;
    char ch = '!';
    float f = 6.0;
    pound(times);
    pound(ch);
    pound(f); // without the argument type "int n" in pound() prototyping, this won't work properly. See Vol1. Page 180.

    return 0;
}

void pound(int n)
{
    while (n-- > 0) // mistakenly, n-- > n would always be true and the loop goes forever.
    {
        printf("#");
    }
    printf("\n");
}