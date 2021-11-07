#include <stdio.h>
#include <stdlib.h>

static int mode;
static float distance;
static float fuel;

void set_mode(int _mode)
{
    extern int mode;
    mode = _mode;

}

void get_info()
{
    extern float distance;
    extern float fuel;

    if (mode == 0)
    {
        printf("Enter distancd traveled in kilometers: ");
        scanf("%f", &distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%f", &fuel);
    }
    else if (mode == 1)
    {
        printf("Enter distance traveled in miles: ");
        scanf("%f", &distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%f", &fuel);
    }
    else
    {
        printf("Invalid mode specified. Mode 1(US) used.\n");
        set_mode(1);
        get_info();
    }
}

void show_info()
{
    extern int mode;
    extern float distance, fuel;
    if (mode == 0)
       printf("Fuel consumption is %.2f liters per 100km.\n",
       fuel / (distance / 100)        
       );
    else
       printf("Fuel consumption is %.1f miles per gallon.\n",
       distance / fuel        
       );

}