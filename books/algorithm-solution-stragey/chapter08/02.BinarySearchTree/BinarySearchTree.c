#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX         10
#define TRUE        1
#define FALSE       0

typedef struct _Node{
    int key;
    struct _Node *Left;
    struct _Node *Right;
} Node;

Node *ptrNode;
Node *HeadNode;
Node *EndNode;

void MakeRandomNumber(void);
void QuickShort(int [], int , int);
void DisplayBuffer(void);
int IsNumberExit(int , int);
void BSTInitialize(void);
void BSTInsert(int );
void BSTDisplay(Node *);

int Buf[MAX];
int CompareCount;

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

void QuickShort(int data[], int left, int right){
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

void BSTInitialize(void){
    EndNode = (Node *)malloc(sizeof(Node));
    EndNode->Left = EndNode;
    EndNode->Right = EndNode;
    EndNode->key = -1;

    HeadNode = (Node *)malloc(sizeof(Node));
    HeadNode->Right = EndNode;
    HeadNode->key = 0;
}

void BSTInsert(int num){
    Node *p, *x;
    p = HeadNode;
    x = HeadNode->Right;

    while(x != EndNode){
        p = x;
        x = (num < x->key) ? x->Left : x->Right;
    }
    x = (Node *)malloc(sizeof *x);
    x->key = num;
    x->Left = EndNode;
    x->Right = EndNode;

    if(num < p->key){
        p->Left = x;
    }else{
        p->Right = x;
    }
}

void BSTDisplay(Node *ptr){
    if(ptr != EndNode){
        BSTDisplay(ptr->Left);
        printf("%5d ", ptr->key);
        BSTDisplay(ptr->Right);
    }
}

int main(){
    int i, ret;
    CompareCount = 0;
    printf("Init Data \r\n");
    MakeRandomNumber();
    DisplayBuffer();
    printf("\r\nSort Data \r\n");
    QuickShort(Buf, 0, MAX - 1);
    DisplayBuffer();
    BSTInitialize();

    for(i = 0; i < MAX; i++){
        BSTInsert(Buf[i]);
    }
    printf("\r\nRoot Node : %d \r\n", HeadNode->Right->key);

    BSTDisplay(HeadNode->Right);
    printf("\r\n");

    return 0;
}