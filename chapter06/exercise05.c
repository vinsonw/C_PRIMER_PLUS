#include <stdio.h>
#define START_CHR 'A'
#define END_CHR 'Z'

int main(void)
{
    short ROWS = END_CHR - START_CHR + 1;
    short row_index;
    short col_index;
    short cursor; 
    short num_of_space_for_indentation;
    for (row_index=0; row_index<ROWS; row_index++)
    {
        num_of_space_for_indentation = END_CHR - START_CHR - row_index;
        // this loop handles space indentation
        for (cursor=0; cursor<num_of_space_for_indentation; cursor++)
            printf(" ");
        // this loop handles printing characters in ascending order
        for (col_index=0; col_index<row_index+1; col_index++)
            printf("%c", START_CHR+col_index);
        // this loop handles printing characters in descending order
        for (col_index=0; col_index<row_index; col_index++)
            printf("%c", START_CHR+row_index-col_index-1);
        printf("\n");
    }

    return 0;
}
