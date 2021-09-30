#include <stdio.h>

int main(void)
{
    int arr[8];
    printf("Input 8 integers. You know the deal: ");
    int index;
    for(index=0; index<8; index++)
        scanf("%d", &arr[index]); // if '&' is forgotten, you would have compile error.
    for(index=7; index>-1; index--)
        printf("%d", arr[index]);
    printf("\n");

    return 0;
}