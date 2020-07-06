#include <stdio.h>

void main(void){
    int data = 10;
    int *ptr;

    printf("data address : 0x%p, data value : %d \r\n", &data, data);

    ptr = &data;
    printf("ptr address : 0x%p, ptr value : %d \r\n", &ptr, ptr);

    printf("ptr point value : %d , data value : %d \r\n", *ptr, data);


    printf("ptr address : 0x%p, ptr value : 0x%p, ptr point value : %d \r\n", &ptr, ptr, *ptr);
}