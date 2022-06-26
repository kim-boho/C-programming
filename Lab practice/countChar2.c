#include <stdio.h> // define EOF

main(){
  int c;
  char a = 'a';
  int count = 0;
  int countOfa = 0;

  c = getchar();

  while(c != EOF) /* no end of file*/
  { 
    count++; //include spaces and '\n'

    if(c == a){
      countOfa++;
    }

    c = getchar(); /* read next */
  }
  printf("# of chars:  %d\n# of char a: %d\n",count, countOfa);

}

