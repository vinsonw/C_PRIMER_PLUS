#include <stdio.h>
#include <ctype.h>

void reverse_that_string(char *);
char get_first_char(void);

int main(void)
{
    while (1)
    {
        char s[20];
        printf("give something and i will reverse it.\n");

        // Recall that fgets() reads up to
        // newline or n-1 characters,
        // whichever comes first.
        fgets(s, 20, stdin);

        while (getchar() != '\n')
            ;
        reverse_that_string(s);

        puts(s);
        printf("Somebody makes me ask this:\n"
        "do you want to do this again?(type 'q' to quit, else to continue)\n");
        if (get_first_char() == 'q')
            break;
    }
    return 0;
}

void reverse_that_string(char * s)
{
    int index=0;
    while (*(s+index))
        index++;

    index--;
    int cursor;
    char ch;
    for (cursor = 0; 2*cursor < index; cursor++)
    {
        ch =  s[index-cursor];
        s[index-cursor] = s[cursor];
        s[cursor] = ch; 
    }
}

char get_first_char(void)
{
    char ch;
    while (isspace(ch=getchar()))
        ;
    while (getchar() != '\n')
        ; 

    return ch;
}