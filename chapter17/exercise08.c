#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree_e8.h"

#define SLEN 40

char menu(void);
void addpet(Tree *pt);
void droppet(Tree *pt);
void showpets(const Tree *pt);
void findpet(const Tree *pt);
void printitem(Item item);
void uppercase(char *str);
char *s_gets(char *st, int n);
void eatline(void);

int main(void)
{
    Tree pets;
    char choice;

    InitializeTree(&pets);
    while ((choice = menu()) != 'q')
    {
        switch (choice)
        {
        case 'a':
            addpet(&pets);
            break;
        case 'l':
            showpets(&pets);
            break;
        case 'f':
            findpet(&pets);
            break;
        case 'n':
            printf(">>> %d pets in club\n", TreeItemCount(&pets));
            break;
        case 'd':
            droppet(&pets);
            break;
        
        default:
            puts("Switching error");
            break;
        }
    }

    DeleteAll(&pets);
    puts("Bye.");

    return 0;
}

char menu(void)
{
    int ch;
    puts(">>> Nerfville Pet Club Membership Program");
    puts("Enter the letter corresponding to your choice:");
    puts(
        "a) add a pet      l) show list of pets\n"
        "n) number of pets f) find pets\n"
        "d) delete a pet   q) quit"
    );
    while ((ch=getchar()) != EOF)
    {
        eatline(); // clear the input queue
        ch = tolower(ch);
        if (strchr("alrfndq", ch) == NULL)
            puts("Please enter an a, l, f, n, d, or q:");
        else
            break;
    }
    if (EOF == ch)
        ch = 'q';
    
    return ch;
}

void addpet(Tree *pt)
{
    Item temp;

    if (TreeIsFull(pt))
        puts(">>> No room in the club!");
    else
    {
        puts("Please enter name of pet:");
        s_gets(temp.petname, SLEN);
        puts("Please enter kind of pet:");
        s_gets(temp.petkind, SLEN);
        temp.next = NULL; // make sure temp is properly initialized
        uppercase(temp.petname);
        uppercase(temp.petkind);
        AddItem(&temp, pt);
    }
}

void showpets(const Tree *pt)
{
    if (TreeIsEmpty(pt))
        puts(">>> No entries!");
    else
        Traverse(pt, printitem);
}

void printitem(Item item)
{
    printf(">>> Pet: %-19s Kind: %-19s\n",
    item.petname,
    item.petkind
    );

    // Exercise 08
    Adj * adj = item.next;

    // The following "If" caused a bug!
    // if (adj != NULL)
    while (adj != NULL)
    {
        printf(">>> Pet: %-19s Kind: %-19s\n",
        item.petname,
        adj->petkind);

        // printf(">>> adj == %p\n", adj);

        adj = adj->next;
    }
}

void findpet(const Tree *pt)
{
    Item temp;

    if (TreeIsEmpty(pt))
    {
        puts(">>> No entries!");
        return; // return void terminating the function
    }

    puts("Please enter name of pet you wish to find:");
    puts("Please enter name of pet:");
    s_gets(temp.petname, SLEN);
    puts("Please enter kind of pet:");
    s_gets(temp.petkind, SLEN);
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf(">>> %s the %s ", temp.petname, temp.petkind);
    if (InTree(&temp, pt))
    {
        printf("Is a member.\n");
        printf("Pets with the same name:\n");
        PrintOtherItemsInTheSameNode(&temp, pt);
    }
    else
        printf("is not a member.\n");
}

void droppet(Tree *pt)
{
    Item temp;
    if (TreeIsEmpty(pt))
    {
        puts("No entries!");
        return; // return void terminating the function
    }

    puts("Please enter name of pet you wish to delete:");
    puts("Please enter name of pet:");
    s_gets(temp.petname, SLEN);
    puts("Please enter kind of pet:");
    s_gets(temp.petkind, SLEN);
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf(">>> %s the %s ", temp.petname, temp.petkind);
    if (DeleteItem(&temp, pt))
        printf("is dropped from the club.\n");
    else
        printf("is not a member.\n");
}

void uppercase(char * str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

void eatline(void)
{
        while (getchar() != '\n')
            continue;
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