#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(void)
{
    FILE *fp;
    char words[MAX];

    if ( (fp = fopen("wordy", "a+")) == NULL )
    {
        fprintf(stderr, "Damn you: %s!\n", "wordy");
        exit(EXIT_FAILURE);
    }

    puts("Enter words to add to the file; press the #");
    puts("to quit.");

    while ( (fscanf(stdin, "%40s", words) == 1) && (words[0] != '#') )
        fprintf(fp, "%s\n", words);
    puts("File contents:") ;
    rewind(fp);

    int wd_cnt = 0;
    while ( fscanf(fp, "%s", words) == 1 )
    {
        printf("%d :", ++wd_cnt);
        puts(words);
    }
    puts("Done.");
    if ( fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");
    
    return 0;
}