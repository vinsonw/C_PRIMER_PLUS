/*
* Note:
* clearerr(FILE *) function in stdio.h could
* clear EOF in the standard input. 
* See line 73
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100
#define ROWS 10

/* utilities */
int read_a_line(char *, int);
char get_first_char(void);
int get_length_of_str(char *, int);
void display_2d_arr(char * arr[ROWS], int);
void copy_first_word(char *, char *, int);

/* functions */
void sort_str_in_ascii_order(char * str_arr[], int length);
void sort_str_in_order_of_increasig_length(char * str_arr[], int length);
void sort_str_in_order_of_length_of_first_word(char * str_arr[], int length);

int main(void)
{
    char str_arr[ROWS][SIZE];
    char * ptstr[ROWS];
    int index=0;
    int ch;
    printf("Please enter %d strings, each at one line:\n", ROWS);
    while ( index < ROWS)
    {
        ch=read_a_line(str_arr[index], SIZE); 
        index++;
        if ( ch == EOF )
            break;
    }


    while (1)
    {
        int cursor=0;

        // "index" below is the actual size of rows of two-dimensional arry "str_arr"
        while (cursor<index)
        {
            /* ptstr[cursor] is a variable,
            * whereas str_arr[cursor] is a constant.
            * That why we need to copy it,
            * so we could change the value of each element
            * of array "ptstr", which couldn't be done for
            * constant elements of array "str_arr"
            */
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

        /* the bug has been found!!!!
        * by searching "clear EOF in stand input" using google,
        * I found the question on stack overflow:
        * https://stackoverflow.com/questions/19744423/recover-stdin-from-eof-in-c
        * clearerr() is the way to go.
        */
        clearerr(stdin);
        
        char ch_;
        while ( (ch_=getchar()) == '\n')
            continue;
        
        printf("-------------------------------------\n");

        // printf("ch_=%c\n", ch_);
        switch (ch_)
        {
            case '1':
                display_2d_arr(ptstr, index);
                break;
            case '2':
                sort_str_in_ascii_order(ptstr, index); 
                display_2d_arr(ptstr, index);
                break;
            case '3':
                sort_str_in_order_of_increasig_length(ptstr, index); 
                display_2d_arr(ptstr, index);
                break;
            case '4':
                sort_str_in_order_of_length_of_first_word(ptstr, index); 
                display_2d_arr(ptstr, index);
                break;
            case '5':
                return 0;
            default:
                printf("choose from 1-5.\n");
                continue;
        }
    printf("-------------------------------------\n");

    }
    return 0;
}

int read_a_line(char * str, int n)
{
    int index=0;
    int ch;
    while ((ch=getchar()) != '\n' && index<n)
    {
        if (ch == EOF)
        {
            *(str+index) = '\0';
            return EOF;
        }
        *(str+index) = ch;
        index++;
    }
    if (index == n)
        str[index-1] = '\0';
    else
        str[index] = '\0';
    return 0;
}

void display_2d_arr(char * arr[ROWS], int rows)
{
        int index=0;
        for (index=0; index< rows; index++)
            puts(arr[index]);
}

char get_first_char(void)
{
    char ch;
    char test;
    while (isspace(ch=getchar()))
            ;

    //there is a bug below when you use ctrl+d
    // to input less than ROWS strings
    // getchar() would get infinite -1 (EOF)
    // from stand input, I don't know why.
    // -- Solved! Because EOF input would block
    // standard input, use clearerr() to clear it.
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

void sort_str_in_order_of_length_of_first_word(char * str_arr[], int length)
{
    char *temp;
    int index;
    int second_index;
    for (index=0; index<length; index++)
        for (second_index=index+1; second_index<length; second_index++) 
        {
            char word1[21];
            char word2[21];
            // save 1 unit for adding '\0' at the end if needed
            // prepare for strlen(), which requires '\0' at the end to measure length of string.
            copy_first_word(word1, str_arr[index], 20); 
            copy_first_word(word2, str_arr[second_index], 20);
            if ( strlen(word1) > strlen(word2) )
            {
                temp = str_arr[second_index];
                str_arr[second_index] = str_arr[index];
                str_arr[index] = temp;
            }
        }
}

void copy_first_word(char * t, char * s, int l)
{
    int index=0;
    while ( !(isspace(*(s+index))) && index<l )
    {
        *(t+index) = *(s+index);
        index++;
    }
    *(t+index) = '\0';
}

void sort_str_in_order_of_increasig_length(char * str_arr[], int length)
{
    char *temp;
    int index;
    int second_index;
    for (index=0; index<length; index++)
        for (second_index=index+1; second_index<length; second_index++) 
            if ( get_length_of_str(str_arr[index], SIZE) > get_length_of_str(str_arr[second_index], SIZE))
            {
                temp = str_arr[second_index];
                str_arr[second_index] = str_arr[index];
                str_arr[index] = temp;
            }
}

int get_length_of_str(char * s, int length)
{
    int i=0;
    while ( *s != '\0' && i<length )
    {
        s++;
        i++;
    }

    return i;
}