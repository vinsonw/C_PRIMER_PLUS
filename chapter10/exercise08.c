#include <stdio.h>

void copy_arr(double *t, double *s, int l);
void display_array_of_double(double * arr, int l);

int main(void)
{
    double arr[7] = {1., 2., 3., 4., 5., 6., 7.};
    double arr1[3];
    copy_arr(arr1, arr, 3);
    display_array_of_double(arr1, 3);

    return 0;
}

/*  array-copy using array notation */
void copy_arr(double *t, double *s, int l)
{
    int index;
    for (index=0; index<l; index++)
        t[index] = s[index];
}

void display_array_of_double(double * arr, int l)
{
    int index;
    for (index=0; index<l; index++)
        printf("%.2lf ", arr[index]);
    printf("\n");
}