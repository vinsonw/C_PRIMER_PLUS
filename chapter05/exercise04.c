#include <stdio.h>

int main(void)
{
    const float CENTIMETERS_FOR_ONE_INCH = 2.54;
    const int INCHES_FOR_ONE_FOOT = 12;
    float cm;
    float f_in;
    int i_in;
    int ft;
    printf("Enter a height in centimeters:");
    scanf("%f", &cm);

    while (cm > 0)
    {
        f_in = cm / CENTIMETERS_FOR_ONE_INCH; 
        i_in = (int) f_in;
        ft = i_in / INCHES_FOR_ONE_FOOT;
        float remainder_in = f_in - ft * INCHES_FOR_ONE_FOOT;
        printf("%.1f cm = %d feet, %.1f inches\n", cm, ft, remainder_in);
        printf("Enter a height in centimerters (<=0 to quit):");
        scanf("%f", &cm);

    }

    printf("bye\n");

    return 0;
    
}