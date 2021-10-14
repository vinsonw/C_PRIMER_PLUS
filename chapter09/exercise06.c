#include <stdio.h>

void ascending(double *, double *, double *);

int main(void)
{
    double m=3, n=1, o=2;
    ascending(&m, &n, &o);
    printf("now\n"
    "m=%.2lf\n"
    "n=%.2lf\n"
    "o=%.2lf\n",
    m, n, o
    );

    return 0;
}

void ascending(double *x, double *y, double *z)
{
    double arr[3] = {*x, *y, *z};
    int i, j, temp;
    for (i=0; i<3; i++)
        for (j=i+1; j<3; j++)
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
    *x = arr[0];
    *y = arr[1];
    *z = arr[2];

}