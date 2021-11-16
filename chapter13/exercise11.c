#include <stdio.h>
#include <string.h>
#define SLEN 255

int main(int argc, char *argv[])
{
   FILE *fp; 

   for (int i=2; i<argc; i++)
   {
       if ( (fp=fopen(argv[i], "r")) == NULL )
       {
           fprintf(stderr, "Guess what! %s couldn't be opened!", argv[i]);
           continue;
       }
       
       char this_line[SLEN];
       while ( fgets(this_line, SLEN, fp ) )
           if ( strstr(this_line, argv[1]) )
               printf(this_line);

       fclose(fp);

   }
}
