#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("Hi, please enter your first and last name:\n");
    
    char first_name[20];
    char last_name[20];
    scanf("%s %s", first_name, last_name);
    printf("Okay, this is the stats:\n");
    printf("%21s %21s\n", first_name, last_name);
    printf("%21d %21d\n", strlen(first_name), strlen(last_name)); // if %21d was written as %21s, string thins would happen.

    printf("And this is the same stats in left-aligned form:\n");
    printf("%-21s %-21s\n", first_name, last_name);
    printf("%-21d %-21d\n", strlen(first_name), strlen(last_name));

    return 0;
}