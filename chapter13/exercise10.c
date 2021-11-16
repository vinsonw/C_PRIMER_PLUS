#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SLEN 41

char *s_gets(char *, int);

int main(void)
{
    FILE *fp;
    char file_name[SLEN];

    puts("Enter the file name:");
    s_gets(file_name, SLEN);
    if ( (fp=fopen(file_name, "r")) == NULL )
    {
        fprintf(stderr, "Couldn't open %s\n", file_name);
        exit(EXIT_FAILURE);
    }
    puts("Enter the char number you wnat to input");
    long pos;
    if ( scanf("%ld", &pos) != 1 )
    {
        fputs("I am tired.\n", stderr);
        exit(EXIT_FAILURE);
    }
    fseek(fp, pos-1, SEEK_SET);
    char ch;
    while ( (ch=getc(fp)) != '\n' && (ch != EOF) )
        putchar(ch);
    printf("\n");
    fclose(fp);

   return 0; 
}


char *s_gets(char *s, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(s, n, stdin);
    if (ret_val)
    {
        find = strchr(s, '\n');
        if (find)
            *find = '\0';
        else
            while ( getchar() != '\n' )
                continue;
    }

    return ret_val;
}