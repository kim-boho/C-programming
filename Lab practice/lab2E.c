#include <stdio.h>

#define MAX_SIZE 21
int length(char[]);
int indexOf(char[], char);
int occurrence(char[], char);
int isQuit(char[]);

int main() {

   char word[MAX_SIZE];
   char c;

   char helloArr[]  = "helloWorld";
   printf("\"%s\" contains %d characters, but the size is %lu (bytes)\n", helloArr, length(helloArr), sizeof(helloArr));
   helloArr[5] = '\0'; helloArr[3]='X'; helloArr[7] ='Y';
   printf("\"%s\" contains %d characters, but the size is %lu (bytes)\n\n", helloArr, length(helloArr), sizeof(helloArr));


   /********** Fill in your code here. **********/
   printf("Enter a word and a character separated by blank: ");
   scanf("%s %c", word, &c);

   while (isQuit(word) == 0)   
   {
      printf("Input word is \"%s\". Contains %d characters\n", word, length(word));
      printf("\'%c\' appears %d times in the word\n", c, occurrence(word, c));
      printf("Index of \'%c\' in the word is %d\n\n", c, indexOf(word, c));
      printf("Enter a word and a character separated by blank: ");
      scanf("%s %c", word, &c);

   }

   return 0;
}

int length(char arr[])
{
   int count = 0;
   while(arr[count] != '\0'){
      count++;
   }
   return count;
}

int indexOf(char arr[], char c)
{
 int index = 0;
 while(index < length(arr)){
    if(arr[index] == c){
       return index;
    }
    index++;
 }
 return -1;
}

int occurrence(char arr[], char c)
{
   int count = 0;
   int i;
   for(i = 0; i < length(arr); i++){
      if(arr[i] == c){
         count++;
      }
   }
   return count;
}

int isQuit (char arr[])
{
 if (arr[0]=='q' && arr[1]=='u' && arr[2]=='i' && arr[3]=='t')
    return 1; 
 else 
    return 0;
}
