#include <stdio.h>


int Add(void);
int Subtract(void);

int Num_A, Num_B;

int ret;

int Add(void){
    return Num_A + Num_B;
}

int Subtract(void){
    return Num_A - Num_B;
}

int main(int argc, char **argv){
    Num_A = 100;
    Num_B = 90;

    ret = Add();
    printf("return value : %d \r\n", ret);
    ret = Subtract();
    printf("return value : %d \r\n", ret);
    return 0;
}