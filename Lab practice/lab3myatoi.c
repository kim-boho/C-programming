
#include <stdio.h>
#include <string.h>

#define SIZE 10
int my_atoi(char[]);
int atoi(char[]);
int power(int, int);

int main(){
  int a,b;
  char arr [SIZE];

  printf("Enter a word of postive number or 'quit': " );
  scanf("%s", arr);
  char quit[5] = "quit";
  while(strcmp(quit,arr) != 0)
  {
    printf("%s\n", arr);

    a = atoi(arr);
    printf("atoi:    %d (%#o, %#X)\t%d\t%d\n", a,a,a, a*2, a*a);

    b = my_atoi(arr);
    printf("my_atoi: %d (%#o, %#X)\t%d\t%d\n", b,b,b, b*2, b*b);

   printf("\nEnter a word of postive number or 'quit': " );
   scanf("%s", arr);
  }

  return 0;

}

/* convert an array of digit characters into a decimal int */

/* textbook did scan from left to right.
 Here you should scan from right to left. This is a little complicated 
 but more straightforward (IMHO) */

int my_atoi (char c[]){
  if(c[1] == 'X' || c[1] == 'x'){
    int index = strlen(c) - 1;
    int i;
    int result = 0;
    for(i = 0; i <= index - 2; i++){
      if(c[index - i] >= 'A' && c[index - i] <= 'F'){
        result = result + (c[index - i] - 55) * power(16,i);
      }
      else if(c[index - i] >= 'a' && c[index - i] <= 'f'){
        result = result + (c[index - i] - 87) * power(16,i);
      }
      else{
        result = result + (c[index - i] - '0') * power(16,i);
      }
    }
    return result;
  }
  else{
    int index = strlen(c) - 1;
    int i;
    int result = 0;
    for(i = 0; i <= index; i++){
      result = result + (c[index - i] - '0') * power(10,i);
    }
    return result;
  }
}

int power(int base, int n){
  int i;
  int result = 1;
  for(i = 0; i < n; i++){
    result = result * base;
  }
  return result;
}

int atoi(char c[]){
  int i, n;
  n = 0;
  for(i = 0; c[i] >= '0' && c[i] <= '9'; i++){
    n = 10 * n + (c[i] - '0');
  }
  return n;
}
