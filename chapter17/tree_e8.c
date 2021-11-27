#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree_e8.h"

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
static void DeleteNodeOrItem(Tree *pt, Trnode **ptr, const Item *pi);
static void DeleteAllNodes(Trnode * ptr);
static Pair SeekItem(const Item *pi, const Tree *ptree);

void InitializeTree(Tree * ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
    ptree->entry_size = 0;
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
    return ptree->entry_size;
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

    // printf("Now pi->petname: %s pi->petkind %s\n",
    // pi->petname, pi->petkind
    // );

    if ( (temp = SeekItem(pi, ptree).child) != NULL )
    {

        // Exercise 08
        bool petKindExist = false;
        printf("%s already exists as petkind %s\n",
        temp->item.petname,
        temp->item.petkind
        );

        petKindExist =  (!strcmp(pi->petkind, temp->item.petkind)) \
        || petKindExist;

        if (petKindExist)
        {
            fprintf(stderr, "%s %s already exists!\n", pi->petname, pi->petkind);
            return false;
        }

        Adj * adj, * prevAdj;
        adj = temp->item.next;
        prevAdj = adj;

        while  (NULL != adj)
        {
            printf("and also as petkind %s\n", adj->petkind);
            petKindExist = (!strcmp(adj->petkind, pi->petkind)) || petKindExist;
            prevAdj = adj;
            adj = adj->next;
        }

        if (petKindExist)
        {
            fprintf(stderr, "%s %s already exists!\n", pi->petname, pi->petkind);
            return false;
        }

        // if the control flow reaches here, the petname-petkind doesn't exit
        adj = (Adj *) malloc (sizeof(Adj));

        // set up the new Adj
        strcpy(adj->petkind, pi->petkind);
        adj->next = NULL;

        // connect new Adj to preceding Adj or Item 
        if (NULL == prevAdj) // No Ajd on this node before
            // prevAdj = adj; <- This is a bug!
            temp->item.next = adj;
        else // Adjs already exist.
            prevAdj->next = adj;

        printf("%s as NEW petkind \"%s\" was added.\n", 
        pi->petname,
        pi->petkind);

        ptree->entry_size++;

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
    ptree->entry_size++;

    if (ptree->root == NULL)
        ptree->root = new_node;
    else
        AddNode(new_node, ptree->root);

    return true;
}

bool InTree(const Item *pi, const Tree * ptree)
{
    // return (SeekItem(pi, ptree).child == NULL) ? false: true;

    // Exercise 08
    Trnode * pnode = SeekItem(pi, ptree).child;
    if (pnode != NULL) // petname exists, see SeekItem definition
    {
        if ( !strcmp(pnode->item.petkind , pi->petkind) )
            return true;

        Adj * adj;
        adj = pnode->item.next;
        while (adj != NULL)
        {
            if ( !strcmp(adj->petkind , pi->petkind) )
                return true;
            adj = adj->next;
        }

        // if the control flow gets here, not found
        return false;
    }
    else // no petname
        return false;
}
void PrintOtherItemsInTheSameNode(const Item *pi, const Tree * ptree)
{
    // return (SeekItem(pi, ptree).child == NULL) ? false: true;

    // Exercise 08
    Trnode * pnode = SeekItem(pi, ptree).child;
    if (pnode != NULL) // petname exists, see SeekItem definition
    {
        bool existsPetWithSameName = false;
        if ( strcmp(pnode->item.petkind , pi->petkind) )
        {
            existsPetWithSameName = true;
            printf(">>> %s the %s\n", pi->petname, pnode->item.petkind);
        }

        Adj * adj;
        adj = pnode->item.next;
        while (adj != NULL)
        {

            if ( strcmp(adj->petkind, pi->petkind) )
            {
                existsPetWithSameName = true;
                printf(">>> %s the %s\n", pi->petname, adj->petkind);
            }
            adj = adj->next;
        }
        if (!existsPetWithSameName)
        {
            printf("None.\n");
        }

        // if the control flow gets here, not found
    }
    else // no petname
        printf("%s the %s not in the tree.\n", pi->petname, pi->petkind);
}


bool DeleteItem(const Item *pi, Tree *ptree)
{
    if (!InTree(pi, ptree)) // test if the pet was in the tree.
    {
        fprintf(stderr, "%s %s not in the club!\n", pi->petname, pi->petkind);
        return false;
    }

    Pair look;

    // only looking for petname match, but we know from above the item
    // with the petkind was in the tree.
    look = SeekItem(pi, ptree); 
    if (look.child == NULL)
        return false;
    
    if (look.parent == NULL) // meaning the child is root, which is the target
        DeleteNodeOrItem(ptree, &ptree->root, pi);
    else if (look.parent->left == look.child)
        DeleteNodeOrItem(ptree, &look.parent->left, pi);
    else
        DeleteNodeOrItem(ptree, &look.parent->right, pi);

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
    ptree->entry_size--;
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
    if ( strcmp(i1->petname, i2->petname) < 0 )
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
    if ( strcmp(i1->petname, i2->petname) > 0)
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

Item * QueryItem(const Item *pi, const Tree *ptree)
{
    Pair p = SeekItem(pi, ptree);
    if (NULL == p.child)
        return NULL;
    else
        return &p.child->item;
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

static void DeleteNodeOrItem(Tree *pt, Trnode **ptr, const Item *pi)
{
    Trnode * temp;
    if (temp->item.next == NULL) // when there are no Adjs, delete the whole node
    {
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
        // update pt->size pt->entry-size
        pt->size--;
        pt->entry_size--;
    }
    else // Adjs exist
    {
        Adj * adj = temp->item.next;
        Adj * prevAdj = adj;

        // Exercise 08
        // The data arrangement is Node(Item, left, right), 
        // and the Item -> 1st Adj -> 2nd Adj -> 3rd Adj -> ...
        // There are three scenarios to consider:

        // Scenario 0: the Item is the petname-petkind to be deleted
        if ( !strcmp(temp->item.petkind, pi->petkind) )
        {
            temp->item.next = adj->next;
            strcpy(temp->item.petkind, adj->petkind);
            free(adj);
            pt->entry_size--;
            return;
        }

        // Scenario 1: the Adj that is immediately after Item(aka the 1st Adj) is the petname-petkind to be deleted
        if ( !strcmp(adj->petkind, pi->petkind) )
        {
            temp->item.next = adj->next;
            free(adj);
            pt->entry_size--;
            return;
        }
        
        // Scenario 2: the 2nd Adj and onwards
        adj = adj->next;
        while ( adj != NULL )
        {
            if ( !strcmp(adj->petkind, pi->petkind) )
            {
                prevAdj->next = adj->next;
                free(adj);
                pt->entry_size--;
                return;
            }
            prevAdj = adj; 
            adj = adj->next;
        }

        // if the control flow reaches here, the item is not in the tree.
        // But in Exercise 08, the calling fuction DeleteItem has used InTree function
        // to rule out the possibility, thus the following shouldn't be executed in Exercise 08.
        printf("\n%s exits, but no petkind called %s\n", pi->petname, pi->petkind);
    }
}