#include <stdio.h>

void larger_of(int, int);

int main(void)
{
    larger_of(2, 6);
    
    return 0;
}

void larger_of(int x, int y)
{
    int max = x > y? x: y;
    x = max;
    y = max;
    printf("now x = %d\n", x);
    printf("now y = %d\n", y);
}
