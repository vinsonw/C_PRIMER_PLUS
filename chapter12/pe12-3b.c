#include <stdio.h>
#include "pe12-3a.h"
int main(void)
{
    int mode;
    float distance, fuel;

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        distance = get_distance_info(mode);
        printf("distance=%.2f\n", distance);
        fuel = get_fuel_info(mode);
        printf("fuel=%.2f\n", fuel);
        show_info(distance, fuel, mode);
        printf("Enter 0 for metric mode, 1 for US mode");
        printf("(-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}