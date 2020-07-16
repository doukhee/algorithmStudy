#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    char Data;
    struct _node *Next;
}NODE;

NODE *head, *end, *temp;
NODE *temp1, *temp2, *temp3, *temp4;

void Initialize();
void InsertNode(NODE *ptr);
void DeleteNode(NODE *ptr);

void Initialize(){
    NODE *ptr = NULL;
    head = (NODE *)malloc(sizeof(NODE));
    end = (NODE *)malloc(sizeof(NODE));

    temp1 = (NODE *)malloc(sizeof(NODE));
    temp1->Data = 'A';
    head->Next = temp1;
    temp1->Next = end;
    end->Next = end;
    ptr = temp1;

    temp2 = (NODE *)malloc(sizeof(NODE));
    temp2->Data = 'B';
    ptr->Next = temp2;
    temp2->Next = end;
    ptr = temp2;

    temp3 = (NODE *)malloc(sizeof(NODE));
    temp3->Data = 'D';
    ptr->Next = temp3;
    temp3->Next = end;
    ptr = temp3;

    temp4 = (NODE *)malloc(sizeof(NODE));
    temp4->Data = 'E';
    ptr->Next = temp4;
    temp4->Next = end;
    ptr = temp4;
}

void InsertNode(NODE *ptr){
    NODE *indexptr;
    
    for(indexptr = head->Next; indexptr != end; indexptr = indexptr->Next){
        if(indexptr->Data < ptr->Data && indexptr->Next->Data > ptr->Data){
            break;
        }
    }

    ptr->Next = indexptr->Next;
    indexptr->Next = ptr;
}

void DeleteNode(NODE *ptr){
    NODE *indexptr;
    NODE *deleteptr;

    for(indexptr = head; indexptr != end; indexptr = indexptr->Next){
        if(indexptr->Next->Data == ptr->Data){
            deleteptr = indexptr->Next;
            break;
        }
    }

    indexptr->Next = indexptr->Next->Next;
    free(deleteptr);
}

int main(void){

    NODE *ptr;
    int i = 0;
    Initialize();

    printf("Insert C before \r\n");
    ptr = head->Next;

    for(i = 0; i < 4; i++){
        printf("%2c", ptr->Data);
        ptr = ptr->Next;
    }

    temp = (NODE *)malloc(sizeof(NODE));
    temp->Data = 'C';

    InsertNode(temp);
    printf("Insert C After\r\n");
    ptr = head->Next;

    for(i = 0; i < 5; i++){
        printf("%2c", ptr->Data);
        ptr = ptr->Next;
    }

    DeleteNode(temp);

    printf("\r\nNode C Delete \r\n");
    ptr = head->Next;

    for(i = 0; i < 4; i++){
        printf("%2c", ptr->Data);
        ptr = ptr->Next;
    }
    printf("\r\n");
    return 0;
}