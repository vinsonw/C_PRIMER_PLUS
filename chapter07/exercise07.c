#include <stdio.h>
#define PAY_RATE_PER_HOUR 10
#define OVERTIME_PAY_RATE_PER_HOUR PAY_RATE_PER_HOUR*1.5 
#define TAX_LEVEL0 300
#define TAX_LEVEL1 300+150
#define TAX_RATE0 0.15
#define TAX_RATE1 0.20
#define TAX_RATE2 0.25
#define TAX_BASE0 TAX_LEVEL0*0.15
#define TAX_BASE1 TAX_BASE0+150*0.15
#define OVERTIME_HRS 40

int main(void)
{
    float hrs_worked;
    double gross_pay;
    double tax;
    double net_pay;

    printf("Please tell your hours worked this weeek(type 'q' to quit): ");
    while (scanf("%f", &hrs_worked) == 1)
    {
        if (hrs_worked > OVERTIME_HRS)
            gross_pay = OVERTIME_HRS * PAY_RATE_PER_HOUR + (hrs_worked - OVERTIME_HRS) * PAY_RATE_PER_HOUR * 1.5;
        else
            gross_pay = hrs_worked * PAY_RATE_PER_HOUR;
        
        if (gross_pay<=TAX_LEVEL0)
            tax = gross_pay*TAX_RATE0;
        else if (gross_pay<=TAX_LEVEL1)
            tax = TAX_BASE0 + (gross_pay-TAX_BASE0) * TAX_RATE1;
        else
            tax = TAX_BASE1 + (gross_pay-TAX_BASE1) * TAX_RATE2;

        net_pay = gross_pay - tax;

        printf("Okay, for %.2f hours of work, you get gross pay $%.2f, ", hrs_worked, gross_pay);
        printf("tax $%.2f, and net pay $%.2f\n", tax, net_pay);
        printf("Please tell your hours worked this weeek(type 'q' to quit): ");
    }

    return 0;
    

}