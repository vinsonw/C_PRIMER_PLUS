#include <stdio.h>

int main(void)
{
    float input;
    printf("Please enter a real number(decimal number):\n") ;
    scanf("%f", &input);
    printf("Here is the required output:\n");
    printf("The input is %.1f or %.1e\n", input, input);
    printf("The input is %+.3f or %.3E\n", input, input);

    return 0;
}