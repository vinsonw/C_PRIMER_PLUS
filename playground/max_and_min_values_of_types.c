#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("INT_MAX is %d\n", INT_MAX);
    printf("INT_MIN is %d\n", INT_MIN);
    printf("CHAR_BIT is %d\n", CHAR_BIT);
    // above proves one char type uses 8 bit
    // i.e. 1 byte equals 8 bit on this machine.

    return 0;
}

