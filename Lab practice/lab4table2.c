
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define ROWS 20
#define COLUMNS 30

int main(int argc, char *argv[])
{
     char input_table[ROWS][COLUMNS];
     int current_row=0;
  	
     printf("Enter name age and rate: ");
     fgets(input_table[current_row], 30, stdin);   // add a /n.  Don't change this line
	 
     while(!(input_table[current_row][0] == 'x' && input_table[current_row][1] == 'x' && input_table[current_row][2] == 'x' && input_table[current_row][3] == ' '))        
     { 
	 /* need to 'tokenize' the current input */	    
	 input_table[current_row][strlen(input_table[current_row]) - 1] = '\0';
      char name[10];
      int age;
      float rate;
      sscanf(input_table[current_row], "%s %d %f", name, &age, &rate);
      current_row += 1;
      
      int j;
      for(j = 0; j < strlen(name); j++){
          if(islower(name[j])){
             name[j] = toupper(name[j]);
          }
          else{
             name[j] = name[j];
          }
        }
      name[j] = '\0';

      age += 10;
      rate = rate * 1.5;
      sprintf(input_table[current_row],"%s %d %.2f", name, age, rate);
      current_row++;


        // read again    
     printf("Enter name age and rate: ");
     fgets(input_table[current_row], 30, stdin);  
     }

     printf("\nRecords generated in %s on %s %s\n", __FILE__, __DATE__, __TIME__);
     /* now display the input_table row by row */
	int i;
     for(i = 0; i < current_row; i++){
        printf("row[%d]: %s\n", i, input_table[i]);
    }
     return 0;
}

