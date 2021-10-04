#include <stdio.h>
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
    float PAY_RATE_PER_HOUR;
    char prompt_ch;

    printf("*********************************************\n" 
    "Enter the number orresponding to the desired pay rate or action:\n" 
    "a) $8.75/hr        b) $9.33/hr\n" 
    "c) $10.00/hr       d) $11.20/hr\n" 
    "q) quit\n" 
    "*********************************************\n" 
    );


    while (1)
    {
        prompt_ch = getchar();

        if (prompt_ch=='\n') continue;
        switch (prompt_ch)
        {
            case 'a':
                PAY_RATE_PER_HOUR = 8.75;
                break;
            case 'b':
                PAY_RATE_PER_HOUR = 9.33;
                break;
            case 'c':
                PAY_RATE_PER_HOUR = 10.00;
                break;
            case 'd':
                PAY_RATE_PER_HOUR = 11.20;
                break;
            case 'q':
                return 0;
            default:
                printf("You must select one of a-q.\n");
                continue;
        }
        
        printf("Please tell your hours worked this weeek: ");
        scanf("%f", &hrs_worked);

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

        // get rid of the remainder of the last 
        // input remained in standard input. 
        while (getchar() != '\n')
            continue; 

        printf("Do you want to do it again?(y for yes, n for no).\n");
        if (getchar() == 'y')
        printf("------------------------------------------\n" \
        "Enter the number orresponding to the desired pay rate or action:\n" \
        "a) $8.75/hr        b) $9.33/hr\n" \
        "c) $10.00/hr       d) $11.20/hr\n" \
        "q) quit\n" \
        "*********************************************\n" 
        );
        else
            break;

    }

    return 0;
        

}