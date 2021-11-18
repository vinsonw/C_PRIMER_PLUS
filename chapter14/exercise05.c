#include <stdio.h>
#define CSIZE 4

struct name {
    char first[20];
    char second[20];
};

struct student {
    struct name name;
    float grade[3];
    float avg;
};

int main(void)
{
    struct student students[CSIZE] = {
        {.name.first="Jack"},
        {.name.first="Missy"},
        {.name.first="Huel"},
        {.name.first="Frank"},
    };
    for (int i=0; i<CSIZE; i++)
    {
        printf("Please enter the 3 scores for %s:\n", students[i].name.first);
        scanf("%f %f %f", &students[i].grade[0],&students[i].grade[1],&students[i].grade[2]);
        students[i].avg = (students[i].grade[0]+students[i].grade[1]+students[i].grade[2]) / 3.0;
    }

    float ttl_score=0.;
    for (int i=0; i<CSIZE; i++)
    {
        printf("Average score for %s is: ", students[i].name.first);
        printf("%.2f\n", students[i].avg);
        ttl_score += students[i].avg;
    }
    printf("Class average: %.2f\n", ttl_score / CSIZE);

    return 0;

}