#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void run_stat(void);

#define SIZE 1000

int main(void)
{
    srand((unsigned int) time(0));
    for (int i=0; i<10; i++)
        run_stat();

    return 0;

}

void run_stat(void)
{
    int stat[10] = {0};
    int temp;
    for (int i=0; i<SIZE; i++)
    {
        temp = rand() % 10 + 1; 
        switch (temp)
        {
            case 1:
                ++stat[0];
                break;
            case 2:
                ++stat[1];
                break;
            case 3:
                ++stat[2];
                break;
            case 4:
                ++stat[3];
                break;
            case 5:
                ++stat[4];
                break;
            case 6:
                ++stat[5];
                break;
            case 7:
                ++stat[6];
                break;
            case 8:
                ++stat[7];
                break;
            case 9:
                ++stat[8];
                break;
            case 10:
                ++stat[9];
                break;
        
            default:
                break;
        }
    }


    printf("Here is the stats for %d random numbers in the range 1-10.\n", SIZE);
    for (int i=0; i<10; i++)
        printf("%d : %d\n", i+1, stat[i]);

}