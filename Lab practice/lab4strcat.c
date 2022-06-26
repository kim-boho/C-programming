
#include<stdio.h>
#include<string.h>

#define SIZE 30

void my_strcat(char[], char[]);
int main(){
   char a[SIZE];
   char b[SIZE];
   char c[SIZE];
   char d[SIZE];

   scanf("%s",a);
   scanf("%s",b);
   while (strcmp(a,"xxx") || strcmp(b,"xxx")){
    
      strcpy(c,a); strcpy(d,b);

      strcat(a,b);
      my_strcat(c,d);
      
      printf("strcat:   %s\n", a); 
      printf("mystrcat: %s\n\n", c);

      scanf("%s",a);
      scanf("%s",b);
   }
}


void my_strcat(char a[], char b[]){
   int leng = strlen(a);
   int leng2 = strlen(b);
   int i;
   for(i = leng; i < leng + leng2; i++){
      a[i] = b[i - leng];
   }
   a[i] = '\0';
}
