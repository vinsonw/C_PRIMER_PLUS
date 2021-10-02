#include <stdio.h>

int main(void)
{
   char ch;
   int cnt=0;
   while ((ch = getchar()) != '@') 
   {
       if (ch == '|')
            continue; // after "continue", program flow goes to test contidition part.
       cnt++;
       putchar(ch);

   }

   printf("\n%d characters\n", cnt);

   cnt = 0;
   for (ch=getchar(); ch != '@'; ch=getchar(),cnt++) // ch here will read the last input '\n' remained in stand input.
    {
        if (ch == '|' || ch == '\n') // don't dispaly the '\n' from last input.
            continue; //after 'continue', program flow goes to update part: cnt++
        putchar(ch);
    }
   printf("\n%d characters\n", cnt-1);

   return 0;
}
