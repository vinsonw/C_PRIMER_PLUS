#include <stdio.h>

double Daphne(double it, int year);
double Deirdre(double it, int year);

int main(void)
{
    int index=0;
    double daphne;
    double deirdre;

    do 
    {
        index++;
        daphne = Daphne(100., index);
        deirdre = Deirdre(100., index);
    } while (deirdre <= daphne);

    printf("%d years later, Deirder's inverstment exceeds Daphne's.\n", index);
    printf("Deirdre = %.2lf, Daphne = %.2lf\n", deirdre, daphne);
    
    return 0;
}

double Daphne(double it, int year)
{
    return it*0.1*year + it;
}

double Deirdre(double it, int year)
{
    int index;
    double sum = it;

    for (index=0; index<year; index++)
        sum *= 1+0.05;
        
    return sum;
}
