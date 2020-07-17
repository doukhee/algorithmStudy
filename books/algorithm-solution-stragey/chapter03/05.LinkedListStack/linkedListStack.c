#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int Data;
    struct _node *Next;
}Node;

Node *head, *end;
Node *ptrNode;

void InitializeStack(void);
void Push(int );
int Pop(void);
void DisplayStack(void);


void InitializeStack(void){
    head = (Node *)malloc(sizeof(Node));
    end = (Node *)malloc(sizeof(Node));
    head->Next = end;
    end->Next = end;
}

void Push(int num){
    ptrNode = (Node *)malloc(sizeof(Node));
    ptrNode->Data = num;
    ptrNode->Next = head->Next;
    head->Next = ptrNode;
}

int Pop(void){
    int ret;
    ptrNode = head->Next;
    head->Next = head->Next->Next;
    ret = ptrNode->Data;
    free(ptrNode);
    return ret;
}

void DisplayStack(void){
    Node *indexNode;
    printf("Head-> ");

    for(indexNode = head->Next; indexNode != end; indexNode = indexNode->Next){
        printf("%2d-> ", indexNode->Data);
    }
    printf("end\r\n");

}

int main(void){
    int ret;
    InitializeStack();
    Push(1);
    Push(3);
    Push(10);
    Push(20);
    Push(12);

    printf("5 Push() result \r\n");
    DisplayStack();
    ret = Pop();
    ret = Pop();
    ret = Pop();
    printf("3 Pop() result \r\n");
    DisplayStack();
    return 0;
}