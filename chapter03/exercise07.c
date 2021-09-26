#include <stdio.h>

int main(void)
{
    float centimenters;
    printf("How tall are you(in centimerters)?\n");
    scanf("%f", &centimenters);
    printf("Okay, that about %.0f inches.\n", centimenters / 2.54);

    return 0;
}