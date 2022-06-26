
#include <stdio.h>
#define MAX_LENGTH 100   // DO NOT CHANGE THIS CONSTANT

/******************  YOUR CODE STARTS HERE ******************/
/************************************************************/

/*
 * Input: non-empty string s
 * Output: return the length of s
 */ 
int strgLen( char s[ ] )
{
   /* ADD YOUR CODE HERE */
   int length = 0;
   while(s[length] != '\0'){
     length++;
   }
   // count each char in array until '\0'(the last char)
 if(length >= MAX_LENGTH){
     return -1;
   }
   else{
     return length;
   }//If its length is maximum or over than maximum, return -1. Otherwise, return length.
}
/*
 * Input: non-empty string s
 * Output: copy the content of string s to string dest
 */ 
int strgCopy( char s[ ], char dest[ ] )
{
   /* ADD YOUR CODE HERE */
   int index = 0;
   while(s[index] != '\0' && index != MAX_LENGTH){
     dest[index] = s[index];
     index++;
   } // copy each char of input until input is end or maximum length of string.

   dest[index] = '\0';
   return (unsigned long int) dest;
   // add '\0' at the end to complete copied string and return it.
}

/*
 * Input: non-empty string s
 * Output: for each character in string s, if it is an alphabet, reverse the  
 * case of the character.  Keep the non-alphabet characters as is.  
 */ 
int strgChangeCase( char s[ ] )
{
   /* ADD YOUR CODE HERE */
   int index = 0;
   while(s[index] != '\0' && index != MAX_LENGTH){
     if(s[index] >= 'a' && s[index] <= 'z'){
       s[index] = s[index] - 32;
     }
     else if(s[index] >= 'A' && s[index] <= 'Z'){
       s[index] = s[index] + 32;
     }
     index++;
   } // Until the string is end or string length is maximum length,
     // check each char if it is alphabet or not.
     // If it is lower case, change to upper case.
     // If it is upper case, change to lower case.

   s[index] = '\0'; // Add '\0' to complete string.
   return (unsigned long int) s; // return changed string.
}


/*
 * Input: non-empty strings s1 and s2
 * Output: Return the index where the first difference occurs.
 * Return -1 if the two strings are equal.
 */
int strgDiff( char s1[ ], char s2[ ] )
{
   /* ADD YOUR CODE HERE */
   int count;
   int i;
   for(i = 0; (s1[i] != '\0' || s2[i] != '\0') && i != MAX_LENGTH; i++){
     if(s1[i] != s2[i]){
       return i;
     }
     count = i;
   } // Check each of char in the same index in s1 and s2.
     // If they are different, return index i.
     // Keep the loop unitl their maximum length if they are not end and have the same chars.

   if(i == MAX_LENGTH){
     return -1;
   } // In the loop, if strings already were checked unitl maximum length,
     // return -1.

   if(s1[count + 1] != '\0' || s2[count + 1] != '\0'){
     return count;
   } // If there is left unchecked char in strings, return the first index of left chars.

   else{
     return -1;
   } // If ther is no left unchecked char in strings, return -1.
}


/*
 * Input: non-empty strings s1 and s2
 * Output: copy s1 and s2 to s3, interleaving the characters of s1 and s2.  
 * If one string is longer than the other, after interleaving, copy the rest 
 * of the longer string to s3.  
 */
int strgInterleave( char s1[ ], char s2[ ], char d[ ] )
{
   /* ADD YOUR CODE HERE */
   int i;
   int count;
   for(i = 0; s1[i] != '\0' && s2[i] != '\0' && i != MAX_LENGTH; i++){
     d[i * 2] = s1[i];
     d[i * 2 + 1] = s2[i];
     count = i;
   } // Until one of input strings is end, put one char of each strings.
     // The first string is the first.

   count++;
   int index = count * 2;
   // If one of strings is end,
   // set index to attach left strings.(index = length of string made above)

   if(s1[count] == '\0' && s2[count] == '\0'){
     d[index] = '\0';
     return (unsigned long int) d;
   } // If there is no left char in string in both of them,
     // end the strings by attaching '\0' at the end.
     // And, return completed strings.

   else{
     if(s1[count] == '\0'){
       while(s2[count] != '\0'){
         d[index] = s2[count];
         index++;
         count++;
       }
     } // If only the first string is done, attach left strings from second string.

     else{
       while(s1[count] != '\0'){
         d[index] = s1[count];
         index++;
         count++;
       }
     } // If only the second sring in done, attach left strings from first string.

     d[index] = '\0';
     return (unsigned long int) d;
     // End the string by adding '\0' at the end, and return the strings.
   }
}

/*******************  YOUR CODE ENDS HERE *******************/
/************************************************************/

/*********  DO NOT CHANGE ANYTHING BELOW THIS LINE IN THE FINAL SUBMISSION *********/

/* main() function 
 */
int main()
{
  char op[ MAX_LENGTH ]; 
  char str1[ MAX_LENGTH ]; 
  char str2[ MAX_LENGTH ];
  char str3[ MAX_LENGTH ];  
  int index;
  
  do {
    scanf( "%s %s", op, str1 );
    switch( op[ 0 ] )
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
      printf( "Invalid operation %c\n", op[0] );         
    }  // end switch
  } while ( op[ 0 ] != 'q' && op[ 0 ] != 'Q' );
  
  return 0;
}

