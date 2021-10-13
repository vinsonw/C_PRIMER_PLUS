#include <stdio.h>

double avg(int l, double arr[l]);
double avg_of_all(int l, int m, double arr[l][m]);
double lgt_of_all(int, int, double arr[*][*]);


int main(void)
{
    double arr[3][5];
    printf("Please enter 3 sets of five numbers, each set lies on one line:\n");
    int i,j;
    for (i=0; i<3; i++)
        for (j=0; j<5; j++)
            scanf("%lf", &arr[i][j]);
    for (i=0; i<3; i++)
        printf("average by line: %.2lf\n", avg(5, arr[i]));
    printf("average of all %.2lf\n", avg_of_all(3, 5, arr));
    printf("largest of all %.2lf\n", lgt_of_all(3, 5, arr));

}

double avg(int l, double arr[l])
{
   double sum=0;
   int index;
   for (index=0; index<l; index++)
        sum += *(arr+index);
    return sum / l;
}

double avg_of_all(int l, int m, double arr[l][m])
{
    int i,j;
    double sum=0;
    for (i=0; i<l; i++)
        for (j=0; j<m; j++)
            sum += arr[i][j];
    return sum / l;
}

double lgt_of_all(int l, int m, double arr[l][m])
{
    int i,j;
    double max=arr[0][0];
    for (i=0; i<l; i++)
        for (j=0; j<m; j++)
                if (max < arr[i][j])
                    max = arr[i][j];
    return max;
}