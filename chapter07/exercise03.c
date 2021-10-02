#include <stdio.h>

int main(void)
{
    int input;
    int e_cnt, o_cnt;
    int even_sum=0, odd_sum=0;

    while (scanf("%d", &input) == 1 && input != 0)
    {
        if (input % 2 == 0)
        {
            e_cnt++;
            even_sum += input;
        }
        else 
        {
            o_cnt++;
            odd_sum += input;
        }
    }

    printf("Total even: %d, average even: %.2f; ", even_sum, (double) even_sum / e_cnt );
    printf("Total odd: %d, average odd: %.2f\n", odd_sum, (double) odd_sum / o_cnt );
}