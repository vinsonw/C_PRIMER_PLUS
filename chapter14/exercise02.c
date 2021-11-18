#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct month_st {
    char month_name[20];
    char month_abbr[4];
    unsigned char num_of_days;
    unsigned char order_of_the_month;
};

struct month_st non_leap_year[12] = {
    {"Janaury", "Jan", 31, 1},
    {"Febrary", "Feb", 28, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 31, 8},
    {"September", "Sep", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12},
};

struct month_st leap_year[12] = {
    {"Janaury", "Jan", 31, 1},
    {"Febrary", "Feb", 29, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 31, 8},
    {"September", "Sep", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12},
};
// The following won't work, cuz you cannot initilize an array with another array.
// struct month_st leap_year[12] = non_leap_year;
// leap_year[1].num_of_days = 29; 

int days_of_year_to_date(int, const char *, int);
int isLeapYear(const int);
void eatline(void);

int main(void)
{

    int year, day;
    char month[20];
    printf("input year: ");
    while ( scanf("%d", &year) != 1 )
    {
        eatline(); //without eatline() characters left in input queue will case infinite loop
        printf("try again, input year: ");
    }
    printf("input month: ");
    while ( scanf("%s", month) != 1 )
    {
        eatline();
        printf("try again, input month: ");
    }
    printf("input day: ");
    while ( scanf("%d", &day) != 1 )
    {
        eatline();
        printf("try again, input day: ");
    }

    printf("year-to-month days: %d\n", days_of_year_to_date(year, month, day));

    return 0;
}

int days_of_year_to_date(int year, const char * month, int day)
{
    int month_num;
    if (isdigit(*month))
    {
        char *ptr; 
        month_num = strtol(month, &ptr, 10);
    }
    else 
    {
        int i=0;
        while ( strcmp(month, non_leap_year[i].month_abbr) &&
                strcmp(month, non_leap_year[i].month_name) )
                i++;
        month_num = i+1; 
    }

    int ttl_days = 0;
    if (isLeapYear(year))
        for (int i=0; i<month_num-1; i++)
            ttl_days += leap_year[i].num_of_days;
    else
        for (int i=0; i<month_num-1; i++)
            ttl_days += non_leap_year[i].num_of_days;
    
    ttl_days += day;
        
    return ttl_days;
}

int isLeapYear(const int year)
{
    int isLeapYear = 0;
    if ( year % 400 ==0 )
        isLeapYear = 1;
    else if ( year % 100 !=0 && year % 4 == 0 )
        isLeapYear = 1;

    return isLeapYear;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}