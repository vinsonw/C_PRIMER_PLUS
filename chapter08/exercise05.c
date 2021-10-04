#include <stdio.h>
#include <ctype.h>

char get_first_char(void);

int main(void)
{
    int guess = 50;
    char h_or_l; 
    int low = 0, high = 100;
    char ch;
    printf("Choose a number between 1 and 100. I will try to guess\n");

    printf("okay, have you chosen your number?"
    "\nlet's get started.\n"
    "You could respond with y(es), n(o), h(igh) or l(low).\n"
    );

    printf("Is your number %d ?\n", guess);

    while ((ch=get_first_char()) != 'y')
    {

        if (ch=='n') 
        { 
            printf("okay, is the guess too low or too high?\n");

            while ((h_or_l = get_first_char()) != 'h' && h_or_l != 'l')
            {
                printf("sorry, please select from h/l\n");
                continue;
            }

            
            if (h_or_l == 'h') 
                high = guess;
            else 
                low = guess;

            guess = (low + high) / 2;
            printf("okay, let me try again. Is it %d ?\n", guess);
        }
        else
        {
            printf("sorry, please select from y/n\n");
            // cuz the user messed up, still replay the
            // last guess, putting the game back on track.
            printf("so is the guess %d?\n", guess);
            continue;
        }
    }
    printf("I know i could do it.\n");

    return 0;
}

char get_first_char(void)
{
    char ch;
    while (isspace((ch=getchar())))
        ; 
    while (getchar() != '\n')
        ; 

    return ch;
}