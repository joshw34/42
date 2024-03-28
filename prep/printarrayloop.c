#include <stdio.h>

int main()
{
   double prices[] = {5.0, 10.0, 15.0, 25.0, 20.0, 30.0};
   
   /* Shows the size of the array in bytes */
   //printf("%d bytes\n", sizeof(prices));

   /* # of values in array = size of array / size of 1 value  (float = 8bytes) */
   for(int i = 0; i < sizeof(prices)/sizeof(prices[0]); i++)
   {
      printf("$%.2lf\n", prices[i]);
   }

   return 0;
}
