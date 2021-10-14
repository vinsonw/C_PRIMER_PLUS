#include <stdio.h>
#include <ctype.h>

int test_letter(char ch);

int main(void)
{
    char ch;
    while ( (ch=getchar()) != EOF )
    {
        int result;
        if ( (result=test_letter(ch)) == -1 )
            printf("'%c' is not a letter\n", ch);
        else
            printf("'%c' is letter %d\n", ch, result);

    }
}


int test_letter(char ch)
{
    if ( !(isalpha(ch)) )
        return -1;
    else
        return toupper(ch)-'A'+1;

}