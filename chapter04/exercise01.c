#include <stdio.h>

int main(void)
{
    char first_name[10];
    char last_name[10];

    printf("Please enter you first name and last name:\n");
    scanf("%s %s", first_name, last_name);
    printf("Hello, %s,%s\n", last_name, first_name);

    return 0;
}