#include <stdio.h>
void print_primes(int upper_limit);

int main(void)
{
    int input;
    printf("Please enter an integer, and we will give back all the primes that're smaller that it.\n");
    scanf("%d", &input);
    print_primes(input);

    return 0;
}

void print_primes(int upper_limit)
{
    int index;
    int inner_index;
    for (index=2; index<=upper_limit; index++)
    {
        int isPrime=1;
        for(inner_index=2; inner_index*inner_index<=index; inner_index++)
        {
            // printf("index=%d,inner_index=%d\n", index, inner_index);
            if (index % inner_index == 0)
                isPrime=0;

        }

        if (isPrime)
            printf("%d ", index);
    }

    printf("\n");
}