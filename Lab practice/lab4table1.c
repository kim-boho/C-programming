
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

 
#define ROWS 20
#define COLUMNS 30

int main(int argc, char *argv[])
{
    char inputs_table [ROWS][COLUMNS];
    char name[10]; char ageS[10]; char rateS[10];
    int rows = 0;
		
    printf("Enter name age and rate: ");
    scanf("%s %s %s", name, ageS, rateS); 
       
    while (strcmp(name,"xxx") != 0)        
    {  
	   
	    sprintf(inputs_table[rows], "%s %s %s", name, ageS, rateS);

        rows += 1;

        char upName[10];
        int j;
        for(j = 0; j < strlen(name); j++){
            if(islower(name[j])){
                char new = toupper(name[j]);
                upName[j] = new;
            }
            else{
                upName[j] = name[j];
            }
        }
        upName[j] = '\0';

        int ageInt = atoi(ageS) + 10;
        float rateFl = atof(rateS) * 1.5;

        sprintf(inputs_table[rows],"%s %d %.2f", upName, ageInt,rateFl);
        
        rows += 1;
          

       /* read again using scanf(%s %s %s) */
        printf("Enter name age and rate: ");
        scanf("%s %s  %s", name, ageS, rateS); 
    }
    
     printf("\nRecords generated in %s on %s %s\n", __FILE__, __DATE__, __TIME__); 
    
    /* now display the input_table row by row */      
	int i;
    for(i = 0; i < rows; i++){
        printf("row[%d]: %s\n", i, inputs_table[i]);
    }

     return 0;
}

