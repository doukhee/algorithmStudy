#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int data;
    struct _Node *Next;
} Node;

Node *Front, *Rear;
Node *ptrNode;

void InitializeQueue();
void Put(int);
int Get(void);
void DisplayQueue(void);

int main(){
    int ret;
    InitializeQueue();
    printf("Put() 함수를 호출해보자 \r\n");
    Put(1);
    Put(3);
    Put(10);
    Put(20);
    Put(12);
    
    printf("다섯 번의 Put() 함수 호출 후 결과 : ");
    DisplayQueue();

    ret = Get();
    ret = Get();
    ret = Get();

    printf("\r\n세번의 Get() 함수 호출 후 결과 \r\n");
    DisplayQueue();

    ret = Get();
    ret = Get();

    printf("\r\n두번의 Get() 함수 호출 후 결과 \r\n");
    DisplayQueue();
    return 0;
}

void InitializeQueue(){
    Front = (Node *)malloc(sizeof(Node));
    Rear = (Node *)malloc(sizeof(Node));
    Front->Next = Rear;
    Rear->Next = Rear;
}

void Put(int num){
    ptrNode = (Node *)malloc(sizeof(Node));
    ptrNode->data = num;
    
    if(Front->Next == Rear){
        Front->Next = ptrNode;
        ptrNode->Next = Rear;
        Rear->Next = ptrNode;
    }else{
        Rear->Next->Next = ptrNode;
        ptrNode->Next = Rear;
        Rear->Next = ptrNode;
    }
}

int Get(void){
    int ret;
    Node *deleteNode;
    printf("\r\n");

    if(Front->Next == Rear){
        printf("Queue Empty!\r\n");
    }else{
        deleteNode = Front->Next;
        Front->Next = deleteNode->Next;
        ret = deleteNode->data;
        printf("Get() : %d ", ret);
        free(deleteNode);
    }
    return ret;
}

void DisplayQueue(void){
    Node *ptrTemp;

    if(Front->Next != Rear){
        for(ptrTemp = Front->Next; ptrTemp->Next != Rear; ptrTemp = ptrTemp->Next){
            printf("%2d -> ", ptrTemp->data);
        }
        printf("%d\r\n", ptrTemp->data);
    }else if(Front->Next == Rear){
        printf("Queue Empty\r\n");
    }
}