#include <stdio.h>

int main(void)
{
    // A new format for expressing floating-point constants added in C99.
    // See Vol. Page 82.
    printf("floating-point constant added in C99: %f\n", 0xa.1fp10);
    printf("floating-point constant added in C99: %e\n", 0xa.1fp10);
    printf("floating-point constant added in C99: %a\n", 0xa.1fp10);

    // Vol. Page 84
    // Floating-point round-off errors
    // Mechanism behind the error:
    // "A float number is typically just six or seven digits scaled to bigger
    // or smaller numbers with an exponent"
    float a, b;
    
    b = 2.0e20 + 1.0;
    a = b - 2.0e20;
    printf("%f \n", a);

    return 0;
}