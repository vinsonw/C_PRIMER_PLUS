#include <stdio.h>

int main(void)
{
   float cups;
   printf("how much is the volume(in cups)?\n") ;
   scanf("%f", &cups);
   printf("okay, that's:\n");
   printf("%0.2f pints\n", cups / 2);
   printf("%0.2f ounces\n", cups * 8);
   printf("%0.2f tablespoons\n", cups * 2 * 2);
   printf("%0.2f teaspoons\n", cups * 2 * 2 *3);
   
   return 0;

}