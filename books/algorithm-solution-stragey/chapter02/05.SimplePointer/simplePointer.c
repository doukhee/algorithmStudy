#include <stdio.h>

void main(void){
    int data = 0;
    int *ptr;

    printf("data address : 0x%p, data value : %d \r\n", &data, data);
    ptr = &data;

    printf("ptr Address : 0x%p, ptr value : %d \r\n", &ptr, ptr);
}