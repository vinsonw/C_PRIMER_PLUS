#include <stdio.h>

int main(void)
{
    char np_0 = '\a'; // "a" stands for "alert"
    char np_1 = '\b'; // "b" stands for "backspace"

    char normal_char0  = 65;
    char normal_char1 = 0101;
    char normal_char2 = '\101'; //'\0101' won't work on gcc 10.2.1
    
    printf("test %c\n", np_0);
    printf("test backspace%c\n", np_1);
    printf("Hello!\x41 \n");

    printf("normal_char0: %c\n", normal_char0);
    printf("normal_char1: %c\n", normal_char1);
    printf("normal_char2: %c\n", normal_char2);


    return 0;
}