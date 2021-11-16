// This emulates Listing 13.5 P590 Vol 2.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE 4096 // 2 ^ 12
#define SLEN 81

void append(FILE *source, FILE *dest);
char *s_gets(char *, int);

int main(int argc, char *argv[])
{
    FILE *fs, *fd;
    int files = 0;
    char file_dest[SLEN];
    char file_src[SLEN];
    int ch;

    printf("Please enter a file as destination file:\n");
    s_gets(file_dest, SLEN);
    

    if ( (fd = fopen(file_dest, "a+")) == NULL )
    {
        fprintf(stderr, "Can't open %s\n", argv[1]);
    }

    if ( setvbuf(fd, NULL, _IOFBF, BUFSIZE) != 0 )
    {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }

    puts("Enter name of first source file (empty line to quit):");
    while ( s_gets(file_src, SLEN) && file_src[0] != '\0' )
    {
        if ( strcmp(file_dest, file_src) == 0 )
        {
            fprintf(stderr, "Can't copy %s to itself\n", file_src);
            continue;
        }
        else if ( (fs = fopen(file_src, "r")) == NULL )
        {
            fprintf(stderr, "Can't open %s\n", file_src);
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
            fprintf(stderr, "Error in reading file %s.\n", file_src);
        if (ferror(fd) != 0)
            fprintf(stderr, "Error in writing file %s.\n", file_src);

        fclose(fs);
        files++;
        printf("File %s appended.\n", file_src);
        puts("You many continue to input another file:");
        
    }

    printf("Done copying and pasting, %d files copied to %s\n", files, file_dest);
    rewind(fd);
    printf("Now contents in %s file:\n", file_dest);
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
    {
        for (int i=0; i<BUFSIZ; i++)
            if (islower(temp[i]))
                temp[i] = toupper(temp[i]);

        fwrite(temp, sizeof(char), bytes, dest);
    }
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