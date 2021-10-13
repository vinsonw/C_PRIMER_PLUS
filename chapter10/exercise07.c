#include <stdio.h>
void copy_arr(double *, double *, int);

int main(void)
{
    double arr[2][2] = {{1,2},{1,2}}; // source
    double arr1[2][2]; // target
    int index;
    for (index=0; index<2; index++)
        copy_arr(arr1[index], arr[index], 2); // copy subarray

    int i,j;
    for (i=0; i<2; i++)
        for (j=0; j<2; j++)
            printf("%.2lf ", arr[i][j]);
    printf("\n");

    return 0;
}

/*  array-copy using array notation */
void copy_arr(double *t, double *s, int l)
{
    int index;
    for (index=0; index<l; index++)
        t[index] = s[index];
}