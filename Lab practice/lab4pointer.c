
#include <stdio.h>

int main(){
    int age = 10;
    int age2 = 100;
    int *ptr = &age;
    printf("age: %d %d\n", age, *ptr);
    *ptr = 14;
    printf("age: %d %d\n", age, *ptr);
    int *ptr2 = &age2;
    *ptr2 = *ptr;
    printf("age: %d %d\n", age2, *ptr2);
    ptr2 = ptr;
    printf("ptr2's pointee: %d\n", *ptr2);
    printf("age: %d %d %d\n", age, *ptr, *ptr2);
    *ptr2 = *ptr2 - 1;
    printf("age: %d %d %d\n", age, *ptr, *ptr2);
    printf("%p %p %p\n", &age, ptr, ptr2);
}
