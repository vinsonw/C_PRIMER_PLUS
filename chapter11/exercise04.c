#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
// #define WORDSIZE 20
void get_first_word(char *, int);

int main(int argc, char * argv[])
{
    if (argc !=2 || atoi(argv[1]) < 1)
    {
        printf("Input 'e4 positive-number'\n");
        return 0;
    }
    // without const is also okay, which is a lit bit strange
    // "+1" let WORDSIZE could accommodate the extra '\0'
    const int WORDSIZE = atoi(argv[1]) + 1;
    char word[WORDSIZE];
    char ch;

    get_first_word(word, WORDSIZE);
    puts(word);

    return 0;
}


void get_first_word(char * spt, int WORDSIZE)
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