#include "node.h"

#define MAX     100


Node *Stack[MAX];
int Top;

void InitializeStack(void);
void Push(Node *);
Node *Pop(void);
int IsStackEmpty(void);

void InitializeStack(void){
    Top = 0;
}

void Push(Node *ptrNode){
    Stack[Top] = ptrNode;
    //Top = (Top++) % MAX;
    Top = (++Top) % MAX;
}

Node *Pop(void){
    Node *ptrNode;

    if(!IsStackEmpty()){
        ptrNode = Stack[--Top];
        return ptrNode;
    }else{
        printf("Stack is Empty!\r\n");
        return NULL;
    }
}
int IsStackEmpty(void){
    if(Top == 0){
        return TRUE;
    }else{
        return FALSE;
    }
}

