#include <stdio.h>
#define CHR '$'
#define ROWS 5
#define COLUMNS 5 


int main(void)
{
    int i,j;

    for (i=0; i<ROWS; i++)
    {
        for (j=0; j<i+1; j++)
        {
            printf("%c", CHR);
        }

        printf("\n");
    }

    return 0;
}