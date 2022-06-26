#include <stdio.h>

float sum(float, float);

int main()
{
  float a,b;
  printf("Enter two float numbers separated by ##: ");
  scanf("%f##%f", &a, &b);
  printf("%.6f + %.6f = %.6f\n", a, b, sum(a, b));


}

/* function definition */
float sum (float i, float j){
   return i+j;             
}
