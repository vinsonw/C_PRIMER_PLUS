#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch;
    int uc_cnt=0, lc_cnt=0, oc_cnt=0;
    printf("give some input, you know the drill:\n");

    while ((ch=getchar()) != EOF)
    {
        if (isupper(ch))
            uc_cnt++;
        else if (islower(ch))
            lc_cnt++;
        else  
            oc_cnt++;

    }

    printf("\nReport: %d uppercases "
    "%d lowercases "
    "%d other characters.\n",
    uc_cnt, lc_cnt, oc_cnt
    );

    return 0;

}