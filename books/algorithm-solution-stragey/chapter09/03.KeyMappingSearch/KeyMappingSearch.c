#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX             100
#define TRUE            1
#define FALSE           0

typedef struct _Node{
    int key;
    int Counter;
}Node;

void Initialize(void);
void MakeRandomNumber(void);
void DisplayBuffer();
void DisplayHitBuffer(void);
void DisplayHitCounter();

int Buf[MAX];
Node Hit[50];

void Initialize(void){
    int i;
    for(i = 0; i < MAX; i++){
        Buf[i] = -1;
    }
    for(i = 0; i < 20; i++){
        Hit[i].key = -1;
        Hit[i].Counter = 0;
    }
}

void MakeRandomNumber(void){
    int i, Num, index;
    i = 0;
    srand((unsigned)time(NULL));

    while(i < 50){
        Num = rand() % 100;
        Buf[Num] = Num;

        index = Num % 50;
        Hit[index].key = Num;
        Hit[index].Counter++;
        
        i++;
    }
}

void DisplayBuffer(){
    int i;
    for(i = 0; i < MAX; i++){
        if((i % 10) == 0){
            printf("\r\n");
        }
        printf("%4d ", Buf[i]);
    }
    printf("\r\n");
}

void DisplayHitBuffer(void){
    int i;
    printf("============>Hit Key Data<============");

    for(i = 0; i < 50; i++){
        if((i % 10) == 0){
            printf("\r\n");
        }
        printf("%4d ", Hit[i].key);
    }
    printf("\r\n");
}

void DisplayHitCounter(){
    int i;
    printf("============>Hit Counter Data<============");
    for(i = 0; i < 50; i++){
        if((i % 10) == 0){
            printf("\r\n");
        }
        printf("%4d ", Hit[i].Counter);
    }
    printf("\r\n");
}

int main(){
    Initialize();

    MakeRandomNumber();
    printf("Key-Mapping Data \r\n");
    DisplayBuffer();
    printf("\r\n");
    DisplayHitBuffer();
    DisplayHitCounter();
    return 0;
}