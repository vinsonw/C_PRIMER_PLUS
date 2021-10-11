#include <stdio.h>

int main(int argc, char * argv[])
{
   int index;
   char * temp;
   for (index=1; 2*index<argc; index++) 
    {
        temp = argv[index];
        argv[index] = argv[argc-index];
        argv[argc-index] = temp;
    }
   for (index=1; index<argc; index++) 
        printf("%s ", argv[index]);
    printf("\n");
}