#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("How many words do you wish to enter? ");
    int wd_count;
    while ( scanf("%d", &wd_count) < 1 )
    {
        printf("Get your shit together!\n");
    }
    printf("Enter %d words now:\n", wd_count);
    char ** arr = (char **) malloc(wd_count * sizeof(char *));
    for (int i=0; i<wd_count; i++)
    {
        char * temp_s = (char *) malloc(1000); // every word has a maximum of 1000 bytes to store.
        scanf("%s", temp_s); // hopefully, this will add '\0' at the end. -- Yes, it did!
        *(arr+i) = temp_s; // copy the address of first byte of allocated space, so it won't get lost. 
    }

    for (int i=0; i<wd_count; i++)
    {
        puts(*(arr+i));
    }
}