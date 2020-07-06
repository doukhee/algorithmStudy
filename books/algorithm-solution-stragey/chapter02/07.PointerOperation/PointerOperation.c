#include <stdio.h>


void main(void){
    int data = 10;
    int *ptr;


    printf("ptr : 0x%p, *ptr : %d \r\n", ptr, *ptr);
    ptr = &data;

    printf("ptr : 0x%p, *ptr : %d \r\n", ptr, *ptr);
    *ptr = data;
    printf("ptr : 0x%p, *ptr : %d \r\n", ptr, *ptr);
}