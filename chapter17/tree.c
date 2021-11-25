#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/* local data type */
typedef struct pair {
    Trnode * parent;
    Trnode * child;
} Pair;

/* prototypes for local funtctions */
static Trnode * MakeNode(const Item *pi);
static bool ToLeft(const Item * i1, const Item *i2);
static bool ToRight(const Item * i1, const Item *i2);
static void AddNode (Trnode * new_node, Trnode * root);
static void InOrder(const Trnode * root, void (* pfun)(Item item));
static Pair SeekItem(const Item * pi, const Tree * ptree);
static void DeleteNode(Trnode **ptr);
static void DeleteAllNodes(Trnode * ptr);

void InitializeTree(Tree * ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree * ptree)
{
    if (ptree->root == NULL)
        return true;
    else
        return false;
}

bool TreeIsFull(const Tree * ptree)
{
    if (ptree->size == MAXITEMS)
        return true;
    else
        return false;
}

int TreeItemCount(const Tree * ptree)
{
    return ptree->size;
}

bool AddItem(const Item * pi, Tree * ptree)
{
    Trnode * new_node;
    Trnode * temp;

    if (TreeIsFull(ptree))
    {
        fprintf(stderr, "Tree is full\n");
        return false;
    }
    if ( (temp =  SeekItem(pi, ptree).child) != NULL)
    {
        // problem dependent

        // fprintf(stderr, "Attempted to add duplicate item\n");
        // return false;

        // Review question 07
        printf("%s alread exists, count increment by 1 to %d\n",
        temp->item.word,
        ++(temp->item.word_cnt));
        return true;

    }
    new_node = MakeNode(pi);
    if (new_node == NULL)
    {
        fprintf(stderr, "Couldn't create node\n");
        return false;
    }
    /* succeeded in creating a new node */
    ptree->size++;

    if (ptree->root == NULL)
        ptree->root = new_node;
    else
        AddNode(new_node, ptree->root);

    return true;
}

bool InTree(const Item *pi, Tree * ptree)
{
    return (SeekItem(pi, ptree).child == NULL) ? false: true;
}

bool DeleteItem(const Item *pi, Tree *ptree)
{
    Pair look;

    look = SeekItem(pi, ptree);
    if (look.child == NULL)
        return false;
    
    if (look.child == NULL)
        DeleteNode(&ptree->root);
    else if (look.parent->left == look.child)
        DeleteNode(&look.parent->left);
    else
        DeleteNode(&look.parent->right);
    ptree->size--;

    return true;
}

void Traverse(const Tree * ptree, void (*pfun)(Item item))
{
    if (ptree != NULL)
        InOrder(ptree->root, pfun);
}

void DeleteAll(Tree * ptree)
{
    if (ptree != NULL)
        DeleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}

static void InOrder(const Trnode * root, void (*pfun)(Item item))
{
    if (root != NULL)
    {
        InOrder(root->left, pfun);
        (*pfun)(root->item);
        // printf("%s node address %p %p %p\n", root->item.word, root, root->left, root->right);
        InOrder(root->right, pfun);
    }
}

static void DeleteAllNodes(Trnode * root)
{
    Trnode * pright;

    if (root != NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}

static void AddNode(Trnode * new_node, Trnode * root)
{
    if (ToLeft(&new_node->item, &root->item)) // ToLeft seems to have a bug and always return true
    {
        printf("new item: %s root item: %s \n", new_node->item.word, root->item.word);
        if (root->left == NULL)
            root->left = new_node;
        else
            AddNode(new_node, root->left);
    }
    else if (ToRight(&new_node->item, &root->item))
    {
        if (root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node, root->right);
    }
    else
    {
        fprintf(stderr, "Location error in AddNode()\n");
        exit(1);
    }
}

static bool ToLeft(const Item * i1, const Item * i2)
{
    // int comp1;
    // Problem dependent
    
    // for Review Question 7
    if ( strcmp(i1->word, i2->word) < 0 )
    {
        return true;
    }
    else
        return false; // !!! Previous left out "return", causing always return true

}

static bool ToRight(const Item * i1, const Item * i2)
{

    // Problem dependent
    // for Review Question 7
    if ( strcmp(i1->word, i2->word) > 0)
    {
        // printf("R: %s vs %s\n", i1->word, i2->word);
        return true;
    }
    else
        return false;

}

static Trnode * MakeNode(const Item * pi)
{
    Trnode * new_node;

    new_node = (Trnode *) malloc(sizeof(Trnode)); // not bound to block scope
    if (new_node != NULL)
    {
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }

    return new_node;
}

static Pair SeekItem(const Item *pi, const Tree *ptree)
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;

    if (look.child == NULL)
        return look;
    
    while (look.child != NULL)
    {
        if (ToLeft(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else
            break;
    }

    return look;
}

static void DeleteNode(Trnode **ptr)
{
    Trnode * temp;
    if ( (*ptr)->left == NULL )
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
    else if ( (*ptr)->right == NULL )
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
    else
    {
        for (temp = (*ptr)->left; temp->right != NULL;
        temp = temp->right)
            continue;
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}