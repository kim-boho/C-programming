
#include <stdio.h>
#include <string.h>
#include <math.h>

#define SIZE 10
#define SIZE2 40

int main(int argc, char *argv[])
{
     char resu[SIZE2];
     char input[SIZE2];    
     char name[SIZE];  
     int age;
     float rate;
	
     printf("Enter name, age and rate (or \"exit\"): ");
     fgets(input, 40, stdin);
     while (strcmp(input,"exit\n"))
     {    
       //output original input using two functions.
       printf("%s", input);  // no \n needed
       fputs(input, stdout); 
      
       sscanf(input, "%s %d %f", name, &age, &rate);
       
       if(name[0] >= 'a' && name[0] <= 'z'){
         name[0] -= 32;
       }

       age += 10;
       rate = rate * 2;
       int flo = floor(rate);
       int cei = ceil(rate);

       sprintf(resu, "%s-%d-%.3f-[%d,%d]\n\n", name, age, rate, flo, cei);
       fputs(resu, stdout);

       /* use fgets to read again */
       printf("Enter name, age and rate (or \"exit\"): ");
       fgets(input, 40, stdin);

     } 
      return 0;
}
