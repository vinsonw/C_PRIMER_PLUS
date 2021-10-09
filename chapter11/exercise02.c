#include <stdio.h>
#include <ctype.h>

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
        int cnt = 0;
        char ch;
        while (cnt < n && !(isspace(ch=getchar())))
        {
            *(spt + cnt) = ch;
            cnt++;
        }
    }
}