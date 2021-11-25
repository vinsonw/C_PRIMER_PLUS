#include <stdio.h>
#include <string.h>
#include "tree.h"

#define TEXT_LENGTH 2000
#define WORD_LENGTH 50
#define TEXT_NUM 4

char *s_gets(char *, int);
void show_item(const Item);

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
        s_gets(temp_text, TEXT_LENGTH+1);
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
    printf(">> Display:\n");
    for (int i=0; i<TEXT_NUM; i++)
    {
        printf("In text %d\n", i+1);
        Traverse(&(text[i]), show_item);
        putchar('\n');
    }

    Item food;
    strcpy(food.word,"food");
    food.word_cnt = 1;
    for (int i=0; i<TEXT_NUM; i++)
    {
        DeleteItem(&food,&text[i]);
    }
    printf(">> Remove \"food\"\n");
    for (int i=0; i<TEXT_NUM; i++)
    {
        printf("In text %d\n", i+1);
        Traverse(&(text[i]), show_item);
        putchar('\n');
    }

    
}

char *s_gets(char *temp, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(temp, n, stdin);
    if (ret_val)
    {
        find = strchr(temp, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;

}

void show_item(const Item item)
{
    printf("%s : %d ", item.word, item.word_cnt);
}