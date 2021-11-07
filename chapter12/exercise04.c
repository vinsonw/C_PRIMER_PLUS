#include <stdio.h>

int timer(void);
int main(void)
{
    int num=10;
    int records;
    for (int i=0; i<num; i++)
        records = timer();
    printf("At the end, records = %d\n", records);
}


int timer(void)
{
    static int times=0;
    times++;
    return times;   
}