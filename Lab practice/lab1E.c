#include <stdio.h>

float sum(float, float);

int main()
{
  int c;
  printf("Enter the number of interactions: ");
  scanf("%d", &c);

  int i;

  for(i = 0; i < c; i++){
  float a,b;
  printf("\nEnter two float numbers separated by ##: ");
  scanf("%f##%f", &a, &b);
  printf("%f + %f = %f (%.2f)", a, b, sum(a, b), sum(a, b));
  printf("\n");
  }
}

/* function definition */
float sum (float i, float j){
   return i+j;             
}
