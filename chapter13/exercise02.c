// This emulates Listing 13.5 P590 Vol 2.
// usage:
// <binary> dest source
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096 // 2 ^ 12

void append(FILE *source, FILE *dest);
char *s_gets(char *, int);

int main(int argc, char *argv[])
{
    FILE *fs, *fd;
    int files = 0;
    int ch;

    if (argc == 1)
    {
        printf("No file to copy or paste, bye.\n");
        exit(EXIT_FAILURE);
    }

    if ( (fd = fopen(argv[1], "ab+")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[1]);
    }

    if ( setvbuf(fd, NULL, _IOFBF, BUFSIZE) != 0 )
    {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }

    for (int i=2; i<argc; i++)
    {
        if ( strcmp(argv[1], argv[i]) == 0 )
        {
            fprintf(stderr, "Can't copy %s to itself\n", argv[1]);
            continue;
        }
        else if ( (fs = fopen(argv[i], "r")) == NULL )
        {
            fprintf(stderr, "Can't open %s\n", argv[i]);
            continue;
        }
        else
        {
            if ( setvbuf(fs, NULL, _IOFBF, BUFSIZ) != 0 )
            {
                fputs("Can't create input buffer\n", stderr);
                continue;
            }
        }
        append(fs, fd);
        if (ferror(fs) != 0)
            fprintf(stderr, "Error in reading file %s.\n", argv[i]);
        if (ferror(fd) != 0)
            fprintf(stderr, "Error in writing file %s.\n", argv[i]);

        fclose(fs);
        files++;
        printf("File %s appended.\n", argv[i]);
        
    }

    printf("Done copying and pasting, %d files copied to %s\n", files, argv[1]);
    rewind(fd);
    printf("Now contents in %s file:\n", argv[1]);
    while ( (ch = getc(fd)) != EOF)
        putchar(ch);
    puts("Done displaying.");
    fclose(fd);

    return 0;
}

void append(FILE *source, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZ];

    while ((bytes = fread(temp, sizeof(char), BUFSIZ, source)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while ( getchar() != '\n' )
                continue;
    }

    return ret_val;
}