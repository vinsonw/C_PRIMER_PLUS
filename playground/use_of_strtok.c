#include <string.h>
#include <stdio.h>

int main(void)
{
    char date[] = "2021/11/21";
    const char *token;
    char s[2] = "/";
    token = strtok(date, s);
    while ( token )
    {
        printf("%s\n", token);
        token = strtok(NULL, s);
    }
    printf("after:\n");
    printf("%s\n", date);

    return 0;
}