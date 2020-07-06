#include <stdio.h>

/** windows error *ptr = data */
void main(){
    int data = 10;
    int *ptr;
    *ptr = data;

    printf("ptr : 0x%p, *ptr : %d \r\n", ptr, *ptr);
}