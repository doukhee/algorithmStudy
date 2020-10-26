#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX         100
#define TRUE        1
#define FALSE       0

void MakeRandomNumber(void);
void QuickShort(int [], int ,int);
void DisplayBuffer(void);
int IsNumberExit(int , int);
int BinarySearch(int);

int Buf[MAX];
int CompareCount;

clock_t StartTime;
clock_t EndTime;

void MakeRandomNumber(void){
    int i, Num;
    i = 0;
    srand((unsigned)time(NULL));

    while(i < MAX){
        Num = rand() % 200;
        if(!IsNumberExit(Num, i)){
            Buf[i] = Num;
            i++;
        }
    }
}

void QuickShort(int data[], int left,int right){
    int num, i, j, temp;

    if(right > left){
        num = data[right];
        i = left - 1;
        j = right;
        for(; ;){
            while(data[++i] < num){;}
            while(data[--j] > num){;}
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

        QuickShort(data, left, i - 1);
        QuickShort(data, i + 1, right);
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

int BinarySearch(int num){
    int left, right;
    int min;
    left = 0;
    right = MAX;

    while(right >= left){
        CompareCount++;
        min = (left + right) / 2;
        if(num < Buf[min]){
            right = min - 1;
        }else{
            left = min + 1;
        }
        if(num == Buf[min]){
            return min;
        }
    }
    return -1;
}

int main(){
    int ret;
    CompareCount = 0;
    printf("Init Data \r\n");
    MakeRandomNumber();
    printf("Init Data \r\n");
    DisplayBuffer();
    StartTime = clock();
    QuickShort(Buf, 0, MAX - 1);
    EndTime = clock();
    printf("\r\nSort Data \r\n");
    DisplayBuffer();
    ret = BinarySearch(23);
    printf("\r\n\r\nShort Time is %lf \r\n", (float)(StartTime - EndTime)/CLOCKS_PER_SEC);
    if(ret == -1){
        printf("\r\nnot have 23 data \r\n");
    }else{
        printf("\r\n23 data index is %d \r\n", ret);
    }
    printf("all comapare number is %d \r\n", CompareCount);
    return 0;
}