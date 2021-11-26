// Approach 2: recursion

/* film2.c -- using a linked list of structures */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45

struct film {
    char title[TSIZE];
    int rating;
    struct film * next;
};

char *s_gets(char *, int);
void forward_display_linked_list(struct film * head);
void backward_display_linked_list(struct film * head);
void free_linked_list(struct film *head);

int main(void)
{
    struct film * head = NULL;
    struct film * prev, * current;
    char input[TSIZE];

    puts("Enter first movie title: ");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (struct film *) malloc(sizeof(struct film));
        current->next = NULL;
        if (head == NULL)
            head = current;
        else
            prev->next = current;
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
        forward_display_linked_list(head);
    else if ('b' == ch)
        backward_display_linked_list(head);
    else
        printf("wrong input");

    free_linked_list(head);

    printf("Bye!\n");
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

void backward_display_linked_list(struct film * head)
{
    // recursion solution
    if (head->next != NULL)
        backward_display_linked_list(head->next);
    printf("Movie: %s, Rating: %d\n", head->title, head->rating);
    head = head->next;
}

void forward_display_linked_list(struct film * head)
{
    while (head != NULL)
    {
        printf("Movie: %s, Rating: %d\n",
            head->title, head->rating);
        head = head->next;
    }
}

void free_linked_list(struct film *head)
{
    struct film * temp;
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}