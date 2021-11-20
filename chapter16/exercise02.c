#include <stdio.h>
#include "ex01.h"

int main(void)
{
   int arr0[3] = {1, 2, 3} ;
   int arr1[3] = {4, 5, 6} ;
   for (int i=0; i<3; i++)
        printf("harmonic mean for %d and %d is %.2lf\n", 
        arr0[i], arr1[i], HARMONIC_MEAN(arr0[i], arr1[i]));
    
    return 0;
}