/*
* calculate the arithmetic mean(the average)
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    
    FILE *input;
    if (argc == 1)
    {
        input = stdin;
        printf("Please enter a series of numbers:\n");
    }
    else
    {
        input = fopen(argv[1], "r");
        printf("Reading from %s:\n", argv[1]);
    }

    int num_cnt=0;
    double ttl=0.;

    double temp;
    while ( fscanf(input,"%lf", &temp) == 1 ) 
    // fscanf() return EOF(-1) at the end of file or at manual EOF signal
    // somehow newline in comand-line doesn't trigger EOF only Ctrl+D does
    {
        ttl += temp;
        ++num_cnt;
    } 
    printf("The mean is: %.2f\n", ttl / (double) num_cnt);
     
    return 0; 
}