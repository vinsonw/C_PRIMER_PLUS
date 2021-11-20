#include <stdio.h>
#include <time.h>

void usr_elapse(double);

int main(void)
{
    double delays[3] = {1, 1, 1};
    usr_elapse(1.2);
    // for (int i=0; i<3; i++)
        // usr_elapse(delays[i]);
}

void usr_elapse(double delay)
{
    clock_t t1 = clock();
    while (1)
    {
        printf("Looping |\n");
        printf("Looping /\n");
        printf("Looping --\n");
        printf("Looping \\\n");
        if ( ( (double)(clock() - t1) ) / CLOCKS_PER_SEC >= delay)
            break;
    }
}