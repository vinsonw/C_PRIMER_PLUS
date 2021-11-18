#include <stdio.h>
#include <string.h>

struct fml
{
    char first[40];
    char middle[40];
    char last[40];
};

struct person_id {
    char sid[20];
    struct fml name;
};

void print_id(struct person_id);

int main(void)
{
    struct person_id sb = { "302039823", {"Flossie", "Morgan", "Dribble" } };
    struct person_id sb1 = { "802339823", { "Frank",  "\0",  "Underwood"} };
    print_id(sb);
    print_id(sb1);

    return 0;
}

void print_id(struct person_id p)
{
    printf(p.name.last);
    printf(", ");
    printf(p.name.first);
    if (strlen(p.name.middle))
        printf(" %c.", *(p.name.middle));
    printf(" -- ");
    printf("%s\n", p.sid);
}