#include <stdio.h>

int main(void)
{
    // const int i;
    // i = 1;
    // above won't work.
    const int i = 1;
    printf("i = %d\n", i);

    // const int arr[8];
    // arr[1] = 1;
    // above won't work.
    const int arr[8] = {1,2,3,4,5,6,7,8};
    printf("arr[1]=%d\n", arr[1]);

    return 0;
}