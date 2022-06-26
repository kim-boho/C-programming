
#include <stdio.h>
#include <stdlib.h>

void insertBegining(int);

struct node { 
   int data;
   struct node * next;
};

struct node * head; 

main()
{
   head = NULL;

   insertBegining(100);
   insertBegining(200);
   insertBegining(300);
   insertBegining(400);   
   insertBegining(500);

   int i; 
   struct node * cur;
   for(cur= head; cur != NULL; cur= cur->next)
     printf("%d ", cur->data);
   printf("\n");  
}   

void insertBegining(int dat){
   struct node *newNode;
   newNode = malloc(sizeof(struct node));
   (*newNode).data = dat;

   (*newNode).next = head;
   
   head = newNode;

}

/* In lab6LL1.c, the function insertBegining is using local variable.
Local variable can not be kept after the function ends because
it is saved in stack, not heap.
So, since newNode which head is pointing disappears in main function,
it was the problem.*/
