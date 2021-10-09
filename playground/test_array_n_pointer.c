#include <stdio.h>

int main(void)
{
    int zippo[4][2] = {{2,4}, {6,8}, {1,3}, {5,7}};

    printf("Do the following symbols have the same value?\n");
    printf("zippo = %p\n", zippo);
    printf("&zippo = %p\n", &zippo);
    printf("*zippo = %p\n", *zippo);
    printf("zippo[0] = %p\n", zippo[0]);
    printf("&zippo[0] = %p\n", &zippo[0]);
    printf("*zippo[0] = %d\n", *zippo[0]); // *zippo[0] gets the first int value stored in zippo[0][0]

    printf("\n------------\n"
    "for simple one-dimensional array of int type.\n" 
    );
    int a[3] = {1,2,3};
    printf("a = %p\n", a); // here, "a" decays to a pointer to its first element.
    printf("&a = %p\n", &a); // to get the address of array "a"
    printf("&a[0] = %p\n", &a[0]); // to get the address of the first element of array "a"

    return 0;
}