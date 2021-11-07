#include <stdio.h>

void critic(int *);

int main(void)
{
    int units;
    printf("How many pounds to a frikin of butter?\n");
    scanf("%d", &units);
    while ( units != 56 )
        critic(&units);
    printf("You must have cheated\n");

    return 0;
}

void critic(int * p)
{
    printf("No luck, my friend. Try again.\n");
    scanf("%d", p);
}