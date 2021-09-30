#include <stdio.h>
float sign(int n);

int main(void)
{
    int terms;
    printf("How many terms do you want to test: ");
    scanf("%d", &terms);
    long double sum1 = 0.0, sum2 = 0.0;
    int term_index;

    for (term_index=0; term_index<terms; term_index++)
    {
        // to print "long double" you have to use "%Lf", nothing else will work.
        printf("1.0+1.0/2.0+1.0/3.0+...+1.0/%d.0: %Lf\n", term_index+1, sum1 += 1.0 / (term_index+1));
        printf("1.0-1.0/2.0+1.0/3.0+...+1.0/%d.0: %Lf\n", term_index+1, sum2 += sign(term_index) / (term_index+1));
    }
}


float sign(int n)
{
    if (n % 2)
        return -1.0;
    return 1.0;
}