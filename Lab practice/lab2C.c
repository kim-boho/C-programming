#include <stdio.h>
#include<string.h>

#define SIZE 10

int main () {

  int k[SIZE] = {0};
  int i=0;
  for (i=0; i< SIZE; i++)  
    printf("k[%d]: %d\n", i, k[i]);

  char msg[]="Hello world";
  printf("\nmsg: %s\n", msg);
  printf("memory size of msg: %d (bytes)\n", sizeof(msg));
  printf("strlen of msg: %d\n", strlen(msg));
  /* your code here to print element */
  int j;
  for(j = 0; j < sizeof(msg); j++){
    printf("msg[%d] %d %c\n", j, msg[j], msg[j]);
  }

  msg[3] = 'x';
  printf("\nmsg: %s\n", msg);
  printf("memory size of msg: %d (bytes)\n", sizeof msg);
  printf("strlen of msg: %d\n", strlen(msg));

  /**********************************/
  char msg2[2*SIZE] = "Hello world";
  printf("\nmsg2: %s\n", msg2); 
  printf("memory size of msg2: %d (bytes)\n", sizeof(msg2));
  printf("strlen of msg2: %d\n", strlen(msg2));
  /* your code here to print element */
 int l;
  for(l = 0; l < sizeof(msg2); l++){
    printf("msg2[%d] %d %c\n", l, msg2[l], msg2[l]);
  }

  msg2[3] = '\0';
  printf("\nmsg2: %s\n", msg2); // stop at first '\0'
  printf("memory size of msg2: %d (bytes)\n", sizeof(msg2));
  printf("strlen of msg2: %d\n", strlen(msg2));  // stop at first '\0'
  
  // but can still access individul elements, including those after first '\0'
  printf("%c %c %c %c %c %c\n", msg2[0], msg2[1], msg2[4], msg2[6], msg2[8], msg2[10]);

  char msg3[2*SIZE];
  printf("\nEnter a string: ");
  scanf("%s",msg3);
  printf("msg3: %s\n",msg3);
  printf("memory size of msg3: %d (bytes)\n", sizeof(msg3));
  printf("strlen of msg3: %d\n", strlen(msg3));
  int m;
  for(m = 0; m < sizeof(msg3); m++){
    printf("msg3[%d] %d %c\n", m, msg3[m], msg3[m]);
  }


  return 0;
}

