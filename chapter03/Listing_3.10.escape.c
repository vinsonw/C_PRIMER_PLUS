// escape.c -- uses escape characters

#include <stdio.h>

int main(void)
{
    float salary;

    printf("\aEner your desired monthly salary:");
    printf(" $_______\b\b\b\b\b\b\b");
    scanf("%f", &salary);
    printf("\n\t$%.2f a month is $%.2f a year.", salary,
    salary * 12.0);
    printf("\rGee!\n");

    return 0;
}