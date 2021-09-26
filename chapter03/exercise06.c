#include <stdio.h>

int main(void)
{
    int quarts;
    printf("How many quarts of water do you have?\n");
    scanf("%d", &quarts);
    long double num_of_molecules = quarts * 950 / (3.0e-23);
    printf("Okay, that's about %lld molecules in there!\n", num_of_molecules);

    return 0;
}