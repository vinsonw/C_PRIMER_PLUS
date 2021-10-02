// rewrite Review Question 9 without continue and goto keywords.
#include <stdio.h>

int main(void)
{
    char ch;

    while ( (ch = getchar()) != '#')
    {
        if (ch != '\n')
            printf("Step 1\n");

        if (ch != '\n' && ch != 'c' && ch != 'h' && ch != 'b')
        {

            printf("Step 2\n");
            printf("Step 3\n");
            
        }
        if (ch != '\n' && ch == 'h')
            printf("Step 3\n");
        if (ch != '\n' && ch == 'b')
            break;

    }
    printf("Done\n");

    return 0;
}