
#include <stdio.h>
#include <math.h>

double my_pow(double, double);
int main(int argc, char *argv[])
{
	
   double base; 
   int exponent;  
   printf("enter base and power: ");
   scanf("%lf %d", &base, &exponent);

   while (base != -100){
        double res = pow(base, exponent);
        double res2 = my_pow(base, exponent);
        printf("pow:    %.4f\n", res);
        printf("my_pow: %.4f\n", res2);

        printf("\nenter base and power: ");
        scanf("%lf %d", &base, &exponent);
    }
	
    return 0;
}

// this function should be RECURSIVE
// should not use any loop here
double my_pow(double base, double power)
{
     if(power == 0){
          return 1;
     }
     else{
          if(power > 0){
               return my_pow(base, power - 1) * base;
          }
          else{
               return my_pow(base, power + 1) / base;
          }
     }
}
