#include <stdio.h>
#include <math.h>

int main(void)
{
    int arr[8];
    int index;
    for (index=0; index<8; index++)
        arr[index] = pow(2, index+1);

    index = 0;
    do
    {
        printf("%d ", arr[index]);
        index++;

    } while (index < 8);
    printf("\n");

    return 0;
    
}