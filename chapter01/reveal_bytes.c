#include <stdio.h>

int main(void)
{
    printf("On this machine, the sizes in byte for some types:\n");
    printf("char == %d bytes\n", sizeof (char));
    printf("unsigned char == %d bytes\n", sizeof (unsigned char));
    printf("short == %d bytes\n", sizeof (short));
    printf("unsigned short == %d bytes\n", sizeof (unsigned short));
    printf("int == %d bytes\n", sizeof (int));
    printf("unsigned int == %d bytes\n", sizeof (unsigned int));
    printf("long == %d bytes\n", sizeof (long));
    printf("unsigned long == %d bytes\n", sizeof (unsigned long));
    printf("long long == %d bytes\n", sizeof (long long));
    printf("unsigned long long == %d bytes\n", sizeof (unsigned long long));
    printf("float == %d bytes\n", sizeof (float));
    printf("double == %d bytes\n", sizeof (double));
    printf("long double == %d bytes\n", sizeof (long double));
    printf(">>> And one byte == %d bits\n", __CHAR_BIT__);

    return 0;
}