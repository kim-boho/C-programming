#include <stdio.h>

int isDigit(char);

main(){
    printf("Enter an integer and a character separated by blank: ");
    int input1; char input2;
    scanf("%d %c", &input1, &input2);
    while(input1 != -10000){
        if(isDigit(input2) == 1){
            int i = input2 - 48;
            printf("Character '%c' represents a digit. Sum of %d and %c is %d\n", input2, input1, input2, input1 + i);
        }
        else{
            printf("Character '%c' does not represent a digit\n", input2);
        }
        printf("\nEnter an integer and a character separated by blank: ");
        scanf("%d %c", &input1, &input2);
    }
}

int isDigit(char c){
    if(c >= '0' && c <= '9'){
        return 1;
    }
    else{
        return 0;
    }
}
