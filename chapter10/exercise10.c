#include <stdio.h>

void sum_two_into_one(int *, int *, int *, int);

int main(void)
{
    int arr0[4] = {2, 3, 5, 8};
    int arr1[4] = {1, 0, 4, 6};
    int arr2[4]; 
    sum_two_into_one(arr0, arr1, arr2, 4);
    int index;
    for (index=0; index<4; index++)
        printf("%d ", arr2[index]);
    printf("\n");

    return 0;
}

void sum_two_into_one(int * arr0, int * arr1, int * arr2, int l)
{
    int index;
    for (index=0; index<l; index++)
        arr2[index] = arr1[index] + arr0[index];
}