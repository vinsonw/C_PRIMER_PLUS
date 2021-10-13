#include <stdio.h>

void double_values(int [][5], int);
void display_values(int [][5], int);

int main(void)
{
    int arr[3][5] = {
        {1.,2.,3.,4.,5.},
        {1.,2.,3.,4.,5.},
        {1.,2.,3.,4.,5.}
    };
    display_values(arr, 3);
    double_values(arr, 3);
    display_values(arr, 3);

    return 0;
}

void double_values(int (*arr)[5], int l)
{
    int index,j;
    for (index=0; index<l; index++)
        for (j=0; j<5; j++)
            *(*(arr+index)+j) = *(*(arr+index)+j) * 2;
}

void display_values(int (*arr)[5], int l)
{

    int index,j;
    for (index=0; index<l; index++)
        for (j=0; j<5; j++)
            printf("%-4d ", *(*(arr+index)+j)); 
    printf("\n");

}