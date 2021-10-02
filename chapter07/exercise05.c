#include <stdio.h>

int main(void)
{
    char ch;
    int chg_cnt=0;
    printf("Give some input with period and exclamation marks in it: \n");
    while ((ch = getchar()) != '#')
    {
        switch (ch)
        {
        case '.':
            putchar('!');
            chg_cnt++;
            break;
        case '!' :
            printf("!!");
            chg_cnt++;
            break;
        default:
            putchar(ch);
        }

    }

    printf("Totoally %d changes made.\n", chg_cnt);

    return 0;
    
}