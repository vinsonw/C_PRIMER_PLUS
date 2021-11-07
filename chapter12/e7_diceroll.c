/* diceroll.c -- dice role simulation */
/* compile with mandydice.c */
#include "e7_diceroll.h"
#include <stdio.h>
#include <stdlib.h>

int roll_count = 0;

static int rollem(int sides) // roll one single die with "sides" sides
{
    int roll;

    roll = rand() % sides + 1;
    ++roll_count;
    
    return roll;
}

int roll_n_dice(int dice, int sides)
{
    int d;
    int total = 0;
    if (sides < 2)
    {
        printf("Need at least 2 sides.\n");
        return -2;
    }
    if (dice < 1)
    {
        printf("need at tleast 1 die.\n");
        return -1;
    }

    for (d=0; d<dice; d++) // roll mutiple dice.
        total += rollem(sides);

    return total;
}