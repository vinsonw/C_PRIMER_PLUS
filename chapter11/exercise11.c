#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 40
int read_strings(char *);
void get_one_line(char *);
char get_first_char(void);
void display_str_in_ascii_order(char * str_arr[], const int length);

int main(void)
{
    char str_arr[10][SIZE];
    char * ptstr[SIZE];
    int index=0;
    int ch;
    printf("Please enter 10 strings, each at one line:\n");
    while ( (ch=read_strings(str_arr[index]) != EOF ) && index < 10 )
            index++;

    int cursor=0;
    while (cursor<index)
        ptstr[cursor] = str_arr[cursor];

    printf("alright, what do you chose?\n"
   "1) print the original list of strings\n" 
   "2) print the strings in ASCII collatiing sequence\n" 
   "3) print the strings in order of increasing length\n" 
   "4) print the strings in order of the length of the first word in the string\n" 
   "5) quit\n" 
    );

    ch = get_first_char();

    switch (ch)
    {
    case '2':
        display_str_in_ascii_order(ptstr, index); 
        break;
    
    default:
        break;
    }



    return 0;
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

void display_str_in_ascii_order(char *str_arr[], int length)
{
    char *temp;
    int index;
    int second_index;
    for (index=0; index<length; index++)
        for (second_index=index+1; second_index<index; second_index++) 
            if (strcmp(str_arr[index], str_arr[second_index]) > 0)
            {
                temp = str_arr[second_index];
                str_arr[second_index] = str_arr[index];
                str_arr[index] = temp;
            }
}