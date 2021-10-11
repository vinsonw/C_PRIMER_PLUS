#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 40
int read_a_line(char *, int);
void get_one_line(char *);
char get_first_char(void);
void sort_str_in_ascii_order(char * str_arr[], int length);

int main(void)
{
    char str_arr[10][SIZE];
    char * ptstr[10];
    int index=0;
    int ch;
    printf("Please enter 10 strings, each at one line:\n");
    while ( index < 10  &&
        (ch=read_a_line(str_arr[index], SIZE)) != 1 )
            index++;
    
    // while (getchar() != '\n')
        // ;
    int cursor=0;
    while (cursor<index)
    {
        ptstr[cursor] = str_arr[cursor];
        cursor++;
    }

    printf("alright, what do you chose?\n"
   "1) print the original list of strings\n" 
   "2) print the strings in ASCII collatiing sequence\n" 
   "3) print the strings in order of increasing length\n" 
   "4) print the strings in order of the length of the first word in the string\n" 
   "5) quit\n" 
    );

    
    char ch_;

    // ch_ = get_first_char();
    ch_ = getchar();
    printf("ch_=%c\n", ch_);
    switch (ch_)
    {
    case '2':
        sort_str_in_ascii_order(ptstr, index); 
        int index=0;
        for (index=0; index< 10; index++)
            puts(ptstr[index]);
        break;
    
    default:
        break;
    }



    return 0;
}

int read_a_line(char * str, int n)
{
    // int index=0;
    // int ch;
    // while ((ch=getchar()) != '\n' && index<n)
    // {
    //     if (ch == EOF)
    //         return 1;
    //     *(str+index) = ch;
    //     index++;
    // }
    // if (index == n)
    //     str[index-1] = '\0';
    // else
    //     str[index] = '\0';
    // return 0;
    
    // char * p;
    // p = fgets(str, n, stdin);
    // if (p == NULL)
    //     return 1;
    // int index=0;
    // while (*(str+index) != '\n' && index < n)
    //     index++;
    // if (*(str+index) == '\n')
    //     *(str+index) = '\0';
    // return 0;

    int index=0;
    int ch;
    while ((ch=getchar()) != '\n' && ch != EOF && index<n)
    {
        *(str+index) = ch;
        index++;
    }
    if (index == n)
        str[index-1] = '\0';
    else
        str[index] = '\0';
    return 0;
}

char get_first_char(void)
{
    char ch;
    char test;
    while (isspace(ch=getchar()))
            ;

    //there is a bug below when you use ctrl+d
    // to input less than 10 strings
    // getchar() would get infinite -1 (EOF)
    // from stand input, I don't know why.
    while ((ch = getchar()) != '\n')
        ;  

    return ch;
}

void sort_str_in_ascii_order(char *str_arr[], int length)
{
    char *temp;
    int index;
    int second_index;
    for (index=0; index<length; index++)
        for (second_index=index+1; second_index<length; second_index++) 
            if (strcmp(str_arr[index], str_arr[second_index]) > 0)
            {
                temp = str_arr[second_index];
                str_arr[second_index] = str_arr[index];
                str_arr[index] = temp;
            }
}