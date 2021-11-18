#include <stdio.h>
#include <math.h>

void transform(double *, double *, int, double (*)(double));
double user_plus100(double);
double user_double(double);

int main(void)
{
    double source[100];
    double target[100];
    for (int i=0; i<100; i++)
        source[i] = (double) i;

    printf("pass user_plus100():\n");
    transform(source, target, 100, user_plus100);
    for (int i=0; i<100; i++)
        printf("%.0lf ", *(target+i));
    getchar();

    printf("pass user_double():\n");
    transform(source, target, 100, user_double);
    for (int i=0; i<100; i++)
        printf("%.0lf ", *(target+i));
    getchar();

    printf("pass sin():\n");
    transform(source, target, 100, sin);
    for (int i=0; i<100; i++)
        printf("%.2lf ", *(target+i));
    getchar();

    printf("pass cos():\n");
    transform(source, target, 100, cos);
    for (int i=0; i<100; i++)
        printf("%.2lf ", *(target+i));

}

void transform(double * ps, double * pt, int size, double (*pf)(double))
{
    for (int i=0; i<size; i++)
        *(pt+i) = (*pf) ( *(ps+i) );
}

double user_plus100(double a)
{
    return a+100.0;
}

double user_double(double a)
{
    return a*2;
}