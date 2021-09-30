#include <stdio.h>
#define START_CHR 'A'
#define END_CHR 'Z'

int main(void)
{
    char ROWS = END_CHR - START_CHR + 1;
    int row_index;
    int col_index;
    for (row_index=0; row_index<ROWS; row_index++)
    {
        for (col_index=0; col_index<row_index+1; col_index++)
            printf("%c", END_CHR - col_index);
        printf("\n");
    }

    return 0;
}