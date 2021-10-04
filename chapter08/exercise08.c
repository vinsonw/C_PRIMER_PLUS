#include <stdio.h>
#include <ctype.h>
char get_first_char(void);

int main(void)
{
    char op;
    float opd1, opd2, outcome;

    while (1)
    {
    
        printf("Chose your arithmatic operation:\n"
        "a for add\n"    
        "s for subtraction\n"
        "m for multiplication\n"
        "d for divison\n"
        "q to quit.\n"
        );

        op = get_first_char();
        if (op != 'a' && 
            op != 's' &&
            op != 'm' &&
            op != 'd' &&
            op != 'q' 
            )
        {
            printf("Oh! Please select from a/s/m/d/q.\n");
            continue;
        }

        if (op == 'q') 
            break;
        printf("Please input the 1st number you want to operate on\n");
        while (scanf("%f", &opd1) != 1)
        {
            char ch;
            while ((ch=getchar()) != '\n')
                putchar(ch);
            printf(" is not a number\n");
        }       
        printf("Please input the 2nd number you want to operate on\n");
        while (scanf("%f", &opd2) != 1)
        {
            char ch;
            while ((ch=getchar()) != '\n')
                putchar(ch);
            printf(" is not a number\n");
        }       
        while (opd2 == 0)
        {
            printf("Enter a number other than 0: ");
            scanf("%f", &opd2);
        }
            

        switch (op)
        {
            case 'a':
                outcome = opd1 + opd2; 
                op = '+';
                break;
            case 's':
                outcome = opd1 - opd2; 
                op = '-';
                break;
            case 'm':
                outcome = opd1 * opd2; 
                op = '*';
                break;
            case 'd':
                outcome = opd1 / opd2; 
                op = '/';
                break;
        }

        printf("\n%.2f %c %.2f = %.2f\n", opd1, op, opd2, outcome);

        printf("Do you want to do it again?(y for yes, n for no)\n");
        if (get_first_char() != 'y')
            break;

    }

    printf("Peace out.\n");
}

char get_first_char(void)
{
    char ch;
    while (isspace(ch=getchar()))
        ;
    while (getchar() != '\n')
        ; 

    return ch;
}