#include <stdio.h> // define EOF

main(){
  int c;
  char nl = '\n';
  int count = 0;
  int countnl = 0;

  c = getchar();

  while(c != EOF) /* no end of file*/
  { 
    if(c == nl){
      countnl++;
    }
    else{
      count++;
    }
    c = getchar(); /* read next */
  }
  printf("# of chars:  %d\n# of lines:  %d\n",count, countnl);

}

