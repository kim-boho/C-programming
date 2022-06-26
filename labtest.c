
#include <stdio.h>
//more header files and declarations as needed
#include <string.h>
#include <math.h>

#define ROWs 30
#define COLs 50


int main(int argc, char *argv[])
{
     char table[ROWs][COLs];  /* 2D array to store lines of input */
        
     int count = 0;
     char word1[20];
     char letter;
     float rate;
     char word2[20];
	
     printf("Enter word1 letter rate word2: ");
     fgets(table[count], 50, stdin);   // use fgets to read in whole line. You can move it into while loop if you like. 

     
     while (strcmp(table[count],"quit\n\0"))        
     { 
           table[count][strlen(table[count])] = '\0';
           sscanf(table[count],"%s %c %f %s", word1, &letter, &rate, word2);
           int i;
           char word3[20];
           for(i = 0; i < strlen(word1); i++){
                 if(word1[i] == 'Z'){
                       word3[i] = 'A';
                 }
                 else if(word1[i] =='z'){
                       word3[i] = 'a';
                 }
                 else{
                       word3[i] = word1[i] + 1;
                 }
           }
           word3[i] = '\0';
           char word4[20];
           strcpy(word4,word1);
           int j;
           for(j = 0; j < strlen(word4); j++){
                 if(word4[j] == letter){
                       word4[j] = '*';
                 }
           }

           float num = rate * 1.6;
           int ff = floor(num);
           int cc = ceil(num);
           char ans[4];
           if(strcmp(word1,word2) < 0){
                 strcpy(ans,"yes");
           }
           else{
                 strcpy(ans,"no");
           }

           int k;
           char end = word2[0];
           for(k = 1; k < strlen(word2); k++){
                 if(end <= word2[k]){
                       end = word2[k];
                 }
           }
           count++;
           sprintf(table[count],"%s--%s--%.4f--[%d, %d]--%s--'%c'\n", word3, word4, num, ff, cc, ans, end);
           count++;
           printf("Enter word1 letter rate word2: ");
           fgets(table[count], 50, stdin); 
     }
     
     /* output number of rows stored   */
      printf("\nTotally %d rows are stored\n",count);

     /* output the stored rows of the table */
     int l;
       for(l = 0; l < count; l++){
      printf("[%d]: %s", l, table[l]);
    }
       return 0;
}

