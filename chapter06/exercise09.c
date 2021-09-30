#include <stdio.h>
float user_defined_calculation(float f1, float f2);

int main(void)
{
    float f1, f2;
    printf("Please enter two numbers to start calculation(or type q to quit): ");
    while (2 == scanf("%f %f", &f1, &f2))
    {
        printf("%.2f\n", user_defined_calculation(f1, f2));
        printf("you could continue or type q to quit: ");
    }
    printf("okay, you're out.\n");

    return 0;
    
}

float user_defined_calculation(float f1, float f2)
{
    return (f1 - f2) / (f1 * f2);
}