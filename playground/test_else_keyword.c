#include <stdio.h>

int main(void)
{
    printf("Please enter an integer: ");
    int input;
    while ( 1==scanf("%d", &input) )
    {
        if (input < 2)
            printf("<2\n");
        else if (input < 5)
            printf("[2,5)\n");

        printf("Done\n");
    }

        return 0;
    }