#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

#define TEXT_LENGTH 2000
#define WORD_LENGTH 50
#define TEXT_NUM 1 // In this case only analyze one text

char *s_gets(char *, int, FILE *);
void show_item(const Item);
void display_menu(void);
void eatline(void);

int main(void)
{
    Tree text[4];
    char temp_text[TEXT_LENGTH+1];
    char temp_word[WORD_LENGTH+1];
    const char s[2] = " ";
    for (int i=0; i<TEXT_NUM; i++)
    {
        InitializeTree(&text[i]);
        printf("Please enter text %d\n", i);
        FILE *fp;
        fp = fopen("corpus.txt", "r");
        if (fp == NULL)
        {
            printf("damn");
            exit(0);
        }
        while ( s_gets(temp_text, TEXT_LENGTH+1, fp) )
        {
            printf("temp_text %s\n", temp_text);

            char * w = strtok(temp_text, s);
            Item item;
            while (w) 
            {
                strcpy(item.word, w);
                item.word_cnt = 1;
                AddItem(&item, &text[i]);

                printf("%s added\n", item.word);

                w = strtok(NULL, s);
            }
        }
        while (1)
        {
            display_menu();
            char ch;
            scanf("%c", &ch);
            eatline();
            
            if ('l' == ch)
            {
                printf(">> Display:\n");
                for (int i=0; i<TEXT_NUM; i++)
                {
                    printf("In text %d\n", i+1);
                    printf("------------\n");
                    Traverse(&(text[i]), show_item);
                    putchar('\n');
                }
            }
            else if ('e' == ch)
            {
                printf("Enter the word\n");
                s_gets(temp_text, TEXT_LENGTH+1, stdin);
                Item item;
                // item.word_cnt doesn't matter in this case
                strcpy(item.word, temp_text);
                
                Item * result = QueryItem(&item, &text[i]);
                if (result == NULL)
                {
                    printf(">> %s doesn't exit in the text.\n", temp_text);
                }
                else
                {
                    printf(">> %s : %d\n",
                    temp_text,
                    result->word_cnt
                    );
                }
            }
            else if ('q' == ch)
                exit(1);
            else
                printf("wrong input, try again.\n");
        }
    }



    
}

char *s_gets(char *temp, int n, FILE *fp)
{
    char *ret_val;
    char *find;
    ret_val = fgets(temp, n, fp);
    if (ret_val)
    {
        find = strchr(temp, '\n');
        if (find)
            *find = '\0';
    }
    return ret_val;

}

void show_item(const Item item)
{
    printf("%s : %d \n", item.word, item.word_cnt);
}

void display_menu(void)
{
    printf("Please chose:\n"
    "l) List all the words along with the number of occurrences.\n"
    "e) Enter a word, show how many times it appears in the text.\n"
    "q) quit\n"
    );
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}