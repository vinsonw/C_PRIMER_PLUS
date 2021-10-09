#include <stdio.h>
#define SIZE 40
void fetch_next_n_chars(int n, char * spt, int size);
int main(void)
{
   char spt[SIZE];
   fetch_next_n_chars(SIZE-1, spt, SIZE);
   puts(spt);

   return 0;
}


void fetch_next_n_chars(int n, char * spt, int size)
{
    if (n >= size)
        printf("You can only fetch at most %d characters.\n", size-1);
    else
    {
        /*2nd argument "n" here stands for index, not order*/
        /*fgets() automatically add '\0' at the end of string.*/
        fgets(spt, n+1, stdin);
    }
}