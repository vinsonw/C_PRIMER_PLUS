#include <stdio.h>
#include <string.h>

int main(void)
{
    char intput[256];
    char ch, cursor=0;
    printf("Now it's the time to type in something: ");
    scanf("%c", &ch); // scanf() with "%c" read whitespaces as normal characters.
    while (ch != '\n')
    {
        intput[cursor] = ch;
        cursor++;
        scanf("%c", &ch);

    }
    int len_of_string = strlen(intput);
    for (cursor=0; cursor<len_of_string; cursor++)
        printf("%c", intput[len_of_string-1-cursor]);

    return 0;
}    
