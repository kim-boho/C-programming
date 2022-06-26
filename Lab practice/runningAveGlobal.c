
#include <stdio.h>
int sum;
int count;
extern void r_avg();

int main(int argc, char *argv[])
{
    int input;

    printf("Enter number (-1 to quit): ");
    scanf("%d", &input);
    
    while(input != -1){
      sum += input;
      count++;
      r_avg();

      // read again
    printf("Enter number (-1 to quit): ");
    scanf("%d", &input);
     }
	 
     return 0;
}

