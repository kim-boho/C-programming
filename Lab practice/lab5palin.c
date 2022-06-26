
#include <stdio.h>
#include <string.h>

#define SIZE 40

void printReverse (char *);
int isPalindrome (char *);

int main ()
{   
   int result;  char c; int i;  int count=0;
   char arr[SIZE];
  
   fgets(arr,SIZE,stdin);
   while (strcmp(arr, "quit\n\0"))
   {
      arr[strlen(arr)-1] = '\0'; // remove the trailing \n
      // print backward
      printReverse(arr);
      printf("%s", arr);
   
      if (isPalindrome (arr)) 
         printf ("\nIs a palindrome.\n\n");
      else 
         printf ("\nNot a palindrome.\n\n");
 
      fgets(arr,SIZE,stdin);
    }
    return 0;
}


// assume the \n was already removed manually
int isPalindrome (char * str)
{
   int i;
   for(i = 0; *(str + i) != '\0'; i++);
   int length = i;
   int j;
   for(j = 0; j < (length / 2); j++){
      if(*(str + j) != *(str + i - 1 - j)){
         return 0;
      }
   }
   return 1;
}

// assume the \n was already removed manually
void printReverse(char * str)
{
   static int n = 0;
   int i;
   for(i = 0; *(str + i) != '\0'; i++);
   int length = i;
   if(n == i || n == i - 1){
      n = 0;
      return;
   }
   char temp = *str;
   *str = *(str + i - 1 - n);
   *(str + i - 1 - n) = temp;
   n++;
   printReverse(str + 1);
}

