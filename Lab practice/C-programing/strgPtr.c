#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100   // DO NOT CHANGE THIS CONSTANT

/******************  YOUR CODE STARTS HERE ******************/
/************************************************************/

/*
 * Input: non-empty string s
 * Output: return the length of s
 */ 
int strgLen( char *s )
{
   /* ADD YOUR CODE HERE */
   char *p = s;
   int len = 0;
   while(*p != '\0'){
     p++;
   }
   return p - s;
}


/*
 * Input: non-empty string s
 * Output: copy the content of string s to string dest
 */ 
int strgCopy( char *s, char *dest )
{
   /* ADD YOUR CODE HERE */
   while(*s != '\0'){
     *dest = *s;
     dest++;
     s++;
   }
   *dest = '\0';
   return 0;
}


/*
 * Input: non-empty string s
 * Output: for each character in string s, if it is an alphabet, reverse the  
 * case of the character.  Keep the non-alphabet characters as is.  
 */ 
int strgChangeCase( char *s )
{
   /* ADD YOUR CODE HERE */
   while(*s != '\0'){
     if(*s >= 'a' && *s <= 'z'){
       *s = *s + 'A' - 'a';
       s++;
     }
     else if(*s >= 'A' && *s <= 'Z'){
       *s = *s + 'a' - 'A';
       s++;
     }
     else{
       s++;
     }
   }
   return 0;
}


/*
 * Input: non-empty strings s1 and s2
 * Output: Return the index where the first difference occurs.
 * Return -1 if the two strings are equal.
 */ 
int strgDiff( char *s1, char *s2 )
{
   /* ADD YOUR CODE HERE */
   int count = 0;
   while(*s1 != '\0' || *s2 != '\0'){
     if(*s1 != *s2){
       return count;
     }
     s1++;
     s2++;
     count++;
   }
   if(*s1 == *s2){
     return -1;
   }
   else{
     return count;
   }
}


/*
 * Input: non-empty strings s1 and s2
 * Output: copy s1 and s2 to s3, interleaving the characters of s1 and s2.  
 * If one string is longer than the other, after interleaving, copy the rest 
 * of the longer string to s3.  
 */
int strgInterleave( char *s1, char *s2, char *d )
{
   /* ADD YOUR CODE HERE */
   while(*s1 != '\0' && *s2 != '\0'){
     *d = *s1;
     d++;
     *d = *s2;
     d++;
     s1++;
     s2++;
   }
   if(*s1 == '\0'){
     while(*s2 != '\0'){
       *d = *s2;
       d++;
       s2++;
     }
     *d = '\0';
   }
   else if(*s2 == '\0'){
     while(*s1 != '\0'){
       *d = *s1;
       d++;
       s1++;
     }
     *d = '\0';
   }
   else{
     *d = '\0';
   }
   return 0;
}

/*******************  YOUR CODE ENDS HERE *******************/
/************************************************************/

/*********  DO NOT CHANGE ANYTHING BELOW THIS LINE IN THE FINAL SUBMISSION *********/

/* main() function 
 */
int main()
{
  char *op, *str1, *str2, *str3;
  int index;
  
  op = ( char* ) malloc ( MAX_LENGTH * sizeof( char ) );
  str1 = ( char* ) malloc ( MAX_LENGTH * sizeof( char ) );
  str2 = ( char* ) malloc ( MAX_LENGTH * sizeof( char ) );
  str3 = ( char* ) malloc ( 2 * MAX_LENGTH * sizeof( char ) );
  
  if( !op || !str1 || !str2 || !str3 ) {
    printf( "Memory allocation failed.\n" );
    exit( 1 );
  }
  
  do {
    scanf( "%s %s", op, str1 );
    switch( *op )
    {
    case 'l':   // length
    case 'L':
      printf( "%d\n", strgLen( str1 ) );
      break;
          
    case 'c':   // copy
    case 'C':
      strgCopy( str1, str2 );
      printf( "%s\n", str2 );
      break;
      
     case 'h':   // cHange case
     case 'H':
      strgChangeCase( str1 );
      printf( "%s\n", str1 );
      break;     
                
    case 'd':  // difference  
    case 'D':
      scanf( "%s", str2 );
      index = strgDiff( str1, str2 );
      if ( index < 0 )
        printf( "Equal strings\n" );
      else
        printf( "%d\n", index );      
      break;    
    
    case 'i':  // interleave
    case 'I':
      scanf( "%s", str2 );    
      strgInterleave( str1, str2, str3 );
      printf( "%s\n", str3 );      
      break;

    case 'q':  // quit
    case 'Q':
      /* To quit, enter character (action) 'q' or 'Q' and an arbitrary string.
         This is not elegant but makes the code simpler.  */  
      /* Do nothing but exit the switch statement */    
      break;
            
    default:  
      printf( "Invalid operation %c\n", *op );         
    }  // end switch
  } while ( *op != 'q' && *op != 'Q' );
  
  return 0;
}

