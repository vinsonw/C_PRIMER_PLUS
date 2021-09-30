#include <stdio.h>

int main(void)
{
    int lower_limit, higher_limit;
    int iterator;
    printf("Enter lower and upper integer limits: ");
    scanf("%d %d", &lower_limit, &higher_limit);

    while (higher_limit > lower_limit)
    {
       int sum = 0;
       for(iterator=lower_limit; iterator<higher_limit+1; iterator++) 
            sum += iterator * iterator;
        printf("The sum of the square from %d to %d is %d\n", lower_limit * lower_limit,
        higher_limit * higher_limit, sum);
        printf("Enter lower and upper integer limits: ");
        scanf("%d %d", &lower_limit, &higher_limit);
    }
    printf("Done\n");
    

    return 0;
}