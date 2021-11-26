#ifndef _LIST_H

#define _LIST_H
#include <stdbool.h>

#define TSIZE 45

struct film
{
    char title[TSIZE];
    int rating;
};

typedef struct film Item;

typedef struct node
{
    Item item;
    struct node *next;
} Node;

// Original Listing 17.3 P791
// typedef Node * List;

// Exercise 02
typedef struct list {
    Node * head;
    Node * end;
} List;

void InitializeList(List * plist);
bool ListIsEmpty(const List *plist);
bool ListIsFull(const List *plist);
unsigned int ListItemCount(const List *plist);
bool AddItem(Item item, List * plist);
void Traverse(const List *plist, void (*pfun)(Item item));
void EmptyTheList(List * plist);

#endif