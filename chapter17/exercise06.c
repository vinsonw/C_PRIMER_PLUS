#include <stdio.h>
#include <stdbool.h>

bool binary_search_interger(int *arr, int n, int x);

int main(void)
{
    puts("Please enter an ascending array of 5 intergers:");

    int arr[5];
    for (int i=0; i<5; i++)
        scanf("%d", arr+i);
    while (getchar() != '\n')
        continue;

    puts("Please enter the integer to search:");
    int x;
    scanf("%d", &x);
    while (getchar() != '\n')
        continue;
    if (binary_search_interger(arr, 5, x))
        printf("yes.\n");
    else
        printf("no.\n");

}


bool binary_search_interger(int *arr, int n, int x)
{
    // requiring arr is in ascending order
    // mark guessed position, avoid dead loop
   int mark[n];
   for (int i=0; i<n; i++)
        mark[i] = 0;

   int guess = n / 2;
   while ( arr[guess] != x )
   {
        mark[guess] = 1;
        if (arr[guess] < x) 
            guess = (guess + n) / 2;
        else
            guess = (guess + 0) / 2;
        if (mark[guess] == 1)
            break;
   }

   return arr[guess] == x;
}