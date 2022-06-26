#include <stdio.h>

int main(){
    char c = getchar();
    char result;
    while(c != EOF){
        if(c >= 'a' && c <= 'z'){
            result = c - 32;
        }
        else{
            result = c;
        }
        putchar(result);
        c = getchar();
    }
    return 0;
}
