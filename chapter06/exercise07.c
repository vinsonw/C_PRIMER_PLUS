#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[20];
    printf("Please enter a word that has less than 20 letters: ");
    scanf("%s", input);
    int len = strlen(input);
    int letter_cursor;
    for (letter_cursor=len-1; letter_cursor>-1; letter_cursor--)
        printf("%c", input[letter_cursor]);
    printf("\n");

    return 0;
}