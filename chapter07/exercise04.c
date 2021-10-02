#include <stdio.h>

int main(void)
{
    char ch;
    int chg_cnt=0;
    printf("Give some input with period and exclamation marks in it: \n");
    while ((ch = getchar()) != '#')
    {
        if (ch == '.')
        {
            putchar('!');
            chg_cnt++;
        }
        else if (ch == '!')
        {
            printf("!!");
            chg_cnt++;
        }
        else
            putchar(ch);

    }

    printf("Totoally %d changes made.\n", chg_cnt);

    return 0;
    
}