#include <stdio.h>

#define MAX_SIZE 20
#define SUCCESS 0

typedef struct {		// DO NOT CHANGE the struct definition
  int arr[MAX_SIZE];	// actual array for integers
  int size;				// number of integers in array
} Array;


/******************  YOUR CODE STARTS HERE ******************/
/************************************************************/

/* 
   Input: array A with "size" elements and an integer d
   Output: d is added to the array.
   Return 0 if the addition is successful.
   Return a negative number if the addition is unsuccessful.
   Error condition(s): fill in the error condition(s).
 */
 
int myAdd( Array *myArr, int d )
{
   /* ADD YOUR CODE HERE */
   if(myArr->size == MAX_SIZE){
     return -1;
   }

   if(myArr->size == 0){
     myArr->arr[0] = d;
     myArr->size++;
     return 0;
   }

   else{

     if(myArr->arr[myArr->size - 1] < d){
       myArr->arr[myArr->size] = d;
       myArr->size++;
       return 0;
     }

     if(myArr->arr[0] > d){
     int i;
     for(i = myArr->size; i > 0; i--){
       myArr->arr[i] = myArr->arr[i - 1];
     }
     myArr->arr[0] = d;
     myArr->size++;
     return 0;
     }

     if(myArr->arr[0] == d || myArr->arr[myArr->size - 1] == d){
       return -1;
     }

     int first = 0;
     int last = myArr->size - 1;
     int mid;
     int index;
     while(last - first > 1){
       mid = (first + last) / 2;
       if(myArr->arr[mid] > d){
         last = mid;
       }
       else if(myArr->arr[mid] < d){
         first = mid;
       }
       else{
         return -1;
       }
     }
     
     index = last;
     int i;
     for(i = myArr->size; i > index; i--){
       myArr->arr[i] = myArr->arr[i - 1];
     }
     myArr->arr[index] = d;
     myArr->size++;
     return 0;
   }
}


/* 
   Input: array A with "size" elements and an integer d
   Output: If d is found in the array, return the index of the cell containing d.
   Otherwise return a negative number if d is not found.
   Error condition(s): fill in the error condition(s).
 */
 
int search( Array *myArr, int d )
{
   /* ADD YOUR CODE HERE */
   int first = 0;
   int last = myArr->size - 1;
   int mid;
   while(first <= last){
     mid = (first + last) / 2;
     if(myArr->arr[mid] == d){
       return mid;
     }
     else if(myArr->arr[mid] > d){
       last = mid - 1;
     }
     else{
       first = mid + 1;
     }
   }
   return -1;
}

/* 
   Input: array A with "size" elements and an integer d
   Output: Return a negative number if d is not found.
   Otherwise d is removed from the array and return 0.
   Error condition(s): fill in the error condition(s).
 */

int myRemove( Array *myArr, int d )
{
   /* ADD YOUR CODE HERE */
   int found = search(myArr, d);
   if(found < 0){
     return -1;
   }
   else{
     int i;
     for(i = found; i < myArr->size - 1; i++){
       myArr->arr[i] = myArr->arr[i + 1];
     }
     myArr->arr[myArr->size - 1] = '\0';
     myArr->size--;
     return 0;
   }
   
}


/*******************  YOUR CODE ENDS HERE *******************/
/************************************************************/

/*********  DO NOT CHANGE ANYTHING BELOW THIS LINE IN THE FINAL SUBMISSION *********/

/* 
   Input: array A with "size" elements
   Output: Display the array on the standard output with one space between every two numbers. 
   Print a new line after the last element.
   If the array is empty, print "Empty array" and a new line.
 */

int printArray( Array *myArr )
{
  int i;
  if ( myArr->size == 0 )
    printf( "Empty array\n" );
  else {
  for ( i = 0; i < myArr->size; i++ )
     printf("%d ", myArr->arr[ i ] );
  printf( "\n" );
  }
  return 0;
}



/* ***** main() function ******
 */
 
int main()
{
Array myArray;
int retCode, data;
char action;

myArray.size = 0;
do {
  scanf( "%d %c", &data, &action );
  switch( action )
  {
    case 'a': /* add */
    case  'A':
      retCode = myAdd( &myArray, data );
      if ( retCode == SUCCESS ) {
        printArray( &myArray ); 
      }
      else
        printf( "Failed to add %d.\n", data );  
      break; 
        
    case 'r': /* remove */
    case 'R':
      retCode = myRemove( &myArray, data );
      if ( retCode == SUCCESS ) {
        printArray( &myArray ); 
      }
      else
        printf( "Failed to remove %d.\n", data );    
      break;  
                    
    case 's': /* search */
    case 'S':
      retCode = search( &myArray, data );
      if( retCode >= 0 )
        printf( "Found %d at index %d.\n", data, retCode );
      else 
        printf( "Not found %d.\n", data );        
      break;
      
    case 'q':  /* quit */
    case 'Q':
      /* do nothing but exit the switch statement */
      break; 
    
    default:
      printf( "Invalid operation %c\n", action );  
  }
} while ( action != 'q' && action != 'Q' );

return 0; 
} // end main
