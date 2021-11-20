#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void pick_rand(int *arr, int size, int num_of_pick);

int main(void)
{
    // int jurors[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    // pick_rand(jurors, 12, 6);

    // big lotto
    // 35-5, 12-2
    int front[35] = {1,2,3,4,5,6,7,8,9,10,11,12,
    13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23,
    24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34,
    35
    };
    int back[12] = {1,2,3,4,5,6,7,8,9,10,11,12};

    printf(">>> Big Lotto:\n");
    pick_rand(front, 35, 5);
    pick_rand(back, 12, 2);

    // 33-6, 16-1
    int red[33] = {1,2,3,4,5,6,7,8,9,10,11,12,
    13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23,
    24, 25, 26, 27, 28, 29, 30, 31, 32, 33 
    };
    int blue[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    printf(">>> Double-color Balls:\n");
    pick_rand(red, 33, 6);
    pick_rand(back, 16, 1);
}

void pick_rand(int *arr, int size, int num_of_pick)
{
   srand((unsigned) time(NULL));

   int index;
   int picked[num_of_pick];
   int mark[size];
   for (int i=0; i<size; i++)
        mark[i] = 0;

   int pick_cnt=0;
   while (pick_cnt < num_of_pick)
   {
       index = rand() % size;
       if (0 == mark[index])
       {
            mark[index] = 1;
            picked[pick_cnt] = *(arr+index);
            pick_cnt++;
       }
   }

   puts("Picked:");
   for (int i=0; i<num_of_pick; i++)
        printf("%d ", picked[i]);
   putchar('\n');

}