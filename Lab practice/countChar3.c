#include <stdio.h> // define EOF

main(){
  int c;
  char nl = '\n';
  int count = 0;

  c = getchar();

  while(c != EOF) /* no end of file*/
  { 
    if(c != nl){
      count++;
    }
    c = getchar(); /* read next */
  }
  printf("# of chars:  %d\n",count);

}

