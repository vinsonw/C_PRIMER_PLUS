#include <stdio.h>

int main(void)
{
    float f1, f2;
    printf("Please enter two numbers to start calculation(or type q to quit): ");
    while (2 == scanf("%f %f", &f1, &f2))
    {
        printf("%.2f\n", (f1 - f2) / (f1 * f2));
        printf("you could continue or type q to quit: ");
    }
    printf("okay, you're out.\n");

    return 0;
    
}