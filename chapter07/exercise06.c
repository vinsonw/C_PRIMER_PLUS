#include <stdio.h>

int main(void)
{
    char pre_ch=' '; // "pre_ch" is assigned an imaginery space character.
    char ch;
    int ei_cnt=0;

    while ((ch = getchar()) != '#')
    {
        if (pre_ch == 'e' && ch == 'i')
            ei_cnt++;
        pre_ch = ch;
    }
    printf("Alright, there are %d 'ei' occurences.\n", ei_cnt);

    return 0;

}