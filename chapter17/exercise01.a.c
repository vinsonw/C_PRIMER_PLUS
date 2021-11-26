// Approach 1: To modify the linked-list definition 
// so that the list can be traversed in both directions

/* film2.c -- using a linked list of structures */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45

struct film {
    char title[TSIZE];
    int rating;
    struct film * next;
    struct film * prec;
};

char *s_gets(char *, int);


int main(void)
{
    struct film * head = NULL;
    struct film * tail = NULL;
    struct film * prev, * current;
    char input[TSIZE];

    puts("Enter first movie title: ");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (struct film *) malloc(sizeof(struct film));
        current->next = NULL;
        current->prec = NULL;
        if (head == NULL)
        {
            head = current;
            tail = current;
        }
        else
        {
            prev->next = current;
            current->prec = prev;
            tail = current;
        }
        strcpy(current->title, input);
        puts("Enter your rating <0-10>");
        scanf("%d", &current->rating);
        while ( getchar() != '\n' )
            continue;
        puts("Enter next movie title (empty line to stop):");
        prev = current; // important
    }

    if (head == NULL)
    {
        printf("No movie entered\n");
        exit(0);
    }
    else
        printf("Choose the order you want to display the movies:\n"
        "a) as input b) backwards\n"
        );
    char ch;
    scanf("%c", &ch);
    while (getchar() != '\n') continue;
    if ('a' == ch)
    {
        current = head;
        while (current != NULL)
        {
            printf("Movie: %s, Rating: %d\n",
                current->title, current->rating);
            current = current->next;
        }

        current = head;
        struct film * temp;
        while (current)
        {
            temp = current;
            current = current->next;
            free(temp);
        }
        printf("Bye!\n");
    }
    else if ('b' == ch)
    {
        current = tail;
        while (current != NULL)
        {
            printf("Movie: %s, Rating: %d\n",
                current->title, current->rating);
            current = current->prec;
        }

        current = tail;
        struct film * temp;
        while (current)
        {
            temp = current;
            current = current->prec;
            free(temp);
        }
        printf("Bye!\n");

    }
    else
        printf("wrong input");

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