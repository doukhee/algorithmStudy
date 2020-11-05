#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX             100
#define TRUE            1
#define FALSE           0
#define OVERFLOW        3

typedef struct _Node{
    int Key[3];
    int Counter;
} Node;

int Buf[MAX];
Node Hit[50];

void Initialize(void);
void MakeRandomNumber(void);
void DisplayBuffer(void);
void DisplayHitBuffer(void);
void DisplayHitCounter(void);
int IsNumberExit(int);

void Initialize(void){
    int i, j;
    for(i = 0; i < MAX; i++){
        for(j = 0; j < 3; j++){
            Hit[i].Key[j] = -1;
        }
        Hit[i].Counter = 0;
    }
}

void MakeRandomNumber(void){
    int i, Num, index;
    i = 0;
    srand((unsigned)time(NULL));

    while(i < 50){
        Num = rand() % 100;

        if(!IsNumberExit(Num)){
            Buf[Num] = Num;
            index = Num % 50;

            if(Hit[index].Counter > 2){
                printf("\r\nOverFlow!\r\n");
            }else{
                Hit[index].Key[Hit[index].Counter++] = Num;
            }
            i++;
        }
    }
}

void DisplayBuffer(void){
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
    printf("====> Hit Key Data <====\r\n");

    for(i = 0; i < 50; i++){
        if((i % 5) == 0){
            printf("\r\n");
        }
        switch(Hit[i].Counter){
            case 0:
            case 1:
                printf("%2d", Hit[i].Key[0]);
                break;
            case 2:
                printf("%2d/%2d", Hit[i].Key[0], Hit[i].Key[1]);
                break;
            case 3:
                printf("%2d/%2d/%2d", Hit[i].Key[0], Hit[i].Key[1], Hit[i].Key[2]);
                break;
            default:
                printf("**");
        }
        printf("\t");
    }
    printf("\r\n\r\n");
}
void DisplayHitCounter(void){
    int i;
    printf("====> Hit Counter Data <====\r\n");

    for(i = 0; i < 50; i++){
        if((i % 5) == 0){
            printf("\r\n");
        }
        printf("%4d ", Hit[i].Counter);
    }
    printf("\r\n");
}

int IsNumberExit(int number){
    int i;
    for(i = 0; i < MAX; i++){
        if(Buf[i] == number){
            return TRUE;
        }
    }
    return FALSE;
}

int main(){
    Initialize();
    MakeRandomNumber();
    printf("key-mapping Init Data \r\n");
    
    DisplayBuffer();
    printf("\r\n");

    DisplayHitBuffer();
    DisplayHitCounter();
    return 0;
}