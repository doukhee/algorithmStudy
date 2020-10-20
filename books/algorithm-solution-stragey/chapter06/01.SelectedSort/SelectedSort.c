/**
 * 선택 정렬 알고리즘의 기본 개념은 데이터의 처음부터 끝까지 쭉 훑어가면서 
 * 가장 작은 값을 찾아 그 값을 첫번째 데이터와 자리를 바꾸고, 두번째로 작은 
 * 데이터를 찾아 두번째의 데이터와 자리를 바꾸는 방법으로 구현하는 알고리즘
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX         100
#define TRUE        1
#define FALSE       0

void MakeRandomNumber(void);
void SelectedSort(void);
void DisplayBuffer(void);
int IsNumberExit(int , int );
int Buf[MAX];

clock_t StartTime, EndTime;

void MakeRandomNumber(){
    int i, Num;
    i = 1;
    /** seed값을 매번 다르게 지정하기 위한 수단으로 ㅎ현재 시간을 측정하여, 다른 난수를 생성해낸다. */
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

void SelectedSort(){
    int i, j, min, dummy;

    for(i = 0; i < MAX; i++){
        min = i;
        for(j = i + 1; j < MAX; j++){
            if(Buf[j] < Buf[min]){
                min = j;
            }
        }
        dummy = Buf[min];
        Buf[min] = Buf[i];
        Buf[i] = dummy;
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

int IsNumberExit(int number, int index){
    int i;

    for(i = 0; i < index; i++){
        if(Buf[i] == number || number == 0){
            return TRUE;
        }
    }
    return FALSE;
}

void main(){
    printf("Sort Data Init\r\n");
    MakeRandomNumber();
    DisplayBuffer();
    printf("Sort Done \r\n");
    StartTime = clock();
    SelectedSort();
    EndTime = clock();
    DisplayBuffer();
    printf("\r\n");
    printf("result Time : %f", (float)(EndTime - StartTime)/CLOCKS_PER_SEC);
    printf("\r\n");
}