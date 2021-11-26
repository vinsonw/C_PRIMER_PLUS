// for Exercise 03
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list_e3.h"


void InitializeList(List *plist)
{
    plist->items = 0;
}


bool ListIsEmpty(const List *plist)
{
    if (0 == plist->items)
        return true;
    else
        return false;
}

bool ListIsFull(const List * plist)
{
    bool isFull = false;
    if (plist->items == MAXSIZE)
        isFull = true;

    return isFull;
}

unsigned int ListItemCount(const List *plist)
{
    return plist->items;
}

bool AddItem(Item item, List * plist)
{
    plist->entires[plist->items] = item;
    plist->items++;
    return true;
}

void Traverse (const List *plist, void (*pfun)(Item item))
{

    for (int i=0; i<plist->items; i++)
        (*pfun)(plist->entires[i]);

}

void EmptyTheList(List *plist)
{
   // for Exercise 03, don't need to explicitly free an array 
}
