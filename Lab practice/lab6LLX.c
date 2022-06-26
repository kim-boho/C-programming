
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 50
#define MAX_LEN 30

struct integers
{
  int int1;
  int int2;
};

struct node {  // list 'node' struct
   char data;
   struct node *next;
};


void init( );
void display();
int len();
//int search(char); removed this term
char get(int);
void insert(char d );
void insertAfter(char key, int index);
void delete (char d);


struct node * head;   // global variable, the head of the linkedlist

int main()
{
    int i, index; char key;

    struct integers arr[MAX_LEN]; // an array of ten structs

    char buffer[BUFFER_SIZE];
    int value1, value2;
    int count= 0;

    FILE * file;
    file = fopen("data.txt", "r");

    while (fgets(buffer, BUFFER_SIZE, file) != NULL)     // or  while (fscanf(file, "%d %d", &value1, &value2) == 2)
    {
       sscanf(buffer, "%d %d", &value1, &value2);   // tokenize buffer and store into value1 and value2

       arr[count].int1 = value1;
       arr[count].int2 = value2;
       count++;
    }

    fclose(file);

    /* print the array of structures */
    for(i=0; i< count; i++){
        printf("arr[%d]: %d %d\n", i, arr[i].int1, arr[i].int2);
    }

    // now building up the list by reading from the array of structures
    printf("\n");
    init();

    i=0;
    for(; i< count; i++){
       // read two ints from each structure in the array, sum up and added into the list
       char sum = arr[i].int1 + arr[i].int2;
        insert(sum); 
        printf("insert %c: (%d)", sum, len());
        display();
    }
    // no more coding in main()
    char removeList [] = {'B','S','A','O','R','K','Y','U','L','\0'}; // \0 is the terminating token
    i=0;
    while ( (key=removeList[i]) != '\0'){
        delete(key);
        printf("remove %c: (%d)", key, len()); display();
        i++;
    }

    // insert again
    char addList [] = "YORKULABS"; 
    i=0;
    while ( (key=addList[i]) != '\0'){ 
        insert(key);
        printf("insert %c: (%d)", key, len());
        display();
        i++;
    }

    int v = get(0);  printf("\nget(0): %c\n", v);
    v = get(3);  printf("get(3): %c\n", v);
    v = get(6);  printf("get(6): %c\n", v);
    v = get(7);  printf("get(7): %c\n", v);
    v = get(8);  printf("get(8): %c\n", v);

    key ='x'; index =2; insertAfter(key,index);
    printf("\ninsert %c after index %d: (%d)\t", key,index,len()); display();
    key ='y'; index = 0; insertAfter(key,index);
    printf("insert %c after index %d: (%d)\t", key,index,len()); display();
    key ='z'; index = 6;insertAfter(key,index);
    printf("insert %c after index %d: (%d)\t", key,index,len()); display();

    v = get(0);  printf("\nget(0): %c\n", v);
    v = get(3);  printf("get(3): %c\n", v);
    v = get(6);  printf("get(6): %c\n", v);
    v = get(7);  printf("get(7): %c\n", v);
    v = get(8);  printf("get(8): %c\n\n", v);


}

/* Initialize the list. */
void init( )
{
    head = NULL;
}



/* Print the content of the list. */
void display()
{
    struct node *current = head;
    while (current != NULL){
       printf( "%3c", current->data );
       current = current -> next;
    }printf( "\n" );

}

/* return the length of the linked list */
int len()
{
    struct node *current = head;
    int counter = 0;
    while(current != NULL){
        counter++;
        current = current->next;
    }
    return counter;
}


char get(int index){
    struct node *current = head;
    int count = 0;
    while(count != index){
        current = current->next;
        count++;
    }
    return current->data;
}


/* Insert a new data element with key d into the end of the list. */
/* Hint: You need to consider the special case that the list is empty,
   and the general case that the list is not empty */
void insert(char d)  //  at the end
{
   if (head == NULL){/* the list is empty */
   struct node *current;
   current = malloc(sizeof(struct node));
   current->data = d;
   current->next = NULL;
   head = current;
   }
   else{  // general case, insert at the end.
   struct node *current;
   current = head;
   while(current->next != NULL){
       current = current->next;
   }
   struct node *new = malloc(sizeof(struct node));
   new->data = d;
   new->next = NULL;
   current->next = new;
   }
}

/* insert in the middle.
  insert new node with data d, after the node of index 'index'
  assume the list is not empty, and index is in [0, len()-1]
 */
void insertAfter(char d, int index)
{
    struct node *current = head;
    int i;
    for(i = 0; i < index; i++){
        current = current->next;
    }
    struct node *new = malloc(sizeof(struct node));
    new->data = d;
    new->next = current->next;
    current->next = new;
}
    
/* lab version */
/* Remove the node with value d from the list */
/* assume the list is not empty  */
/* assume the node to be deleted is in the list */
/* assume no duplicated keys in the list */
/* You don't have to free the space */
void delete(char d)
{
  
   /* special case: to be removed is the first, need to change head  */
   if (head -> data == d){
        head = head->next;
   }
   
   else  // general case, remove from the middle or the last
   {
     struct node *current = head;
     while(current->next != NULL){
         if((current->next)->data == d){
             current->next = (current->next)->next;
             return;
         }
         current = current->next;
     }
   }
}



