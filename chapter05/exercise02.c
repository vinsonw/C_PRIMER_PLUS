#include <stdio.h>

int main(void)
{
    printf("If you give an integer, I will give you back four more.\n");
    int input;
    scanf("%d", &input);
    int input_plus_5;
    input_plus_5 = input + 5;
    while (input <= input_plus_5)
    {
        printf("%d ", input);
        input++;

    }
    printf("\n");

    return 0;
}