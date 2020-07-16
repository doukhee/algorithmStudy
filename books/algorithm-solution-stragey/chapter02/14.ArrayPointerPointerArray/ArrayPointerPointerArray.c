#include <stdio.h>

void main(){
    int i, j;
    int data[][2] = {{10, 20}, {30,40}, {50,60}, {70,80}, {90,100}};
    int (*ptr)[2];
    int *tptr[5];
    ptr = data;

    tptr[0] = &data[0][0];
    tptr[1] = &data[1][0];
    tptr[2] = &data[2][0];
    tptr[3] = &data[3][0];
    tptr[4] = &data[4][0];

    for(i = 0; i < 5; i++){
        printf("ptr : 0x%p, **ptr : %d, *(*ptr+1) : %d \r\n", ptr, **ptr, *(*ptr + 1));
        ptr++;
    }

    for(i = 0; i < 5; i++){
        printf("tptr[%d] : 0x%p, *tptr[%d] : %d, *(*tptr[%d] +1) : %d \r\n", i, tptr[i], i, *tptr[i], i, *(tptr[i] + 1));
    }
}