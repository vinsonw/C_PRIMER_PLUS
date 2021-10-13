#include <stdio.h>
int max_int(int *, int);

int main(void)
{
    int arr[5] = {3, 1, 5, 9, 2};
    printf("the max number of arr is %d\n", max_int(arr, 5));

    return 0;
}

int max_int(int * arr, int l)
{
    int max=arr[0];
    int index;
    for (index=1; index<l; index++)
        if (max < arr[index]) 
            max = arr[index];
    return max;
}
