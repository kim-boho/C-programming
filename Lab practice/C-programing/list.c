#include <stdio.h>
#include <stdlib.h>
#include "list.h"


List *head, *tail;


/* Display an error message. */

void prtError( char *errMsg )
{
   printf( "%s \n", errMsg );
}


/* Create an empty list. */
/* Create a dummy node to simplify insertion and deletion. */
/* After the list is created, pointers head and tail both point to the dummy node. */
/* Return NULL if a node cannot be created. */
/* Otherwise, return the pointer to the dummy node. */

List *init( )
{
   head = ( List * ) malloc( sizeof( List ) );
   if ( head == NULL ) {
      prtError( "Insufficient memory!" );
      return( NULL );
   }
   head->data = -1;
   head->next = NULL;
   tail = head;
   return ( head );
}


/* Return the content (data) of the first element right behind the dummy node. */
/* Return -1 if the list is empty. */

int getFirst()
{
   if ( head != tail )	// non-empty list
      return( head->next->data );
   else					// empty list
      return -1;
}


/* Return the content (data) of the last element at the rear of the list. */
/* Return -1 if the list is empty. */

int getLast()
{
   if ( head != tail )	// non-empty list
      return( tail->data );
   else					// empty list
      return -1;
}


/* Print the content of the list (ignoring the dummy node). */

void prtList( )
{
   List *p;
   for ( p = head->next; p != NULL; p = p->next )
        printf( "%4d", p->data );
   printf( "\n");
}



/************* DO NOT MODIFY ANYTHING ABOVE THIS LINE, *************/
/************* EXCEPT THE HEADER CONTAINING YOUR INFO **************/

/* Insert a new data element d into the list. */
/* Insert at the front of the list, right behind the dummy node. */
/* Return NULL if a new node cannot be created. */
/* Otherwise, return the pointer to the newly created node. */

List *insertFirst( int d )
{

   /***** ADD YOUR CODE HERE *****/
   List *new = malloc(sizeof(List));
   if(new == NULL){
      prtError("Memory allocation was failed");
      return NULL;
   }
   else{
      new->data = d;
      new->next = head->next;
      head->next = new;
      if(new->next == NULL){
         tail = new;
      }
      return new;
   }
}



/* Insert a new data element d into the list. */
/* Insert at the end of the list. */
/* Return NULL if a new node cannot be created. */
/* Otherwise, return the pointer to the newly created node. */

List *insertLast( int d )
{

   /***** ADD YOUR CODE HERE *****/
   List *new = malloc(sizeof(List));
   if(new == NULL){
      prtError("Memory allocation was failed");
      return NULL;
   }
   else{
      new->data = d;
      new->next = NULL;
      tail->next = new;
      tail = new;
      return new;
   }
}



/* Remove the first element of the list, i.e., the node right behind the dummy node. */
/* Return -1 if the list is empty, i.e., containing only the dummy node, */
/* and display error message "Empty list!" on the standard output. */
/* Otherwise, return the data (integer) of the node to be remove. */

int removeFirst()
{

   /***** ADD YOUR CODE HERE *****/
   if(head->next == NULL){
      prtError("Empty list!");
      return -1; 
   }
   else{
      List *current = head->next;
      int removed = current->data;
      head->next = current->next;
      if(head->next == NULL){
         tail = head;
      }
      free(current);
      return removed;
   }
}


/* Search the list for an element containing integer k. */
/* If found, return the pointer to that element.  Otherwise, return NULL. */
/* If there is more than one element containing k, return the pointer to the first encountered element. */

List *search( int k )
{

   /***** ADD YOUR CODE HERE *****/
   List *current = head;
   while(current->next != NULL){
      if(current->data == k){
         return current;
      }
      current = current -> next;
   }
   return NULL;
}


/*************************** END OF FILE ***************************/

