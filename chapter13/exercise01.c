#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLEN 40

char * s_gets(char *st, int n);

int main(void)
{
    int ch;
    char filename[SLEN];
    FILE *fp;
    unsigned long count = 0;
    printf("Please enter the file name you want to count chars of:\n");
    s_gets(filename, SLEN);
    if ( (fp = fopen(filename, "r")) == NULL )
    {
        printf("Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while ( (ch = getc(fp)) != EOF )
    {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters\n", filename, count);
    
    return 0;

}

char * s_gets(char * st, int N)
{
    char * res;
    char * find;
    res = fgets(st, N, stdin); // if all goes well, res == st
    if (res)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while ( getchar() != '\n')
                continue;
    }
}