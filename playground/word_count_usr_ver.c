#include <stdio.h>
#include <ctype.h>
#define STOP '@'

int main(void)
{
    long ch_cnt = 0L;
    int wd_cnt = 0;
    int ln_cnt = 1, p_ln_cnt = 0;
    char ch, pre_ch;

    printf("Give some input, end with symbol '%c': \n", STOP);
    pre_ch = getchar();
    if (pre_ch == STOP)
        return 0;

    ch_cnt++;

    if (!isspace(pre_ch)) 
        wd_cnt++;

    if (pre_ch == '\n')
        ln_cnt++;
    
    while ((ch = getchar()) != STOP)
    {
        ch_cnt++;
        if (isspace(pre_ch) && !isspace(ch))
            wd_cnt++;
        if (ch == '\n')
            ln_cnt++;
        pre_ch = ch;

    }

    if (pre_ch != '\n')
        p_ln_cnt++;
    else
        ln_cnt--; // when pre_ch == '\n', the beginning ln_cnt=1 is extra.


    printf("okay, you just input %d characters, %d words, %d lines(%d partial lines) of text.\n",
        ch_cnt, wd_cnt, ln_cnt, p_ln_cnt);


    return 0;
}
