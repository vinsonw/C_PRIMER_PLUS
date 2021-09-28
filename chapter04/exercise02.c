#include <stdio.h>
#include <string.h>

int main(void)
{
    char first_name[10];
    printf("Please enter your first name:\n");
    scanf("%s", first_name);
    // a. Prints it enclosed in double quotation marks.
    printf("\"%s\"\n", first_name);

    // b. Prints it in a field 20 character wide, with the whole field in quotes
    // and the name at the right end of the field.
    printf("\"%20s\"\n", first_name);

    // c. Prints it at the left end of a field 20 character wide, with the whole
    // field enclosed in quotes
    printf("\"%-20s\"\n", first_name);

    // d. Prints it in a field three characters wider than the name
    int len_of_first_name = strlen(first_name);
    int required_width = len_of_first_name + 3;
    printf("%*s\n", required_width, first_name);

    return 0;

    

}