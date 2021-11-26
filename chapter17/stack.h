/* Review Question 05
 * a. Devise an ADT for a stack
 * >>> Type Name: Stack
 * >>> Type Properties: 
    *  A stack is a kind of list.
    *  In a stack, additions and deletions can be 
    *  made from only one end of the list
 * >>> Type Operations: 
    *  push item onto the top of the stack
    *  pop off item from the stack 
*/

/*
 * b. Devise a C programming interface for a stack, 
 * i.e., a stack.h header file.
*/
#include <stdbool.h>

#ifndef _STACK_H
#define _STACK_H

typedef struct item {
   // any item you want to define.
} Item;

typedef struct node {
   Item item;
   struct node * up;
   struct node * down;
} Node;

typedef struct stack {
   Node * stack_bottom;
   int stack_size;
} Stack;

void InitializeStack(Stack *);

void PushItem(Item *, Stack *);
void PopItem(Item *, Stack *);
bool ItemInStack(Item *, Stack *);

int StackItemCount(Stack *);
bool StackIsEmpty(Stack *);
bool StackIsFull(Stack *);

#endif