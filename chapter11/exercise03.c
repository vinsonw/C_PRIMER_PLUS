#include <stdio.h>
#include <ctype.h>
#define WORDSIZE 20
void get_first_word(char *);

int main(void)
{
    char word[WORDSIZE];
    char ch;

    get_first_word(word);
    puts(word);

    return 0;
}


void get_first_word(char * spt)
{
    int cnt = 0;
    char ch;

    // get rid of leading whitespaces
    while (isspace(ch=getchar()))
        continue;

    // store non-whitespace characters until another whitespace
    // or reaching end if array, whichever comes first.
    do { 
        *(spt+cnt) = ch; 
        cnt++;
    } while (!(isspace(ch=getchar())) && cnt < WORDSIZE-1);

    // store the first word as a string(mannual appending '\0')
    *(spt+cnt) = '\0';
    
}