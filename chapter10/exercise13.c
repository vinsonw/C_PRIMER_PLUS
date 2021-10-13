#include <stdio.h>

double avg(double *, int l);
double avg_of_all(double [][5], int);
double lgt_of_all(double [][5], int);


int main(void)
{
    double arr[3][5];
    printf("Please enter 3 sets of five numbers, each set lies on one line:\n");
    int i,j;
    for (i=0; i<3; i++)
        for (j=0; j<5; j++)
            scanf("%lf", &arr[i][j]);
    for (i=0; i<3; i++)
        printf("average by line: %.2lf\n", avg(arr[i], 5));
    printf("average of all %.2lf\n", avg_of_all(arr, 3));
    printf("largest of all %.2lf\n", lgt_of_all(arr, 3));

}

double avg(double *arr, int l)
{
   double sum=0;
   int index;
   for (index=0; index<l; index++)
        sum += *(arr+index);
    return sum / l;
}

double avg_of_all(double arr[][5], int l)
{
    int i,j;
    double sum=0;
    for (i=0; i<l; i++)
        for (j=0; j<5; j++)
            sum += arr[i][j];
    return sum / l;
}

double lgt_of_all(double arr[][5], int l)
{
    int i,j;
    double max=arr[0][0];
    for (i=0; i<l; i++)
        for (j=0; j<5; j++)
                if (max < arr[i][j])
                    max = arr[i][j];
    return max;
}