#include <stdio.h>

#define MAX     100

int Queue[MAX];
int Front, Rear;

void InitializeQueue(void);
void Put(int );
int Get(void);
void DisplayQueue(void);

int main(){
    int ret;
    InitializeQueue();

    Put(1);
    Put(2);
    Put(10);
    Put(20);
    Put(12);

    printf("다섯번의 Put() 함수 호출 후 결과 \r\n");
    DisplayQueue();
    ret = Get();
    ret = Get();
    ret = Get();

    printf("세번의 Get() 함수 호출 후 결과\r\n");
    DisplayQueue();
    ret = Get();
    ret = Get();
    DisplayQueue();
    return 0;
}

void InitializeQueue(void){
    Front = Rear = 0;
}

void Put(int num){
    Queue[Rear++] = num;
    if(Rear >= MAX){
        Rear = 0;
    }
}

int Get(void){
    int ret;
    ret = Queue[Front++];
    if(Front >= MAX){
        Front = 0;
    }
    return ret;
}

void DisplayQueue(void){
    int i = 0;
    printf("Front -> ");
    for(i = Front; i < Rear; i++){
        printf("%2d -> ", Queue[i]);
    }
    printf("Rear\r\n");
}
