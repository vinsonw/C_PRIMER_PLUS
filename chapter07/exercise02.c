#include <stdio.h>

int main(void)
{
    char ch;
    int index = 0;
    char arr[8];

    printf("Give me some input.\n");
    while ((ch=getchar()) != '#')
    {
        if (ch == '\n')
            continue; // not display the ending '\n' resulting from hitting [Enter] key.
        index++;
        printf("'%c':%d ", ch, ch);
        if (index % 8 == 0)
            printf("\n");
    }


    return 0;
    

}