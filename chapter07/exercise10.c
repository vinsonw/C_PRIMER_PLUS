#include <stdio.h>
int main(void)
{
    char ch;
    printf("Please select the category that you're in.\n" \
    "1) Single 2) Head of household 3) Married, Joint 4) Married, Separate\n" \
    "type 'q' to quit.\n"
    );

    while (1)
    {
        ch = getchar();
        if (ch=='\n') continue;
        float threshold;
        switch (ch)
        {
        case '1':
            threshold = 17850.;
            break;
        case '2':
            threshold = 23900.;
            break;
        case '3':
            threshold = 29750.;
            break;
        case '4':
            threshold = 14875.;
            break;
        
        default:
            return 0;
        }
        double tax_income;
        printf("Please enter your taxable income: ");
        scanf("%f", &tax_income);
        if (tax_income > threshold)
            printf("okay, you need to pay tax $%.2f.\n", 0.15*threshold + 0.28*(tax_income - threshold));
        else
            printf("okay, you need to pay tax $%.2f.\n", 0.15*tax_income);


        printf("-------------one calculation completed---------------------\n");
        printf("Please select the category that you're in.\n" \
        "1) Single 2) Head of household 3) Married, Joint 4) Married, Separate\n" \
        "type 'q' to quit.\n"
        );
    }
}
