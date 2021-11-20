// memory allocated by malloc() is not freed when you return from the function
// in which the malloc was called.
// See: https://stackoverflow.com/questions/3629082/scope-of-malloc-used-in-a-function
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
void show_array(const double ar[], int n);
double *new_d_array(int n, ...);

int main(void)
{
    double * p1;
    double * p2;

    p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);

    show_array(p1, 5);
    show_array(p2, 4);

    free(p1);
    free(p2);
}

// I don't know why, but using "..." in C seems cool.
double *new_d_array(int n, ...)
{
    va_list ap;
    va_start(ap, n);
    double * pd = (double *) malloc(n * sizeof(double));
    for (int i=0; i<n; i++)
        *(pd+i) = va_arg(ap, double);

    return pd;
}

void show_array(const double ar[], int n)
{
    for (int i=0; i<n; i++)
        printf("%.2lf ", ar[i]);
    putchar('\n');
}