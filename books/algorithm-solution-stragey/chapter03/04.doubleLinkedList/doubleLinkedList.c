#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    char Data;
    struct _node *Next;
    struct _node *prev;
} Node;

Node *head, *end, *temp;
Node *temp1, *temp2, *temp3, *temp4;

void Initialize(void);
void InsertNode(Node *ptr);
void DeleteNode(Node *ptr);

void Initialize(void){
    Node *ptr;
    head = (Node *)malloc(sizeof(Node));
    end = (Node *)malloc(sizeof(Node));

    temp1 = (Node *)malloc(sizeof(Node));
    temp1->Data = 'A';
    head->Next = temp1;
    temp1->Next = end;
    temp1->prev = head;
    end->Next = end;
    ptr = temp1;

    temp2 = (Node *)malloc(sizeof(Node));
    temp2->Data = 'B';
    ptr->Next = temp2;
    temp2->Next = end;
    temp2->prev = ptr;
    ptr = temp2;

    temp3 = (Node *)malloc(sizeof(Node));
    temp3->Data = 'D';
    ptr->Next = temp3;
    temp3->Next = end;
    temp3->prev = ptr;
    ptr = temp3;

    temp4 = (Node *)malloc(sizeof(Node));
    temp4->Data = 'E';
    ptr->Next = temp4;
    temp4->Next = end;
    temp4->prev = ptr;
    ptr = temp4;
}

void InsertNode(Node *ptr){
    Node *indexPtr;
    for(indexPtr = head->Next; indexPtr != end; indexPtr = indexPtr->Next){
        if(indexPtr->Data < ptr->Data && indexPtr->Next->Data > ptr->Data){
            break;
        }
    }

    ptr->Next = indexPtr->Next;
    indexPtr->Next->prev = ptr;
    indexPtr->Next = ptr;
    ptr->prev = indexPtr;
}

void DeleteNode(Node *ptr){
    Node *indexPtr;
    Node *deletePtr;
    for(indexPtr = head; indexPtr != end; indexPtr = indexPtr->Next){
        if(indexPtr->Next->Data == ptr->Data){
            deletePtr = indexPtr->Next;
            break;
        }
    }
    indexPtr->Next = indexPtr->Next->Next;
    indexPtr->Next->Next->prev = indexPtr;
    free(deletePtr);
}


int main(void){
    Node *ptr;
    int i = 0;
    Initialize();

    printf("Insert Node C before \r\n");
    ptr = head->Next;

    for(i = 0; i < 4; i++){
        printf("%2c", ptr->Data);
        ptr = ptr->Next;
    }
    printf("\r\n");
    temp = (Node *)malloc(sizeof(Node));
    temp->Data = 'C';

    InsertNode(temp);

    printf("Insert Node C After\r\n");
    ptr = head->Next;

    for(i = 0; i < 5; i++){
        printf("%2c", ptr->Data);
        ptr = ptr->Next;
    }
    printf("\r\n");
    DeleteNode(temp);

    printf("Insert Node C Delete \r\n");
    ptr = head->Next;

    for(i = 0; i < 4; i++){
        printf("%2c", ptr->Data);
        ptr = ptr->Next;
    }
    printf("\r\n");
    return 0;
}