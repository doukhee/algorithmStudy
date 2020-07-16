#include <stdio.h>

void Square(int, int *);

void Square(int lv, int *ret){
    if(lv == 2){
        *ret = *ret * *ret;
    }else if(lv == 3){
        *ret = *ret * *ret * *ret;
    }
}

int main(void){

    int number, level;
    printf("C programing pointer Example \r\n");
    
    level = 2;
    number = 3;
    Square(level, &number);
    printf("Level : %d , Return Value : %d \r\n", level, number);

    printf("\r\n");

    level = 3;
    number = 4;
    Square(level, &number);
    printf("Level %d, Return Value : %d \r\n ", level, number);
    return 0;
}