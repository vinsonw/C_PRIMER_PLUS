#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fputs("Too few arguments.", stderr);
        exit(EXIT_FAILURE);
    }

    if (argc == 2)
    {
        puts("I'm gonna repeat what"
        "you type, until you send EOF."
        );
        char ch;
        while ( (ch=getchar()) != EOF )
            putchar(ch);
        while ( getchar() != '\n')
            continue;
        exit(0);
    }

    char ch, ch_iter;
    ch = *argv[1];
    FILE * f_iter;
    for (int i=2; i<argc; i++)
    {
        if ( (f_iter = fopen(argv[i], "r")) == NULL )
        {
            fprintf(stderr, "Couldn't open %s\n", argv[i]);
            continue;
        }


        int count=0;
        while ( (ch_iter=getc(f_iter)) != EOF )
            if (ch_iter == ch)
                count++;

        fclose(f_iter);

        printf("%s includes \"%c\": %d\n", argv[i], ch, count);
    }
    puts("Done.");
}
