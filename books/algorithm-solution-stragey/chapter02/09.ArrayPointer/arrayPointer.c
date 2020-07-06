#include <stdio.h>

void main(){
    int data[5] = {10, 20, 30, 40, 50};
    int *ptr;
    ptr = data;
    printf("ptr : 0x%p, *ptr : %d \r\n", ptr, *ptr);

    ptr = &data[0];
    printf("ptr ; 0x%p, *ptr : %d \r\n", ptr, *ptr);

}