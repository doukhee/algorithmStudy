#include <stdio.h>
#include <stdlib.h>
#include "node.h"

#define TRUE            1
#define FALSE           0

#define RR              1
#define LL              2

Node *HeadNode, *ParentNode, *GrandNode, *ChildNode, *BigNode;

void InitializeTree(void);
void InsertNode(int);
int IsBalance(void);
void RR_Rotate(void);
void LL_Rotate(void);
void Level_Traverse(Node *);
void Visit(Node *);


extern void InitializeQueue();
extern void Put(Node *);
extern Node *Get();
extern int IsEmptyQueue();

void InitializeTree(void){
    HeadNode = (Node *)malloc(sizeof(Node));
    HeadNode->Left = HeadNode;
    HeadNode->Right = HeadNode;
    BigNode = HeadNode;
}

void InsertNode(int Data){
    Node *tmpNode;
    Node *ptrNode = (Node *)malloc(sizeof(Node));

    ptrNode->Data = Data;
    ptrNode->balance = 0;
    ptrNode->Left = HeadNode;
    ptrNode->Right = HeadNode;

    if(HeadNode->Right == HeadNode){
        HeadNode->Right = ptrNode;
        HeadNode->Left = ptrNode;
    }else{
        GrandNode = HeadNode;
        ParentNode = HeadNode;
        ChildNode = HeadNode->Right;
        tmpNode = HeadNode->Right;

        while(tmpNode != HeadNode){
            ChildNode = tmpNode;

            if(ChildNode->Data > ptrNode->Data){
                BigNode = GrandNode;

                GrandNode = ParentNode;
                ParentNode = ChildNode;
                tmpNode = tmpNode->Left;
            }else{
                BigNode = GrandNode;
                GrandNode = ParentNode;
                ParentNode = ChildNode;
                tmpNode = tmpNode->Right;
            }
        }

        ChildNode = ptrNode;

        if(ParentNode->Data > ChildNode->Data){
            ParentNode->Left = ChildNode;
            ParentNode->balance++;

            if(GrandNode != HeadNode){
                GrandNode->balance++;
            }
            if(BigNode != HeadNode){
                BigNode->balance++;
            }
        }else{
            ParentNode->Right = ChildNode;
            ParentNode->balance--;
            
            if(GrandNode != HeadNode){
                GrandNode->balance--;
            }

            if(BigNode != HeadNode){
                GrandNode->balance--;
            }
        }

        switch(IsBalance()){
            case RR:
                RR_Rotate();
                break;
            case LL:
                LL_Rotate();
                break;
            default:
                break;
        }
    }
}

int IsBalance(void){
    int ret = 0;
    int LeftCnt = 0;
    int RightCnt = 0;

    Node *ptrNode;
    ptrNode = HeadNode->Right;

    InitializeQueue();
    Put(ptrNode);

    while(!IsEmptyQueue()){
        ptrNode = Get();

        if(ptrNode->balance > 1){
            ret = LL;
            break;
        }else if(ptrNode->balance < -1){
            ret = RR;
            break;
        }
        if(ptrNode->Left != HeadNode){
            Put(ptrNode->Left);
            LeftCnt++;
            RightCnt = 0;
        }
        if(ptrNode->Right != HeadNode){
            Put(ptrNode->Right);
            RightCnt++;
            LeftCnt = 0;
        }
    }
    return ret;
}

void RR_Rotate(void){
    ParentNode = GrandNode->Right;
    ChildNode = ParentNode->Right;

    if(GrandNode->balance == -2){
        BigNode->Right = ParentNode;
        ParentNode->Left = GrandNode;
        GrandNode->Left = HeadNode;
        GrandNode->Right = HeadNode;
    }
    BigNode->balance++;

    ParentNode->balance = 0;
    GrandNode->balance = 0;
    ChildNode->balance = 0;
}

void LL_Rotate(void){
    ParentNode = GrandNode->Left;
    ChildNode = ParentNode->Left;

    if(GrandNode->balance == 2){
        BigNode->Left = ParentNode;
        ParentNode->Right = GrandNode;
        GrandNode->Left = HeadNode;
        GrandNode->Right = HeadNode;
    }

    BigNode->balance--;

    ParentNode->balance = 0;
    GrandNode->balance = 0;
    ChildNode->balance = 0;
}

void Level_Traverse(Node *ptrNode){
    InitializeQueue();
    Put(ptrNode);

    while(!IsEmptyQueue()){
        ptrNode = Get();
        printf(" -> ");
        Visit(ptrNode);

        if(ptrNode->Left != HeadNode){
            Put(ptrNode->Left);
        }
        if(ptrNode->Right != HeadNode){
            Put(ptrNode->Right);
        }
    }
}

void Visit(Node *ptrNode){
    printf("%2d ", ptrNode->Data);
}

int main(){
    InitializeTree();
    printf("Node Insert 30, 20, 40, 10 \r\n");
    InsertNode(30);
    InsertNode(20);
    InsertNode(40);
    InsertNode(10);
    Level_Traverse(HeadNode->Right);
    printf("\r\n====================================\r\n");
    printf("Node Insert 5 \r\n");
    InsertNode(5);
    Level_Traverse(HeadNode->Right);
    printf("\r\n");
    return 0;
}