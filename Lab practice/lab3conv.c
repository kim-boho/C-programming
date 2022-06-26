
#include <stdio.h>

float fun_IF(int, char, float);
float fun_II(int, char, int);
float fun_FF(float, char, float);

int main(){

 int op1; float op2;  char operator;
 float resu, resu2, resu3;
 
 float a = 9/2;
 float b = 9*1.0/2;  // force 9 to be converted before /
 float c = 9/2*1.0;  // force 2 to be converted before /, but not working
 float c2 = 9/(2*1.0); // force 2 to be converted before /  
 float d = (float)9/2;  // cast 9 before /
 float e =  9/(float)2; // cast 2 before /
 float f = (float) (9/2); // cast after /, not working
 printf("9/2=%f  9*1.0/2=%f  9/2*1.0=%f   9/(2*1.0)=%f\n\n", a, b, c, c2);
 printf("(float)9/2=%f  9/(float)2=%f  (float)(9/2)=%f\n\n", d, e, f);
  
 // conversion in arithemetic
 printf("3.0*9/2/4=%f  9/2*3.0/4=%f  9*3/2*3.0/4=%f\n\n", 3.0*9/2/4, 9/2*3.0/4, 9/2*3.0/4);
 
 // conversion in assignment
 float f2  = 3.96;
 float f3 = 3.03;
 int i = f2; int j = f3;
 printf("i: %d  j: %d\n", i, j);

 int intNum; char opChar; float floatNum;
 printf("\nEnter operand_1 operator operand_2 separated by blanks> ");
 scanf("%d %c %f",&intNum,&opChar,&floatNum);

 while(intNum != -1 || floatNum != -1){
     printf("\nYour input '%d %c % f' result in\n",intNum,opChar,floatNum);
     printf("%f (fun_IF)\n",fun_IF(intNum,opChar,floatNum));
     printf("%f (fun_II)\n",fun_II(intNum,opChar,floatNum));
     printf("%f (fun_FF)\n",fun_FF(intNum,opChar,floatNum));

     printf("\nEnter operand_1 operator operand_2 separated by blanks> ");
     scanf("%d %c %f",&intNum,&opChar,&floatNum);
 }

 // In fun_IF, int is converted to float when it is calculated because another is float and it was received as float.
 // So, it's the same result with the result of fun_FF.
 // In fun_II, it recieves floating number as int. Since left hand side type is int, input number is converted as int.
 // Therefore, even though the return type is float, its result could be different to others' results because it already lost information.

 
  return 0;


}
 
float fun_IF(int op1, char operator, float op2){
   if(operator == '+'){
       return op1 + op2;
   }
   else if(operator == '-'){
       return op1 - op2;
   }
   else if(operator == '*'){
       return op1 * op2;
   }
   else{
       return op1 / op2;
   }
}

float fun_II(int op1, char operator, int op2) {
   if(operator == '+'){
       return op1 + op2;
   }
   else if(operator == '-'){
       return op1 - op2;
   }
   else if(operator == '*'){
       return op1 * op2;
   }
   else{
       return op1 / op2;
   }
}

float fun_FF(float op1, char operator, float op2){
   if(operator == '+'){
       return op1 + op2;
   }
   else if(operator == '-'){
       return op1 - op2;
   }
   else if(operator == '*'){
       return op1 * op2;
   }
   else{
       return op1 / op2;
   }
}

 
