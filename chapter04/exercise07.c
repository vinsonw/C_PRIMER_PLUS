#include <stdio.h>
#include <float.h>

int main(void)
{
    float f1 = 1.0/3.0;
    double f2 = 1.0/3.0;

    printf("Here comes the float type being printed 3 times:\n");
    printf("%.4f %.12f %.16f\n", f1, f1, f1);
    printf("Here comes the double type being printed 3 times:\n");
    printf("%.4f %.12f %.16f\n", f2, f2, f2);

    printf("Also, this is some info coming from float.h\n");
    printf("FLT_DIG = %d\n", FLT_DIG);
    printf("DBL_DIG = %d\n", DBL_DIG);

    return 0;

}