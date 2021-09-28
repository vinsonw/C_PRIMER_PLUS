#include <stdio.h>
#define ONE_GALLON_TO_LITTERS 3.785
#define ONE_MILE_TO_KILOMETERS 1.609

int main(void)
{
    printf("Please enter the number of miles traveled:\n");
    float miles;
    scanf("%f", &miles);
    printf("Please enter the number of gallons of gasoline consumed:\n");
    float gallons;
    scanf("%f", &gallons);
    printf("okay, miles per gallon is: %.1f\n", miles / gallons);
    printf("And in Europe (or China), that's about %.1f \
liters per 100 km.\n", gallons * ONE_GALLON_TO_LITTERS /
                       (miles * ONE_MILE_TO_KILOMETERS / 100)
    );

    return 0;
    

}
