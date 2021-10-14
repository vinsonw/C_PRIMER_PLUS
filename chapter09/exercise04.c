#include <stdio.h>
double harmonic_mean(double, double);


int main(void)
{
    printf("Please enter two number to calculate the harmonic mean of them: \n");
    double n1, n2;
    scanf("%lf %lf", &n1, &n2);
    printf("harmonic mean is %.2lf\n", harmonic_mean(n1, n2));

    return 0;
}


double harmonic_mean(double n1, double n2)
{
    return 1.0 / (
        (1./n1 + 1./n2) / 2
    );
}