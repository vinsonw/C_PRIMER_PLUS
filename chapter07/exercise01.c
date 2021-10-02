#include <stdio.h>

int main(void)
{
    char ch;
    int sp_cnt = 0;
    int nl_cnt = 0;
    int oc_cnt = 0;

    while ((ch=getchar()) != '#')
    {
        switch (ch)
        {
        case ' ':
            sp_cnt++;
            break;
        case '\n':
            nl_cnt++;
            break;
        default:
            oc_cnt++;
        }

    }

    printf("So you've input %d characters, excluding %d spaces, %d newlines.\n", oc_cnt, sp_cnt, nl_cnt);

    return 0;
    

}