/**
 * makefile에서 진행이 안됨
 * 
 * 비주얼 스튜디오에서 정상 동작
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE            1
#define FALSE           0
#define MAX_INT         65536
#define MAX             100

void MakeRandomNumber();
void HeapSort(int );
void DisplayBuffer(void);
int IsNumberExit(int , int );
void UpHeap(int );
void DownHeap(int );
void InsertData(int );
int RemoveData(void);

int Buf[MAX];
int Data[MAX];
int temp[MAX];
int NUMBER = 0;

void MakeRandomNumber(){
    int i, Num;
    i = 1;
    srand((unsigned)time(NULL));
    Data[0] = 100;


    while(i < MAX){
        Num = rand() % MAX;

        if(!IsNumberExit(Num, i)){
            Data[i] = Num;
            i++;
        }
    }
}

void HeapSort(int N){
    int i;
    for(i = 0; i < MAX; i++){
        InsertData(Data[i]);
    }
    Data[0] = 1;
    for(i = MAX - 1; i >= 0; i--){
        Data[i] = RemoveData();
    }
}

void DisplayBuffer(void){
    int i;
    for(i = 0; i < MAX; i++){
        if((i % 10) == 0){
            printf("\r\n");
        }
        printf("%4d ", Data[i]);
    }
    printf("\r\n");
}

int IsNumberExit(int number, int index){
    int i;
    for(i = 0; i < index; i++){
        if(Data[i] == number || number == 0){
            return TRUE;
        }
    }
    return FALSE;
}

void UpHeap(int k){
    int v;
    v = Buf[k];
    Buf[0] = MAX_INT;
    while(Buf[k / 2] <= v){
        Buf[k] = Buf[k / 2];
        k = k / 2;
    }
    Buf[k] = v;
}
void DownHeap(int k){
    int i, v;
    v = Buf[k];
    while(k <= NUMBER / 2){
        i = 2 * k;
        if(i < NUMBER && Buf[i] < Buf[i + 1]){
            i++;
        }
        if(v >= Buf[i]){
            break;
        }
        Buf[k] = Buf[i];
        k = i;
    }
    Buf[k] = v;
}

void InsertData(int v){
    
    Buf[NUMBER++] = v;
    UpHeap(NUMBER);
}

int RemoveData(void){
    int v = Buf[1];
    Buf[1] = Buf[NUMBER--];
    DownHeap(1);
    return v;
}

int main(){
    NUMBER = MAX;

    printf("Sort Data Init \r\n");
    MakeRandomNumber();
    DisplayBuffer();
    printf("Sort Done Data \r\n");

    HeapSort(NUMBER);
    DisplayBuffer();
    printf("\r\n");
    
    return 0;
}