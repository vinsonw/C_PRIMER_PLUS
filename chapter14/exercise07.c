/* booksave.c -- saves sturcture contents in a file */
/* inspect records one by one */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

char *s_gets(char *st, int n);
void eatline(void);

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};


int main(void)
{
    struct book library[MAXBKS];
    int count = 0;
    int index, filecount;
    FILE *pbooks;

    int size = sizeof (struct book);

    if ( (pbooks = fopen("book.dat", "a+b")) == NULL )
    {
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }

    rewind(pbooks);
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
    {
        if (0 == count)
            printf("The whole file is as follows:\n");
        printf("%s by %s: $%.2f\n", library[count].title,
            library[count].author, library[count].value);
        count++;
    }

    fclose(pbooks);

    char ch;
    printf("Right now, there're %d books in book.txt, do you want to add more?"
    "(y for yes, n for no).\n"
    , count);
    scanf("%c", &ch);
    eatline();
    if ( 'y' == ch )
    {
        puts("Please add new book titles.");
        puts("Press [enter] at the start of a line to stop.");
        while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
            && library[count].title[0] != '\0')
        {
            printf("Now enter the author.\n'");
            s_gets(library[count].author, MAXAUTL);
            printf("Now enter the value.\n");
            scanf("%f", &library[count++].value); // after the last item "value", increment "count" by 1.
            while (getchar() != '\n')
                continue;
            if (count < MAXBKS)
                printf("Enter the next title.\n");
        }
    }

    if (count > 0)
    {
  
        char ch;
        printf("===========================\n");
        printf("Now inspect book one by one:\n");
        for (index = 0; index < count; index++) 
        {
            printf(">>> #Book:%02d: %s by %s: $%.2f\n", index+1, library[index].title, 
            library[index].author, library[index].value);
            printf("Do you want to delete(d), modify(m) or approve(a) this line?\n");
            while ( scanf("%c", &ch) != 1 || (ch != 'd' && ch != 'm' && ch != 'a') )
            {
                eatline();
                puts("wrong input, try again:"); 
            }
            eatline(); // if put this ONLY inside the above while loop, a bug will creep in
            if ('d' == ch)
            {
                for (int i=index; i < count-1; i++)
                {
                    strcpy(library[i].title, library[i+1].title);
                    strcpy(library[i].author, library[i+1].author);
                    library[i].value = library[i+1].value;
                }

                count--; // decrease the lenght of the array by 1
                index--; // look at the same index again next circle
            }
            else if ('m' == ch)
            {
                printf("Please enter the new book info:\n");
                printf("Now enter the title.\n'");
                s_gets(library[index].title, MAXTITL);
                printf("Now enter the author.\n'");
                s_gets(library[index].author, MAXAUTL);
                printf("Now enter the value.\n");
                scanf("%f", &library[index].value);
                while (getchar() != '\n')
                    continue;
            }
                
        }

        FILE *npf;
        if ( (npf = fopen("book.dat", "w")) == NULL )
        {
            fputs("Can't open book.txt file\n", stderr);
            exit(1);
        }
        fwrite(library, size, count, npf);
        fclose(npf);
        
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

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}