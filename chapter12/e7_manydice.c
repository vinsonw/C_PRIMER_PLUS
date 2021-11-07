#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "e7_diceroll.h"

int main(void)
{
    int dice, roll;
    int sides;
    srand((unsigned int) time(0));

    printf("How many sides and how many dice? ");
    while ( scanf("%d %d", &sides, &dice) != 2 || sides<0 || dice<0 )
    {
        printf("Get your shit right! Do it again: ");
        scanf("%d %d", &sides, &dice);
    }
    printf("Here are %d sets of %d %d-sided throws.\n", sides*dice, dice, sides);
    for (int i =0; i<dice*sides; i++)
    {
        printf("%d ",roll_n_dice(dice, sides));
    }

    return 0;
}