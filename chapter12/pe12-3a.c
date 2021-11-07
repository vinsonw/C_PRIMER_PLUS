#include <stdio.h>
#include <stdlib.h>


float get_distance_info(int mode)
{

    float distance;
    if (mode == 0)
    {
        printf("Enter distancd traveled in kilometers: ");
        scanf("%f", &distance);
    }
    else if (mode == 1)
    {
        printf("Enter distance traveled in miles: ");
        scanf("%f", &distance);
    }
    else
    {
        printf("Invalid mode specified. Mode 1(US) used.\n");
        distance = get_distance_info(1); // this assignment form is the key to recursion.
    }

    return distance;
}

float get_fuel_info(int mode)
{
    float fuel;
    if (mode == 0)
    {
        printf("Enter fuel consumed in liters: ");
        scanf("%f", &fuel);
    }
    else if (mode == 1)
    {
        printf("Enter fuel consumed in gallons: ");
        scanf("%f", &fuel);
    }
    else
    {
        printf("Invalid mode specified. Mode 1(US) used.\n");
        fuel =  get_fuel_info(1);
    }

    return fuel;
}

void show_info(float distance, float fuel, int mode)
{
    if (mode == 0)
       printf("Fuel consumption is %.2f liters per 100km.\n",
       fuel / (distance / 100)        
       );
    else
       printf("Fuel consumption is %.1f miles per gallon.\n",
       distance / fuel        
       );

}