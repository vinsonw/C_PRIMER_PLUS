#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char * argv[])
{
    char ch;
    if ( argc == 1 || strcmp(argv[1],"-p")==0 )
        while ( (ch=getchar()) != EOF )
            putchar(ch);
    if ( strcmp(argv[1],"-u" )==0 )
        while ( (ch=getchar()) != EOF )
            putchar(toupper(ch));
    if ( strcmp(argv[1],"-l" )==0 )
        while ( (ch=getchar()) != EOF )
            putchar(tolower(ch));
    
    return 0;
}