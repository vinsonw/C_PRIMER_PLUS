#include <stdio.h>
double diff_of_lgt_smt(double *, int);

int main(void)
{
    double arr[5] = {3., .1, 5., 9., 2.};
    printf("the difference between largest and smallest value is %.2lf\n", diff_of_lgt_smt(arr, 5));

    return 0;
}

double diff_of_lgt_smt(double * arr, int l)
{
    int index;
    int index_max=0;
    int index_min=0;
    for (index=1; index<l; index++)
        if (arr[index_max] < arr[index]) 
            index_max = index;
        else
            index_min = index;
    return arr[index_max] - arr[index_min];
}
