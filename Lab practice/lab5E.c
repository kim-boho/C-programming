
/* Passing an array to a function. */

#include <stdio.h>
#include <string.h>

#define MAX 20
 

int largest(int * x);
void display(int *arr);

 main(int argc, char *argv[])
 {
     int array[MAX], count;

     /* Input MAX values from the keyboard. */
     int i;  count=0;
     
     while ( scanf("%d", &i) != EOF){
        *(array + count) = i; // store in array[count]
        count++;
     }

      *(array + count) = -1;
      
      /* Call the function and display the return value. */
      printf("Inputs: ");
      display(array);

     
     printf("\nLargest value: %d\n", largest(array));
     
     return 0;
 }
 
 /* display a int array */

 void display(int *arr)
 {
     int i;
     for(i = 0; *(arr + i) >= 0; i++){
         printf("%d ", *(arr + i));
     }
 }


/* Function largest() returns the largest value */
 /* in an integer array */

 int largest(int * arr)
 {
     int i;
     int result = *arr;
     for(i = 1; *(arr + i) >= 0; i++){
         if(*(arr + i) > result){
             result = *(arr + i);
         }
     }
     return result;
 }

