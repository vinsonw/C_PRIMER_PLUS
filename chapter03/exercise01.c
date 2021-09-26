// Find out what your system does with integer overflow, floating-point overflow,
// and floating-point underflow
#include <stdio.h>

int main(void)
{
    int i_toobit =  2147483647; // 2^31 - 1
    printf("%d\n", i_toobit);
    // this causes integer overflows and goes back to the smallest value -2^31
    i_toobit++;
    printf("%d\n", i_toobit);

    // toobig is to be set "inf"
    float toobig = 3.4E38 * 100.0f;
    printf("%e\n", toobig);

    float toosmall = 0.000003e-10;
    printf("%f\n", toosmall / 2.0);

    return 0;
}