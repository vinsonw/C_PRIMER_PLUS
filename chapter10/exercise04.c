#include <stdio.h>
int diff_of_lgt_smt(double *, int);

int main(void)
{
    double arr[5] = {3., .1, 5., 9., 2.};
    printf("the max index of arr is %d\n", diff_of_lgt_smt(arr, 5));

    return 0;
}

int diff_of_lgt_smt(double * arr, int l)
{
    int index;
    int index_max=0;
    for (index=1; index<l; index++)
        if (arr[index_max] < arr[index]) 
        {
            index_max = index;
        }
    return index_max;
}
