#include <stdio.h>

int main(void)
{
    char name[20];
    float height_in_cm;
    printf("Please enter your name and height in centimerters:\n");
    scanf("%s %f", name,  &height_in_cm);
    printf("%s, you are %.3f meters tall.\n", name, height_in_cm / 100);

    return 0;

}