#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX             100
#define TRUE            1
#define FALSE           0

void MakeRandomNumber();
void QuickSort(int data[], int , int);
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


void QuickSort(int data[], int left, int right){
    int num, i, j, temp;
    if(right > left){
        num = data[right];
        i = left - 1;
        j = right;

        for(;;){
            while(data[++i] < num);
            while(data[--j] > num);
            if(i >= j){
                break;
                }
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
        temp = data[i];
        data[i] = data[right];
        data[right] = temp;

        QuickSort(data, left, i - 1);
        QuickSort(data, i + 1, right);
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

int main(){
    printf("Init Data \r\n");
    MakeRandomNumber();
    DisplayBuffer();
    printf("Sort done \r\n");
    QuickSort(Buf, 0, MAX - 1);
    DisplayBuffer();
    printf("\r\n");
    return 0;
}