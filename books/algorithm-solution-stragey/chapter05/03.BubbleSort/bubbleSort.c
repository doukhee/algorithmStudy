/**
 * bubble sort는 최악의 경우를 가정했을 때의 알고리즘 성능이 다른 정렬 알고리즘보다 많이 나쁘다.
 * 배열끼리 비교와 복사를 반복 실행하기 때문이다.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX         100
#define TRUE        1
#define FALSE       0


void MakeRandomNumber(void);
void BubbleSort(void);
void DisplayBuffer(void);
int IsNumberExit(int , int);

int Buf[MAX];

clock_t StartTime, EndTime;

void MakeRandomNumber(void){
    int i, Num;
    i = 1;

    srand((unsigned)time(NULL));

    Buf[0] = 100;
    while(i < MAX){
        Num = rand() % MAX;

        if(!IsNumberExit(Num, i)){
            Buf[i] = Num;
            i++;
        }
    }
}

void BubbleSort(void){
    int i, j, dummy;

    for(i = MAX - 1; i >= 0; i--){
        for(j = 1; j <= i; j++){
            if(Buf[j - 1] > Buf[j]){
                dummy = Buf[j - 1];
                Buf[j - 1] = Buf[j];
                Buf[j] = dummy;
            }
        }
    }
}

void DisplayBuffer(void){
    int i;

    for(i = 0; i < MAX; i++){
        if((i % 10) == 0){
            printf("\r\n");
        }
        printf("%4d ",Buf[i]);
    }
    printf("\r\n");
}

int IsNumberExit(int number, int index){
    int i;

    for(i = 0; i < index; i++){
        if(Buf[i] == number || number == 0){
            return TRUE;
        }
    }
    return FALSE;
}

int main(){
    printf("Sort Data Init \r\n");
    MakeRandomNumber();
    DisplayBuffer();
    printf("Sort Data \r\n");
    StartTime = clock();
    
    BubbleSort();
    
    EndTime = clock();
    
    DisplayBuffer();

    printf("result Time : %f", (float)(EndTime - StartTime)/CLOCKS_PER_SEC);
    printf("\r\n");
    return 0;
}