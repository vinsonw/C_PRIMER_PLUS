#include <stdio.h>
#define LOWER 10
#define UPPER 20

int valid_input(int lower, int upper);
void display_menu(void);
int main(void)
{
   while (1) 
   {
        int input;
        display_menu();
        input = valid_input(LOWER, UPPER);
        if (input == 4)
            break;
        if (input == 0)
            continue;
        printf("You have just input %d\n", input);
   }

   printf("None valid value.\n");
}

int valid_input(int lower, int upper)
{
    int input;
    if ( scanf("%d", &input) != 1 )
        return 4;
    if (input < lower || input > upper)
        return 0;
    else 
        return input;
    // there is a problem:
    // how to distinguish between returned output "4","0" and valide integer input.
}

void display_menu(void)
{
    printf(
        "Please chosse one of the follwing:\n"
        "1) copy files 2) move files\n"
        "3) remove files 4) quit\n"
        "Enter the number of your choice\n"
    );
}