#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX         100
#define TRUE        1
#define FALSE       0

#define OVERLOW     3

typedef struct _Node{
    int key[3];
    int counter;
}Node;

void Initialize(void);
void MakeRandomNumber(void);
void DisplayBuffer();
void DisplayHitBuffer(void);
void DisplayHitCounter();

int Buf[MAX];
Node Hit[50];

void Initialize(void){
    int i, j;
    for(i = 0; i < MAX; i++){
        Buf[i] = -1;
    }
    for(i = 0; i < 20; i++){
        for(j = 0; j < 3; j++){
            Hit[i].key[j] = -1;
        }
        Hit[i].counter = 0;
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

        if(Hit[index].counter > 2){
            printf("\r\nOverFlow\r\n");
        }else{
            Hit[index].key[Hit[index].counter++] = Num;
        }
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
    printf("====> Hit Key Data <====\r\n");

    for(i = 0; i < 50; i++){
        if((i % 5) == 0){
            printf("\r\n");
        }
        switch(Hit[i].counter){
            case 0:
            case 1:
                printf("%2d ", Hit[i].key[0]);
            break;
            case 2:
                printf("%2d/%2d ", Hit[i].key[0], Hit[i].key[1]);
            break;
            case 3:
                printf("%2d/%2d/%2d ", Hit[i].key[0], Hit[i].key[1], Hit[i].key[2]);
            break;
            default:
                printf("**");
        }
        printf(", ");
    }
    printf("\r\n\r\n");
}

void DisplayHitCounter(){
    int i;
    printf("====> Hit Counter Data <====\r\n");

    for(i = 0; i < 50; i++){
        if((i % 5) == 0){
            printf("\r\n");
        }
        printf("%4d ", Hit[i].counter);
    }
    printf("\r\n");
}

int main(){
    Initialize();
    MakeRandomNumber();

    printf("key - mapping make data\r\n");

    DisplayBuffer();
    printf("\r\n\r\n");
    DisplayHitBuffer();
    DisplayHitCounter();
    return 0;
}
