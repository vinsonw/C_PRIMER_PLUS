#include <stdio.h>
#include <stdlib.h>
#include "stack.h" 

static bool ItemEqual(const Item * i1, const Item * i2);

void InitializeStack(Stack *pstack)
{
    pstack->stack_top = NULL;
    pstack->stack_size = 0;
}

int PushItem(Item * item, Stack * pstack)
{
    Node * pnode = (Node *) malloc(sizeof(Node));
    pnode->item = *item;
    pnode->down = pstack->stack_top;
    pstack->stack_top = pnode; 
    pstack->stack_size++;
    return pstack->stack_size;
}

int PopItem(Item * item, Stack * pstack)
{
    *item = pstack->stack_top->item;
    Node * temp = pstack->stack_top;
    pstack->stack_top = pstack->stack_top->down;
    free(temp);
    pstack->stack_size--;
    return pstack->stack_size;
}

bool ItemInStack(Item * item, Stack * pstack)
{
    bool inStack = false;
    Node * scan = pstack->stack_top;
    while (scan != NULL)
    {
        if (ItemEqual(&scan->item, item))
        {
            inStack = true;
            break;
        }
        scan = scan->down;
    }
    
    return inStack;
}


int StackItemCount(Stack *pstack)
{
    return pstack->stack_size;
}

bool StackIsEmpty(Stack *pstack)
{
    return 0 == pstack->stack_size;
}

bool StackIsFull(Stack *pstack)
{
    return MAX_STACK_SIZE == pstack->stack_size;
}

static bool ItemEqual(const Item * i1, const Item * i2)
{
    bool isEqual = false;

    // define "char" as "Item"
    if (*i1 == *i2)
        isEqual = true;

    return isEqual;
}