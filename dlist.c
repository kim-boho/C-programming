#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

/* Two dummy nodes that keeps track of the front and the rear of the list */

DList *head, *tail;

/* Display an error message. */

void prtError( char *errMsg )
{
   printf( "%s \n", errMsg );
}


/* Create an empty list. */
/* Create two dummy nodes to simplify insertion and deletion. */
/* After the list is created, pointers head and tail both point to the 2 dummy nodes. */
/* Return NULL if a node cannot be created. */
/* Otherwise, return the pointer to the dummy node "head". */

DList *init( )
{
   head = ( DList * ) malloc( sizeof( DList ) );
   if ( head == NULL ) {
      prtError( "Insufficient memory!" );
      return( NULL );
   }
   
   tail = ( DList * ) malloc( sizeof( DList ) );
   if ( tail == NULL ) {
      prtError( "Insufficient memory!" );
      return( NULL );
   } 
     
   head->data = -1;
   tail->data = -1;   
   head->next = tail;
   head->prev = NULL;  
   tail->next = NULL; 
   tail->prev = head;
   return ( head );  /* indicates no error */ 
}


/* Return the content (data) of the first element right behind the dummy node. */
/* Return -1 if the list is empty. */

int getFirst()
{
   if ( head->next != tail )	// non-empty list
      return( head->next->data );
   else							// empty list
      return -1;
}


/* Return the content (data) of the last element right in front of dummy node "tail" */
/* Return -1 if the list is empty. */

int getLast()
{
   if ( head->next != tail )	// non-empty list
      return( tail->prev->data );
   else							// empty list
      return -1;
}


/* Print the content of the list (ignoring the dummy node). */

void prtList( )
{
   DList *p;
   for ( p = head->next; p != tail; p = p->next )
        printf( "%4d", p->data );
   printf( "\n");
}



/************* DO NOT MODIFY ANYTHING ABOVE THIS LINE, *************/
/************* EXCEPT THE HEADER CONTAINING YOUR INFO **************/

/* Insert a new data element d into the list. */
/* Insert at the front of the list, right behind the dummy node "head". */
/* Return NULL if a new node cannot be created. */
/* Otherwise, return the pointer to the newly created node. */

DList *insertFirst( int d )
{
   			  	
   /***** ADD YOUR CODE HERE *****/
   DList *new = malloc(sizeof(DList));
   if(new == NULL){
      prtError("Memory allocation was failed");
      return NULL;
   }
   else{
      new->data = d;
      new->next = head->next;
      new->prev = head;
      head->next = new;
      (new->next)->prev = new;
      return new;
   }
}



/* Insert a new data element d into the list. */
/* Insert at the rear of the list, right in front of the dummy node "tail". */
/* Return NULL if a new node cannot be created. */
/* Otherwise, return the pointer to the newly created node. */

DList *insertLast( int d )
{
   			     
   /***** ADD YOUR CODE HERE *****/
      DList *new = malloc(sizeof(DList));
   if( new == NULL){
      prtError("Memory allocation was failed");
      return NULL;
   }
   else{
      new->data = d;
      new->prev = tail->prev;
      new->next = tail;
      tail->prev = new;
      (new->prev)->next = new;
      return new;
   }
}



/* Remove the first element of the list, the node right behind the dummy node "head". */
/* Return -1 if the list is empty, i.e., containing only the two dummy nodes, */
/* and display error message "Empty list!" on the standard output. */
/* Otherwise, return the data (integer) of the node to be removed. */

int removeFirst()
{

   /***** ADD YOUR CODE HERE *****/
   if(head->next == tail){
      prtError("Empty list!");
      return -1; 
   }
   else{
      DList *current = head->next;
      int removed = current->data;
      head->next = current->next;
      (current->next)->prev = current->prev;
      free(current);
      return removed;
   }
}


/* Remove the last element,  the node right in fromt of the dummy node "tail". */
/* Return -1 if the list is empty, i.e., containing only the two dummy nodes, */
/* and display error message "Empty list!" on the standard output. */
/* Otherwise, return the data (integer) of the node to be removed. */

int removeLast()
{
    
   /***** ADD YOUR CODE HERE *****/
   if(tail->prev == head){
      prtError("Empty list!");
      return -1;
      }
   else{
      DList *current = tail->prev;
      int removed = current->data;
      tail->prev = current->prev;
      (current->prev)->next = current->next;
      free(current);
      return removed;
      }
}


/* Search the list for an element containing integer k. */
/* If found, return the pointer to that element.  Otherwise, return NULL. */
/* If there is more than one element containing k, return the pointer to the first encountered element. */

DList *search( int k )
{
   
   /***** ADD YOUR CODE HERE *****/
     DList *current = head->next;
   while(current->next != tail){
      if(current->data == k){
         return current;
      }
      current = current -> next;
   }
   if(current->data == k){
      return current;
   }
   return NULL;
}


/*************************** END OF FILE ***************************/
