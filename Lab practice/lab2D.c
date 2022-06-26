#include <stdio.h>

int main() {
    char arr[] = {0,1,2,3,4,5,6,7,8,9};
    int arrlength = 10;
    char c = getchar();
    while(c != EOF){
        if(c >= '0' && c <= '9'){
            int i = c - 48;
            arr[i]++;
        }

        c = getchar();
    }
       int j;
    for(j = 0; j < arrlength; j++){
        printf("%d: %d\n", j, arr[j] - j);
    }

    return 0;
}
