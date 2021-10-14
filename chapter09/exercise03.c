#include <stdio.h>
#define CHR '@'

void print_char(char, int, int);

int main(void)
{
    print_char(CHR, 2, 3);

    return 0;

}


void print_char(char ch, int cols, int rows)
{
    int i,j;
    for (i=0; i<rows; i++)
    {
        for (j=0; j<cols; j++)
            putchar(ch);
        printf("\n");
    }

}