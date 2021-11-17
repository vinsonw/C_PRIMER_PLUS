#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    const char SYMBOL[11] = {' ', '.', '\'', ':',  '~', '*' ,'=','@','%','#','\0'};
    char arr_2d[20][31];
    FILE *fp;

    if ( (fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Couldn't open %s\n", argv[1]);
        exit(0);
    }
    int ch;
    for (int i=0; i<20; i++)
        for (int j=0; j<31; j++)
            if ( (fscanf(fp,"%d", &ch)) == 1 ) 
                if (j==30)
                    arr_2d[i][j] = '\0';
                else
                    arr_2d[i][j] = SYMBOL[ch];

    char saved_file[40];
    strcpy(saved_file, argv[1]);
    strcat(saved_file, ".12.txt");
    FILE *fd = fopen(saved_file, "w");
    puts("alright, this is the converted image:");
    for (int i=0; i<20; i++)
    {
        puts(arr_2d[i]);
        fprintf(fd, "%s", arr_2d[i]);
        fprintf(fd,"\n");
    }

    fclose(fp);
    fclose(fd);

    return 0;
}