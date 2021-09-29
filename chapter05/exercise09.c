#include <stdio.h>
void Temperature(double F);

int main(void)
{
    double F;
    printf("Now you could enter the temperature in Fahrenhat: ");
    int scanf_outcome;
    scanf_outcome = scanf("%lf", &F); // "%lf" stand for double type, see Vol1. Page 130
    while (scanf_outcome == 1)
    {
        Temperature(F);
        printf("you could continue to enter a number that represents a temperature in Fahrenhat or \
enter 'q' or other nonnumeric value to quit: ");
        scanf_outcome = scanf("%lf", &F);
    }

    printf("bye\n");
    

    return 0;

}

void Temperature(double F)
{
    const float INCREMENT_FROM_CELSIUS_TO_KELVIN = 273.16;
    const float FAHRENHAT_TO_CELSIUS_SCALE = 5.0 / 9.0;
    const float FAHRENHAT_TO_CELSIUS_SHIFT = 32.0;

    double C, K;
    C = FAHRENHAT_TO_CELSIUS_SCALE * (F - FAHRENHAT_TO_CELSIUS_SHIFT);
    K = C + INCREMENT_FROM_CELSIUS_TO_KELVIN;

    printf("%.2lf F is respectively %.2lf C and %.2lf K \n", F, C, K);

    
}
