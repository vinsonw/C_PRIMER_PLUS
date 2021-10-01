#include <stdio.h>


int main(void)
{
    double arr1[8], arr2[8];
    int index;
    double sum=0;
    printf("Give me 8 numbers, you know the drill: ");
    for(index=0; index<8; index++)
    {
        scanf("%lf", &arr1[index]);
        sum += arr1[index];
        arr2[index] = sum;
    }
    for(index=0; index<8; index++)
    {
        printf("%8.2lf", arr1[index]);
    }
    printf("\n");
    for(index=0; index<8; index++)
    {
        printf("%8.2lf", arr2[index]);
    }
    printf("\n");

    return 0;
}