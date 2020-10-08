#include <stdio.h>
#include "node.h"

#define MAX             100


Node *Queue[MAX];
int Front, Rear;

void InitializeQueue(void);
void Put(Node *);
Node *Get(void);
int IsEmptyQueue(void);

void InitializeQueue(void){
    Front = Rear = 0;
}

void Put(Node *ptrNode){
    Queue[Rear] = ptrNode;
    Rear = (++Rear) % MAX;
}

Node *Get(void){
    Node *ptrNode;
    if(!IsEmptyQueue()){
        ptrNode = Queue[Front];
        Front = (++Front) % MAX;
        return ptrNode;
    }else{
        printf("Queue is Empty");
        return NULL;
    }
}

int IsEmptyQueue(void){
    if(Rear == Front){
        return TRUE;
    }else{
        return FALSE;
    }
}
