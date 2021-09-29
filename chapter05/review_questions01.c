#include <stdio.h>

int main(void)
{
    char a = 'a';
    while (a <= 'g')
    {
        printf("%c", a);
        a++;
    }
    printf("\n");

    return 0;
}