#include <stdio.h>

int main(void)
{
    int h, l;
    printf("Please enter the low limit and the high limit:");
    scanf("%d %d", &l, &h);
    printf("Here is the table:\n");
    int index;
    for (index=l; index<h+1; index++)
        printf("%d %d %d\n", index, index * index, index * index * index);

    return 0;
}