#include <stdio.h>

int main(void)
{
    double it = 1000000.;
    int index=0;
    do
    {
        index++;
        it *= 1+.08; 
        it -= 100000.;
    } while (it > 0);

    printf("Okay, after %d years, it's empty\n", index);

    return 0;
    
}