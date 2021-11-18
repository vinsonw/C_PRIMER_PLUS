#include <stdio.h>
#include <string.h>

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
    {"December", "Dec", 31, 12}
};

int days_of_year_to_date(const char * s)
{
    int month_index = 0;
    while ( strcmp(s, non_leap_year[month_index].month_name) )
        month_index++;

    int ttl_days = 0;
    for (int i=0; i<month_index+1; i++) 
        ttl_days += non_leap_year[i].num_of_days;

    return ttl_days;
}