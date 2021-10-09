#include <stdio.h>
void show_array(const double [], int);
void multi_array(double [], int, double);


int main(void)
{
    double rates[5] = {88.99, 100.12, 59.45, 183.11, 340.5};
    const double locked[4] = {0.08, 0.075, 0.0725, 0.07};
    const double * p1 = rates;
    // this generates a warning, 
    // cuz "locked" is of pointer-to-const-double, 
    // "p2" is of pointer-to-double
    double * p2 = locked;
    
    show_array(p1, 5);
    show_array(p2, 4);

    multi_array(rates, 5, 1.2);
    // this generates a warning same as before
    multi_array(locked, 4, 1.2); 

    show_array(p1, 5);
    show_array(p2, 4);

    return 0;
}

void show_array(const double arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%8.3f ", arr[i]);
    printf("\n");
}

void multi_array(double arr[], int n, double mult)
{
    int i;
    for (i = 0; i < n; i++)
        arr[i] *= mult;
}