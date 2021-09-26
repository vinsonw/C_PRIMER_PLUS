#include <stdio.h>

int main(void)
{
    int age;
    printf("How old are you?\n");
    scanf("%d", &age);
    printf("OKay, you have lived about %.0f seconds\n", age*3.156E7);

}