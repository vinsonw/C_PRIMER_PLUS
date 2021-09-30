#include <stdio.h>
#define START_CHR 'A'
#define END_CHR 'Z'

int main(void)
{
    int row_index=0;
    int col_index;
    char current_chr = START_CHR;
    while (current_chr < END_CHR + 1)
    {
        for(col_index=0; col_index<row_index+1 && current_chr<END_CHR+1; col_index++)
        {
            printf("%c", current_chr); 
            current_chr++;
        }
        printf("\n");
        row_index++;

    }
    

    return 0;
}