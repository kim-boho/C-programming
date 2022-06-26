
#include <stdio.h>

void r_avg(int);

int main(int argc, char *argv[])
{
	
   int input;  
   printf("Enter number (-1 to quit): ");
   scanf("%d", &input);

   while (input != -1){
        r_avg(input);

        printf("\Enter number (-1 to quit): ");
        scanf("%d", &input);
    }
	
    return 0;
}

void r_avg(int input)
{
    static int count = 0;
    count++;
    static int sum = 0;
    sum += input;
    double resu = ((double) sum) / ((double) count);
    printf("running average is %d / %d = %.3f\n\n", sum, count, resu);     
}
