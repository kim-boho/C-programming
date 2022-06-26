
#include <stdio.h>

int isLeap(int);

int main() {
    int n;
    printf("Enter a year: ");
    scanf("%d",&n);
    while(n >= 0){
        if(isLeap(n)){
            printf("Year %d is a leap year", n);
        }
        else{
            printf("Year %d is not a leap year", n);
        }
        printf("\n\nEnter a year: ");
        scanf("%d", &n);
    }
    return 0;
}
int isLeap(int n){
    if(n % 4 == 0 && n % 100 != 0){
        return 1;
    }
    else if(n % 400 == 0){
        return 1;
    }
    else{
        return 0;
    }
}
