
#include <stdio.h>
#include <string.h>

#define SIZE 30

void sortArray(char*);

int main(){
    char arr[SIZE];
    fgets(arr, SIZE, stdin);
    while(strcmp(arr,"quit\n\0")){
        arr[strlen(arr) - 1] = '\0';
        sortArray(arr);
        printf("%s\n\n", arr);
        fgets(arr,SIZE,stdin);
    }
}

void sortArray(char *str){
    int i;
    for(i = 0; *(str + i) != '\0'; i++);
    int n = i - 1;
    int j;
    for(j = 0; j <= n - 1; j++){
        int k;
        for(k = j + 1; k <= n; k++){
            if(*(str + j) > *(str + k)){
                char temp = *(str + k);
                *(str + k) = *(str + j);
                *(str + j) = temp;
            }
        }
    }
}
