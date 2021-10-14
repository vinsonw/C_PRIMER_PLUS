#include <stdio.h>

void chline(char, int, int);

int main(void)
{
    chline('@', 3, 9);

    return 0;
}

void chline(char ch, int i, int j)
{
    int m,n;
    for (m=i; m<=j; m++)
    {
        for (n=0; n<m; n++)
            putchar(ch);
        printf("\n");
    }
}