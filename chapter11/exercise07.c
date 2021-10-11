#include <stdio.h>
char * mystrncpy(char *, const char *, int n);
int main(void)
{
    char s1[10];
    const char * s2 = "whatnowwhatnowwhatnowwhatnow";

    // variable "n" here should not be larger than 10 
    // so that it won't get out of range of array s1(allocated memoery) 
    mystrncpy(s1, s2, 10); 

    // if the length of s2 is n or more
    // then after copying, s1 won't have a proper null character at the end,
    // causing the following output weird, like:
    // ➜  chapter11 git:(main) ✗ ./e7
    // whatnowwhaZ?
    // ➜  chapter11 git:(main) ✗ ./e7
    // whatnowwhaZ1
    // ➜  chapter11 git:(main) ✗ ./e7
    // whatnowwhaZ�x
    puts(s1);

    return 0;
}

char * mystrncpy(char * s1, const char * s2, int n)
{
    int index=0;
    while ( *(s2+index) && index < n)
    {
        *(s1+index) = *(s2+index);
        index++;
    }

    // the following code is commented intentionally,
    // making "the target string may not be null-terminated 
    // if the length of s2 is n or more" come true.
    // if (index == n)
    //     *(s1+index) = '\0';

    // padding the possible extra space in s1 with '\0'
    while (index < n)
    {
        *(s1+index) = '\0';
        index++;
    }
}