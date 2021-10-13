#include <stdio.h>
void reverse_array_of_double(double *, int);
void display_array_of_double(double *, int);

int main(void)
{
    double arr[5] = {1., 2., 3., 4., 5.};
    display_array_of_double(arr, 5);
    reverse_array_of_double(arr, 5);
    display_array_of_double(arr, 5);

    return 0;
    
}

void reverse_array_of_double(double * arr, int l)
{
    int index;
    int temp;
    for (index=0; 2*index<l; index++)
    {
        temp = arr[index];
        arr[index] = arr[l-1-index];
        arr[l-1-index] = temp;
    }
}

void display_array_of_double(double * arr, int l)
{
    int index;
    for (index=0; index<l; index++)
        printf("%.2lf ", arr[index]);
    printf("\n");
}