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
   if(size >= MAX_SIZE) {
     return -1;
   } //If arrays size is maximum, return -1.
   
   else{
     A[size] = d;
     return 0;
   } //Add integer d as the last element.
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
   int i;
   for(i = 0; i < size; i++){
     if(A[i] == d){
       return i;
     } // If integer d is searched in the array, return its index number.
   }
   return -1; //After for loop is finished, if integer is not found in the array, return -1.
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
     A[index] = A[size - 1];
     A[size - 1] = '\0';
     return 0;
   } // Replace the number in index by the last element of array.
     // And, last element is replaced by '\0'.

   else{
     return -1;
   } // If index is -1, return -1, either.
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
