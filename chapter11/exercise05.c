#include <stdio.h>
#include <ctype.h>
#define SIZE 40


char get_first_char(void);

char * search_char(char *, char);

int main(void)
{
    while (1)
    {
        printf("Please input a string(<%d characters):", SIZE);
        char str[SIZE];
        fgets(str, SIZE, stdin);

        // find out the location of '\0' added by fgets()
        int index=0;
        while (*(str+index) != '\0')
            index++;

        // In array "str", if the left location of '\0'
        // is not '\n', it means there are characters left
        // in stdin(at least '\n' caused by [Enter] is left there),
        // in which case they need to be got rid of, lest affecting
        // the following input
        if (*(str+index-1) != '\n')
            while (getchar() != '\n')
                continue;

        puts("Please input a character to search:");
        char ch = get_first_char();

        char * aha;
        if ( aha = search_char(str, ch) )
            printf("okay, first occurence at %d, starting there is \"%s\"\n",
             aha-str+1,
             aha
             );

        else
            printf("there's no match in the string.\n");

        printf("do you want to do this again(y to continue, q to quit)?\n");
        if (get_first_char() == 'q')
            break;
        
    }

   return 0; 
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

char * search_char(char * str, char ch)
{
    // find out the location of '\0' added by fgets()
    int index=0;
    while (*(str+index) != '\0')
        index++;

    int cursor=0;
    while (*(str+cursor) != ch && cursor < index)
        cursor++;
    if (cursor == index) 
        return NULL;
    else
        return str+cursor;

}