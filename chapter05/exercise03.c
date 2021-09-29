#include <stdio.h>

/* virtually the same as exercise 1 */
int main(void)
{
    const int NUM_OF_DAYS_OF_A_WEEK = 7;
    int days;
    printf("Please enter days you have, or enter a number <=0 tu quit.\n");
    scanf("%d", &days);
    while (days > 0)
    {
        /* code */
        printf("%d days are %d weeks, %d days.\n", days, days / NUM_OF_DAYS_OF_A_WEEK, days % NUM_OF_DAYS_OF_A_WEEK);
        printf("you could continue or quit.\n");
        scanf("%d", &days);
    }


    return 0;
    

}