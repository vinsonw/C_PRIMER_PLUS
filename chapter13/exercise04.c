// This emulates Listing 13.5 P590 Vol 2.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE 4096 // 2 ^ 12

void append(FILE *source, FILE *dest);
char *s_gets(char *, int);

int main(int argc, char *argv[])
{
    FILE *f;
    int files = 0;
    int ch;


    for (int i=1; i<argc; i++) 
    {
        if ( (f = fopen(argv[i], "r")) == NULL )
        {
            fprintf(stderr, "Can't open %s\n", argv[i]);
            continue;
        }
        else
        {
            if ( setvbuf(f, NULL, _IOFBF, BUFSIZ) != 0 )
            {
                fputs("Can't create input buffer\n", stderr);
                continue;
            }
        }

        while ( (ch=getc(f)) != EOF )
            putchar(ch);

        fclose(f);
        files++;

        printf("-------- %s displayed------\n", argv[i]);
        
    }

    printf("--------%d files displayed.-----------\n", files);

    return 0;
}
