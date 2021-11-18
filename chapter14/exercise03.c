/* manybook.c -- multiple book inventory */
#include <stdio.h>
#include <string.h>
char *s_gets(char *st, int n);
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};


int main(void)
{
    struct book library[MAXBKS];
    int count = 0;
    int index;

    printf("Please tner the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
        && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n'");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }

    if (count > 0)
    {
        printf("Here is the list of your books:\n");
        for (index = 0; index < count; index++) 
            printf("%s by %s: $%.2f\n", library[index].title, 
            library[index].author, library[index].value);
        
        //===== the following is the key to making sorting work =====
        // you have to put the items to be sorted in one list first
        // then you start to sort them.
        struct book *pa[count];
        struct book *pv[count];
        for (index = 0; index < count; index++)
            pa[index] = pv[index] = &library[index];
        //===== the above is the key to making sorting work =====

        struct book *temp;
        for (index = 0; index < count; index++)
            for (int j = index+1; j < count; j++)
            {
                if ( strcmp(pa[index]->title, pa[j]->title) < 0 )
                {
                    temp = pa[j];
                    pa[j] = pa[index];
                    pa[index] = temp;
                }

                if ( pv[j]->value - pv[index]->value < 0 )
                {
                    temp = pv[j];
                    pv[j] = pv[index];
                    pv[index] = temp;
                }
            }

        printf("again in alphabetical order:\n");
        for (index = 0; index < count; index++) 
            printf("%s by %s: $%.2f\n", (*pa[index]).title, 
            (*pa[index]).author, (*pa[index]).value);
        printf("again in increased value order:\n");
        for (index = 0; index < count; index++) 
            printf("%s by %s: $%.2f\n", (*pv[index]).title, 
            (*pv[index]).author, (*pv[index]).value);
    }
    else
        printf("No books? Too bad.\n");
    
    return 0;
}

char *s_gets(char *st, int n)
{
    char *rv;
    char *find;

    rv = fgets(st, n, stdin);
    if (rv)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while ( getchar() != '\n')
                continue;
            
    }
    return rv;
}