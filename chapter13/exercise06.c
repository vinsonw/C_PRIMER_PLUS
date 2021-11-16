// revision of Listing 13.2 at Page 574 Vol.2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLEN 30

char *s_gets(char *, int);

int main(void)
{
    FILE *in, *out;
    int ch;
    char ins[SLEN];
    char outs[SLEN];
    int count = 0;
    puts("Please enter the name of the file you want to decrypt:");
    s_gets(ins, SLEN);
    if ( (in = fopen(ins, "r")) == NULL )
    {
        fprintf(stderr, "Couldn't open %s\n", ins);
        exit(EXIT_FAILURE);
    }
    strncpy(outs, ins, SLEN-9);
    outs[SLEN-9] = '\0';
    strcat(outs, ".out.txt");
    if ( (out = fopen(outs, "w")) == NULL )
    {
        fprintf(stderr, "Couldn't open %s\n", outs);
        exit(EXIT_FAILURE);
    }

    puts("Please enter a number that represents the interval you want to extract the characters.");
    int interval;
    scanf("%d", &interval);
    if ( interval < 0)
    {
        fputs("You know, actually, you have to input a number that is greater than 0\n", stderr);
        exit(EXIT_FAILURE);
    }


    while ( (ch = getc(in)) != EOF )
        if ( count++ % (interval+1) == 0 )
            putc(ch, out);
    if ( fclose(in) !=0 || fclose(out) != 0 ) 
    {
        fputs("We have problem in closing files\n", stderr);
        exit(EXIT_FAILURE);
    }
    
    puts("Okay, done.");
    return 0;
}

char *s_gets(char * s, int n)
{
    char *rv;
    char *find;
    rv = fgets(s, n, stdin);

    if (rv)
    {
        find = strchr(s, '\n');
        if (find)
            *find = '\0';
        else
            while ( getchar() != '\n' )
                continue;
    }

    return rv;
}