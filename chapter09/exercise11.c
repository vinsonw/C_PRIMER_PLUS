#include <stdio.h>
#define N 10

void fib0(int);
unsigned Fibonacci_using_loop(int);
unsigned Fibonacci_using_recursion(int);

int main(void)
{
    printf("Fib of length of %d is as:\n", N);
    fib0(N);
    printf("final number is %d(calculated in loop way)\n", Fibonacci_using_loop(N));
    printf("final number is %d(calculated in recursion way)\n", Fibonacci_using_recursion(N));

    return 0;
}

void fib0(int n)
{
    int i=0;
    int a = 1;
    int b = 1;
    int temp;
    while (i<n)
    {
        printf("%d ", a);
        temp = a;
        a = b;
        b = b + temp;
        i++;
    }

    printf("\n");
}

unsigned Fibonacci_using_loop(int n)
{
    int i=1;
    int a = 1;
    int b = 1;
    int temp;
    while (i<n)
    {
        temp = a;
        a = b;
        b = b + temp;
        i++;
    }

    return a;
}

unsigned Fibonacci_using_recursion(int n)
{
    if (n>2) 
        return Fibonacci_using_recursion(n-1) + Fibonacci_using_recursion(n-2);
    else
        return 1;
}
