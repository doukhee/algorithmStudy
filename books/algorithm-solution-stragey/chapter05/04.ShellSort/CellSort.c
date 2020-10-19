#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX         100
#define TRUE        1
#define FALSE       0

void MakeRandomNumber();
void ShellSort();
void DisplayBuffer(void);
int IsNumberExit(int, int);

int Buf[MAX];

void MakeRandomNumber(){
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

void ShellSort(){
    int i, j, h, v;
    for(h = 0; h < MAX; h = 3 * h + 1){
        ;
    }
    for(; h > 0; h /= 3){
        for(i = h; i < MAX; i++){
            v = Buf[i];
            j = i;

            while(j >= h && Buf[j - h] > v){
                Buf[j] = Buf[j - h];
                j -= h;
            }
            Buf[j] = v;
        }
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
    printf("Sort Data Init\r\n");
    MakeRandomNumber();
    DisplayBuffer();
    printf("Sort done number \r\n");

    ShellSort();
    DisplayBuffer();
    printf("\r\n");
    return 0;
}