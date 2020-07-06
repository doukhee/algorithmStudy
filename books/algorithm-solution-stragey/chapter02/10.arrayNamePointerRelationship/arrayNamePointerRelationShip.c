#include <stdio.h>

void main(){
    int data[5] = {10,20,30,40,50};
    int *ptr;
    ptr = data;

    printf("ptr : 0x%p, data : 0x%p, &data[0] : 0x%p \r\n", ptr, data, &data[0]);
}