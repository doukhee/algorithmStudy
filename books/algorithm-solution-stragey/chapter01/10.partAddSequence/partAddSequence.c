#include <stdio.h>

int MaxSum(int );
void Init(void);
int Array[100];

int MaxSum(int N){
    int Sum, Max, i, j, k;
    Sum = Max = 0;

    for(i = 0; i < N; i++){
        for(j = i; j < N; j++){
            Sum = 0;
            for(k = i; k < j+1; k++){
                Sum += Array[k];
            }

            if(Sum > Max){
                Max = Sum;
            }
        }
    }
    return Max;
}



void Init(void){
    int i;

    for(i = 0; i < 100; i++){
        Array[i] = 100 - i;
    }

}

int main(int argc, char **argv){

    int ret;
    Init();
    ret = MaxSum(10);

    printf("ret : %d \r\n", ret);

    return 0;
}