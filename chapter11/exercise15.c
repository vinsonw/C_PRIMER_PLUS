/*inplement atoi() in stdlib.h*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int my_atoi(char *);
int sg_char_to_dig(char ch);

int main(void)
{
    char s[20];
    printf("give a number you know the drill:");
    scanf("%s", s);
    printf("that's %d\n", my_atoi(s));
}

int my_atoi(char * s)
{
    int length = strlen(s);
    int index;
    int sum=0;
    for (index=0; index<length; index++)
        if (isdigit(s[index]))
            sum += sg_char_to_dig(s[index]) * pow(10, length-index-1);
        else
            return 0;
    return sum;
}

int sg_char_to_dig(char ch)
{
    if (ch == '0')
        return 0;
    else if (ch == '1')
        return 1;
    else if (ch == '2')
        return 2;
    else if (ch == '3')
        return 3; 
    else if (ch == '4')
        return 4;
    else if (ch == '5')
        return 5;
    else if (ch == '6')
        return 6;
    else if (ch == '7')
        return 7;
    else if (ch == '8')
        return 8;
    else
        return 9;
}