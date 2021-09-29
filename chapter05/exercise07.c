#include <stdio.h>
double cube(double input);

int main(void)
{
    printf("Please enter a number you want to cube:");
    double input;
    scanf("%lf", &input);
    printf("okay, the cube of %.1lf is %.1lf \n", input, cube(input));

    return 0;
}

double cube(double input)
{
    return input * input * input;
}