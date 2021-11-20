#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct names {
    char first[40];
    char last[40];
};

void showstaff(const struct names staff[], int n);
int mycomp(const void * p1, const void *p2);
int negative_mycomp(const void * p1, const void *p2);

int main(void)
{

    struct names staff[5] = {
        {"Walt", "White"},
        {"Holly", "White"},
        {"Jessie", "Pinkman"},
        {"Huel", "Jackman"},
        {"Saul", "Goodman"},
    };
    printf(">>Initial staff order:\n");
    showstaff(staff, 5);
    printf(">>Sorted order(ascending by name):\n");
    qsort(staff, 5, sizeof(struct names), mycomp);
    showstaff(staff, 5);
    printf(">>Sorted order(descending by name):\n");
    qsort(staff, 5, sizeof(struct names), negative_mycomp);
    showstaff(staff, 5);
}

void showstaff(const struct names staff[], int n)
{
    for (int i=0; i<n; i++)
        printf("%s, %s\n",staff[i].last, staff[i].first);
}

int mycomp(const void * p1, const void *p2)
{
    const struct names * ps1 = (const struct names *) p1;
    const struct names * ps2 = (const struct names *) p2;
    int res;

    res = strcmp(ps1->last, ps2->last);
    if (res != 0)
        return res;
    else
        return strcmp(ps1->first, ps2->first);
}

int negative_mycomp(const void * p1, const void *p2)
{
    const struct names * ps1 = (const struct names *) p1;
    const struct names * ps2 = (const struct names *) p2;
    int res;

    res = strcmp(ps1->last, ps2->last);
    if (res != 0)
        return -res;
    else
        return -strcmp(ps1->first, ps2->first);
}