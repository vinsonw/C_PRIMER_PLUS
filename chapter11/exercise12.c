#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char pre_ch=' ', ch;
    int wd_cnt=0, lc_cnt=0, uc_cnt=0, pc_cnt=0, dt_cnt=0;

    while ( (ch = getchar()) != EOF )
    {
        if ( isspace(pre_ch) && !(isspace(ch)) )
            wd_cnt++;
        if ( isupper(ch) )
            uc_cnt++;
        if ( islower(ch) )
            lc_cnt++;
        if ( ispunct(ch) )
            pc_cnt++;
        if ( isdigit(ch) )
            dt_cnt++;
        pre_ch = ch;
            
    }

    printf(
        "words: %d\n"
        "uppercases: %d\n"
        "lowercases: %d\n"
        "punctuations: %d\n"
        "digits: %d\n",
        wd_cnt, uc_cnt, lc_cnt, pc_cnt, dt_cnt
    );
    
    return 0;
}