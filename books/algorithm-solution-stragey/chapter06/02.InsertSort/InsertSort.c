#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX             100
#define TRUE            1
#define FALSE           0

void MakeRandomNumber(void);
void InsertionSort(void);
void DisplayBuffer(void);
int IsNumberExit(int, int);
int Buf[MAX];

/** time calculator variable */
clock_t StartTime, EndTime;



void MakeRandomNumber(void){
    /** Init Buffer */
    //bzero(Buf, sizeof(Buf));
    //memset(Buf, 0, sizeof(Buf));
    int i, Num;
    i = 1;

    srand((unsigned)time(NULL));

    Buf[0] = 100;

    while(i < MAX){
        Num = rand() %MAX;
        if(!IsNumberExit(Num, i)){
            Buf[i] = Num;
            i++;
        }
    }
}

void InsertionSort(void){
    int i, j, dummy;
    for(i = 0; i < MAX; i++){
        dummy = Buf[i];
        j = i;
        while(Buf[j-1] > dummy && j > 0){
            Buf[j] = Buf[j-1];
            j--;
        }
        Buf[j] = dummy;
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

int main(int argc, char **argv){
    printf("Data Init\r\n");

    MakeRandomNumber();
    DisplayBuffer();
    printf("\r\nSort done \r\n");
    StartTime = clock();
    InsertionSort();
    EndTime = clock();
    DisplayBuffer();
    printf("\r\n");
    printf("result Time : %f", (float)(EndTime - StartTime)/CLOCKS_PER_SEC);
    printf("\r\n");
    return 0;
}