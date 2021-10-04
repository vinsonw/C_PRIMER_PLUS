/*
 * On linux, by default, there is a '\n' at the end of a line
 * even there's only one line, and that affects this program's behavior (alway count one character 
 * more than you could see.)
*/
#include <stdio.h>

int main(void)
{
    int ch;
    int cnt=0;

    while ((ch=getchar()) != EOF)
    {
        cnt++;
        // printf("%c\n", ch);
    }

    printf("Total characters: %d\n", cnt);

    return 0;
    
}

