#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch;
    int wd_cnt=0, ch_cnt=0;
    char pre_ch=' ';

    while ((ch=getchar()) != EOF)
    {
        if (isspace(pre_ch) && !(isspace(ch)))
            wd_cnt++;
        if (!(isspace(ch)) && !(ispunct(ch)))
            ch_cnt++;
        pre_ch = ch;
    }

    printf("\nReport: %d words "
    "%d characters "
    "%.2f characters/word\n",
    wd_cnt, ch_cnt, (double) ch_cnt / wd_cnt 
    );
    
}
