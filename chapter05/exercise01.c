#include <stdio.h>

int main(void)
{
    const int MINUTES_PER_HOUR = 60;
    printf("Please enter a period of time in minutes. Enter <=0 to quit.\n");
    int min;
    scanf("%d", &min);
    while (min > 0)
    {
        /* code */
        printf("Okay, that's %d hour(s) %d minute(s)\n", min / MINUTES_PER_HOUR, min % MINUTES_PER_HOUR);
        printf("You could continue or quit.\n");
        scanf("%d", &min);

    }

    return 0;
    
}