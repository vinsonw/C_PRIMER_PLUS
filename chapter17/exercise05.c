#include <stdio.h>
#include <string.h>
#include "stack.h"

char *s_gets(char *, int n);

int main(void)
{
    puts("Please enter a string.");
    char s[MAX_STACK_SIZE+1]; 
    s_gets(s, MAX_STACK_SIZE+1);

    Stack stack;
    Item temp;
    InitializeStack(&stack);

    // Pushing down
    char *ptr = s;
    while (*ptr)
    {
        temp = *ptr;
        PushItem(&temp, &stack);
        printf("'%c' pushed in to stack\n", temp);
        ptr++;
    }

    // Poping up
    int leftItem;
    do 
    {
        leftItem = PopItem(&temp, &stack);
        printf("'%c' poping up\n", temp);

    } while (leftItem > 0);

    printf("Stack size %d\n", stack.stack_size);

    return 0;
}

char *s_gets(char *s, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(s, n, stdin);
    if (ret_val)
    {
        find = strchr(s, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}