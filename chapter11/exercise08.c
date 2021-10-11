#include <stdio.h>

const char * string_in(const char *, const char *);
void display_match_result(const char *, const char *); 

int main(void)
{
    char  s1[100];
    char  s2[10];

    while (1)
    {
        printf("please type in two strings:\n");
        scanf("%s %s", s1, s2);
        display_match_result(s1, s2);

        while (getchar() != '\n')
            continue; 

        printf("Do you want to do it again?(type 'y' to continue, 'q' to quit)\n");
        if ( getchar() != 'y' )
            break;

    }

    return 0;
}

const char * string_in(const char * s1, const char * s2)
{
    int index=0;
    int isIn=0;
    while ( *(s1+index) )
    {
        int cursor=0;
        int backup_index = index;
        while ( *(s1+index) == *(s2+cursor) )
        {
            index++;
            cursor++;
        }

        if (*(s2+cursor) == '\0')
            return s1+backup_index;
        
        // without this updating of variable "index"
        // the while loop will go on forever
        index = backup_index + 1;

    }

    return NULL;
    
}

void display_match_result(const char * s1, const char * s2)
{

   const char * s;
    //    printf("i am here.\n");
   if ( s = string_in(s1, s2) )
        printf("alright, \"%s\" shows up at %ld(ordinal) location and"
        " the following is \"%s\"\n",
        s2, s-s1+1, s);
    else
        printf("No match for \"%s\" in \"%s\" .\n", s2, s1);
} 