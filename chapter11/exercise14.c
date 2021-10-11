#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char * argv[])
{
    double num = atof(argv[1]);
    double num1 = atof(argv[2]);
    printf("%.2lf raised to power of %.2lf is %.2lf\n",
    num, num1, pow(num, num1)
    );
}