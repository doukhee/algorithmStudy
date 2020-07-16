#include <stdio.h>

void PrintPointer(int (*)[2]);

void PrintPointer(int (*tptr)[2]){
    int i;
    printf("function call later \r\n");
    for(i = 0; i < 5; i++){
        printf("tptr : 0x%p, **tptr : %d \r\n", tptr, **tptr);
        tptr++;
    }
}

void main(void){
    int i, j;
    int data[][2] = {{10,20}, {30,40}, {50,60}, {70,80}, {90,100}};
    int (*ptr)[2];
    ptr = data;
    printf("function call before \r\n");

    for(i = 0; i < 5; i++){
        printf("ptr : 0x%p, **ptr : %d \r\n", ptr, **ptr);
        ptr++;
    }

    ptr = data;
    PrintPointer(ptr);
}