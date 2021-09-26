#include <stdio.h>

int main(void)
{
    float origin = 64.25f;
    printf("Enter a floating-point value: %.2f\n", origin);
    printf("Enter a floating-point value: %.6f\n", origin);
    printf("Enter a floating-point value: %.6e\n", origin);
    printf("Enter a floating-point value: %a\n", origin);

    return 0;

}