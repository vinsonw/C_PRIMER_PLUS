#include <stdio.h>
#define DUNBAR_NUM 150

int main(void)
{
    int num_of_friends = 5;
    int index=0;

    do
    {
        index++;
        
        num_of_friends -= index;
        num_of_friends *= 2;
        printf("week %d, ", index);
        printf("number of friends: %d\n", num_of_friends);
    } while (num_of_friends <= DUNBAR_NUM);

    printf("done\n");

    return 0;
}