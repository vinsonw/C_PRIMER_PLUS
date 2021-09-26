// write a program that asks you to enter an ascii code value, such as 66, and 
// then prints the character having that ascii code.
#include <stdio.h>

int main(void)
{
    printf("Plese give me a ascii code for a character:\n");
    char input;
    scanf("%d", &input);
    printf("Ok, ascii code %d represents character \"%c\" in computer\n", input, input);

    return 0;
}


