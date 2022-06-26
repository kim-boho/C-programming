
#include <stdio.h>

#define MAX_SIZE 20
#define SUCCESS 0

/******************  YOUR CODE STARTS HERE ******************/
/************************************************************/
/* 
   Input: array A with "size" elements and an integer d
   Output: d is added to the array.
   Return 0 if the addition is successful.
   Return a negative number if the addition is unsuccessful.
   Error condition(s): fill in the error condition(s).
 */
 
int myAdd( int A[], int size, int d )
{
   /* ADD YOUR CODE HERE */
   int index;
   // Index for integer d.

   if(size >= 20){
     return -1;
   } // If array's size is maximum, return -1.

   else if(size == 0){
     A[0] = d;
     return 0;
   } // If array is empty, just add integer d as a first element.

   else if(A[0] > d){
     index = 0;
   } // If array's first element is larger than integer d, d should put as a first element.
     // So, index is 0.

   else if(A[size - 1] < d){
     A[size] = d;
     return 0;
   } // If array's last element is smaller than integer d, d should put as a last element.
     // In this case, we don't have elements behind integer d. So, add d and return 0. 

   else{
     int mid = size / 2;
     if(A[mid] > d){
       int i;
       for(i = 0; i < mid; i++){
         if(A[i] < d && A[i + 1] > d){
           index = i + 1;
         }
       }
     }
     else{
       int i;
       for(i = mid; i < size; i++){
         if(A[i] < d && A[i + 1] > d){
           index = i + 1;
         }
       }
     }
     int i;
     for(i = 0; i < size - 1; i++){
       if(A[i] < d && A[i + 1] > d){
         index = i + 1;
       }
     }
   } // Compare middle element to integer d.
     // If d is larger than middle element, search the second half array.
     // Otherwise, search the first half array.

   int i;
   for(i = size; i > index; i--){
     A[i] = A[i - 1];
   } // From the last element, push array's element back to the next index
     // until the number in index that we found is copied in the next index.
   A[index] = d; // Put integer d in the index that we found.
   return 0; // Since adding is completed, return 0.
}


/* 
   Input: array A with "size" elements and an integer d
   Output: If d is found in the array, return the index of the cell containing d.
   Otherwise return a negative number if d is not found.
   Error condition(s): fill in the error condition(s).
 */
 
int search( int A[], int size, int d )
{
   /* ADD YOUR CODE HERE */
   int first = 0;
   int last = size - 1;
   int mid;
   // Integer first means the first index of array that we have to check to find integer d.
   // Integer last menas the last index of array that we have to check to find integer d.

   while(first <= last){
     mid = (first + last) / 2;
     // Integer mid means middle index of array that we have to chekc to find integer d.

     if(A[mid] == d){
       return mid;
     }
     else if(A[mid] > d){
       last = mid - 1;
     }
     else{
       first = mid + 1;
     }
   } // Check middle element of the array until it is equal to integer d.
     // If it's not and the middle point is larger than integer d, set integer last = mid - 1
     //  because we need to check only the first half of the array in the next loop. 
     // If it's not and the middle point is smaller than integer d, set integer first = mid + 1
     //  because we need to check only the second half of the array in the next loop.
     // When we find the same element in array, return its index.

   return -1;
   // After loop, if we couldn't find the same element, return -1.
}

/* 
   Input: array A with "size" elements and an integer d
   Output: Return a negative number if d is not found.
   Otherwise d is removed from the array and return 0.
   Error condition(s): fill in the error condition(s).
 */

int myRemove( int A[], int size, int d )
{
   /* ADD YOUR CODE HERE */
   int index = search(A,size,d);
     // Using search fucntion, determine if integer d is in the array or not.
     // If integer d is in array, return its index number. If not, returns -1.

   if(index != -1){
     int i;
     for(i = index; i < size - 1; i++){
       A[i] = A[i + 1];
     }
     A[size - 1] = '\0';
     return 0;
   } // If index is not -1, it means integer d is in array.
     // From the index, pull elements to previous index to remove the element in int index.
     // And set '\0' as the last element.

   else{
     return -1;
   }// If integer index is -1, it means integer d is not in array.
    // Therefore, eturn -1.
}


/*******************  YOUR CODE ENDS HERE *******************/
/************************************************************/

/*********  DO NOT CHANGE ANYTHING BELOW THIS LINE IN THE FINAL SUBMISSION *********/

/* 
   Input: array A with "size" elements
   Output: Display the array on the standard output with one space between every two numbers. 
   Print a new line after the last element.
   If the array is empty, print "Empty array" and a new line.
   Error condition(s): fill in the error condition(s).
 */

int printArray( int A[], int size )
{
  int i;
  if ( size == 0 )
    printf( "Empty array\n" );
  else {
  for ( i = 0; i < size; i++ )
     printf("%d ", A[ i ] );
  printf( "\n" );
  }
  return 0;
}

/* main() function 
 */
int main()
{
int myArray[MAX_SIZE];
int retCode, data, size;
char action;

size = 0;
do {
  scanf( "%d %c", &data, &action );
  switch( action )
  {
    case 'a': /* add */
    case  'A':
      retCode = myAdd( myArray, size, data );
      if ( retCode == SUCCESS ) {
        size++;		// increment size after successful addition
        printArray( myArray, size ); 
      }
      else
        printf( "Failed to add %d.\n", data );  
      break; 
        
    case 'r': /* remove */
    case 'R':
      retCode = myRemove( myArray, size, data );
      if ( retCode == SUCCESS ) {
        size--;		// decrement size after successful removal
        printArray( myArray, size ); 
      }
      else
        printf( "Failed to remove %d.\n", data );    
      break;  
                    
    case 's': /* search */
    case 'S':
      retCode = search( myArray, size, data );
      if( retCode >= 0 )
        printf( "Found %d at index %d.\n", data, retCode );
      else 
        printf( "Not found %d.\n", data );        
      break;
      
    case 'q':  /* quit */
    case 'Q':
      /* To quit, enter an arbitrary integer and character (action) 'q' or 'Q'.
         This is not elegant but makes the code simpler.  */  
      /* Do nothing but exit the switch statement */
      break; 
    
    default:
      printf( "Invalid operation %c\n", action );  
  }
} while ( action != 'q' && action != 'Q' );

return 0; 
} // end main
