#include <stdio.h>
#include <ctype.h>

void remove_space(char *);
char get_first_char(void);

int main(void)
{
    
   while (1)  
   {
       char s[20];
       printf("Please enter a string with spaces in it.\n");\
       fgets(s, 20, stdin);
       while (getchar() != '\n')
            ;

       remove_space(s);
       puts(s);

       printf("The authoer of the book asks me to ask this question:\n"
       "Do you want to do it again?\n"
       "(type q to quit, y to continue)\n"
       );

        if (get_first_char() != 'y')
            break;


   }


    return 0;
}

void remove_space(char * s)
{
    int index=0;
    while ( *(s+index)  )
    {
        if (!isspace(s[index]))
        {
            index++;
            continue;
        }
        else 
        {
            int second_index=index;
            while (*(s+second_index))
            {
                *(s+second_index) = *(s+second_index+1);
                second_index++;
            }
        }
    }
}

char get_first_char(void)
{
    char ch;
    while (isspace(ch=getchar()))
        ;
    while (getchar() != '\n')
        ; 

    return ch;
}