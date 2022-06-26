
#include <stdio.h>


void r_avg(int, int);


int main(int argc, char *argv[])
{
	
      int input; int count=0; int sum=0;
      // double resu;

      printf("Enter number (-1 to quit):  ");
      scanf("%d", &input);

      while(input != -1)
      {
         sum += input;
         count++;

          r_avg(sum, count);

          /* read again */
          printf("Enter number (-1 to quit):  ");
          scanf("%d", &input);
       }  
	
       return 0;
}

void r_avg(int sum, int count)
{
   double resu = ((double) sum) / ((double) count); 
   printf("running average is %d / %d = %.3f\n\n", sum, count, resu);   
}
