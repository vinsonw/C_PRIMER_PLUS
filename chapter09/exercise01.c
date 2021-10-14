#include <stdio.h>

double min(double, double);

int main(void)
{
    double num1, num2, smaller;
    printf("please enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    smaller = min(num1, num2);
    printf("okay the smaller one is %.2lf\n", smaller);
}

double min(double x, double y)
{
    return x < y? x : y;
}