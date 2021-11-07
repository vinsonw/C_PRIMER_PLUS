#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int main(void)
{
    int num[SIZE];
    srand((unsigned int) time(0));
    for (int i=0; i<SIZE; i++)
    {
        num[i] = rand() % 10 + 1; 
    }

    int temp;
    for (int i=0; i<SIZE; i++)
    {
        for (int j=i+1; j<SIZE; j++)
        {
            if (num[i] < num[j])
            {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp; 
            }
        }
    }

    printf("This is the series of random numbers between 1-10:\n");
    for (int i=0; i<SIZE; i++)
        printf("%d ", num[i]);

}