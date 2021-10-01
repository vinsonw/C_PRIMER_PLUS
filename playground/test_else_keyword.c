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
        // the final "else" is left out here to test if it's okay to ommit it -- tested okay
        printf("Done\n");
    }

        return 0;
    }