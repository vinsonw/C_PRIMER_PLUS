#include <stdio.h>

double power(double n, int p);

int main(void)
{
    int n[3] = {0, 2, 3};
    int p[3] = {0, -2, 3};
    int i,j;
    for (i=0; i<3; i++)
        for (j=0; j<3; j++)
            printf("%d raised to power %d equals %.2lf\n", n[i], p[j], power(n[i], p[j]));

    return 0;

}


double power(double n, int p)
{
    if (p<0)
    {
        p = -p;
        double pow=1.;
        int index;
        for (index=1; index<=p; index++)
            pow *= n;
        return 1/pow;
    }
    else if ( p==0 )
    {
        if ( n==0 )
        {
            printf("0 to power of 0 is undefined, returning 1.\n");
            return 1;
        }
        return 1;
    }
    else 
    {
        double pow=1.;
        int index;
        for (index=1; index<=p; index++)
            pow *= n;
        return pow;
    }
}