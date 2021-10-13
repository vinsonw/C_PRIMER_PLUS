#include <stdio.h>

void copy_arry(int, int, double arr1[*][*],double arr0[*][*]);
void display_arr(int, int, double arr[*][*]);

int main(void)
{
   double arr0[3][5] = {
       {1.,2.,3.,4.,5.},
       {1.,2.,3.,4.,5.},
       {1.,2.,3.,4.,5.}
   };
   double arr1[3][5];
   copy_arry(3, 5, arr1, arr0);
   display_arr(3, 5, arr0);
   display_arr(3, 5, arr1);
}

void copy_arry(int n, int m, double arr1[n][m], double arr0[n][m])
{
    int i,j;
    for (i=0; i<n; i++)
        for (j=0; j<m; j++)
            arr1[i][j] = arr0[i][j];
}

void display_arr(int n, int m, double arr[n][m])
{
    int i,j;
    for (i=0; i<n; i++)
        for (j=0; j<m; j++)
            printf("%4.1lf", arr[i][j]);
    printf("\n");
}
