#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch;
    int cnt=0;
    printf("give some input, you know the drill:\n");
    while ( (ch = getchar()) != EOF)
    {

        if (isprint(ch)) 
            printf("[%c]-[%d] ", ch, ch);
        else if (ch=='\n')
            printf("\n[\\n]-[%d]", ch);
        else if (ch=='\t')
            printf("[\\t]-[%d] ", ch);
        else
            printf("[^%c]-[%d] " , ch+64, ch);

        cnt++;
        if (cnt % 10 == 0)
            printf("\n");
    }

    printf("\ndone.\n");

    return 0; 
}