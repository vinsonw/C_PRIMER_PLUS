#include <stdio.h>
#define BASE 8

void to_base_n(unsigned long, int);

int main(void)
{
    unsigned long arr[3] = {1000, 8, 65};
    int index;
    for (index=0; index<3; index++)
    {
        printf("%d converted to base %d is  ", arr[index], BASE);
        to_base_n(arr[index], BASE);
        printf("\n");
    }

    return 0;
}


void to_base_n(unsigned long num, int base)
{
    int r;
    r = num % base;
    if (num >= base)
        to_base_n(num / base, base);
    printf("%d", r);
}