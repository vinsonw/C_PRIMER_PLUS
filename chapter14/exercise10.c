#include <stdio.h>

void a(void);
void b(void);
void c(void);
void d(void);

int main(void)
{
    void (*arr[4])(void) = {a, b, c, d};
    printf("Choose a function to run:\n"
    "a) a\n"
    "b) b\n"
    "c) c\n"
    "d) d\n"
    );
    char ch;
    scanf("%c", &ch);
    switch (ch)
    {
    case 'a':
        arr[0]();
        break;
    case 'b':
        arr[1]();
        break;
    case 'c':
        arr[2]();
        break;
    case 'd':
        arr[3]();
        break;
    
    default:
        break;
    }

}

void a(void)
{
    printf("Hello from a()!");
}

void b(void)
{
    printf("Hello from b()!");
}

void c(void)
{
    printf("Hello from c()!");
}

void d(void)
{
    printf("Hello from d()!");
}