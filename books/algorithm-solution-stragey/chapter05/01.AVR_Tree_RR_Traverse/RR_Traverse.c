#include <stdio.h>
#include <stdlib.h>
#include "node.h"

#define TRUE        1
#define FALSE       0

Node *HeadNode;
Node *ParentNode;
Node *GrandNode;
Node *ChildNode;
Node *BigNode;

void InitializeTree(void);
void InsertNode(int);
int IsBalance(void);
void RR_Rotate(void);
void Level_Traverse(Node *);
void Visit(Node *);

extern void InitializeQueue(void);
extern void Put(Node *);
extern Node *Get(void);
extern int IsEmptyQueue(void);

void InitializeTree(void){
    HeadNode = (Node *)malloc(sizeof(Node));
    HeadNode->Left = HeadNode;
    HeadNode->Right = HeadNode;
    BigNode = HeadNode;
}

void InsertNode(int Data){
    Node *tempNode;
    Node *ptrNode = (Node *)malloc(sizeof(Node));
    ptrNode->Data = Data;
    ptrNode->Balance = 0;
    ptrNode->Left = HeadNode;
    ptrNode->Right = HeadNode;

    if(HeadNode->Right == HeadNode){
        HeadNode->Right = ptrNode;
        HeadNode->Left = ptrNode;
    }else{
        GrandNode = HeadNode;
        ParentNode = HeadNode;
        ChildNode = HeadNode->Right;
        tempNode = HeadNode->Right;

        while(tempNode != HeadNode){
            ChildNode = tempNode;

            if(ChildNode->Data > ptrNode->Data){
                BigNode = GrandNode;
                GrandNode = ParentNode;
                ParentNode = ChildNode;
                tempNode = tempNode->Left;
            }else{
                BigNode = GrandNode;
                GrandNode = ParentNode;
                ParentNode = ChildNode;
                tempNode = tempNode->Right;
            }
        }

        ChildNode = ptrNode;

        if(ParentNode->Data > ChildNode->Data){
            ParentNode->Left = ChildNode;
            ParentNode->Balance++;

            if(GrandNode != HeadNode){
                GrandNode->Balance++;
            }

        }else{
            ParentNode->Right = ChildNode;
            ParentNode->Balance--;
            
            if(GrandNode != HeadNode){
                GrandNode->Balance--;
            }

        }

        if(GrandNode != HeadNode){
            RR_Rotate();
        }
    }
}

int IsBalance(void){
    int ret = TRUE;
    Node *ptrNode;
    ptrNode = HeadNode->Right;

    InitializeQueue();
    Put(ptrNode);

    while(!IsEmptyQueue()){
        ptrNode = Get();

        if(ptrNode->Balance > 1 || ptrNode->Balance < -1){
            ret = FALSE;
            break;
        }
        if(ptrNode->Left != HeadNode){
            Put(ptrNode->Left);
        }
        if(ptrNode->Right != HeadNode){
            Put(ptrNode->Right);
        }
    }
    return ret;
}

void RR_Rotate(void){
    ParentNode = GrandNode->Right;
    ChildNode = ParentNode->Right;;

    if(GrandNode->Balance == -2){
        BigNode->Right = ParentNode;
        ParentNode->Left = GrandNode;
        GrandNode->Left = HeadNode;
        GrandNode->Right = HeadNode;
    }
    BigNode->Balance++;
    ParentNode->Balance = 0;
    GrandNode->Balance = 0;
    ChildNode->Balance = 0;
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
    printf("node 10 add 20 insert\r\n");

    InsertNode(10);
    InsertNode(20);

    Level_Traverse(HeadNode->Right);
    printf("\r\n====================================\r\n");
    printf("Insert node 30\r\n");
    InsertNode(30);

    Level_Traverse(HeadNode->Right);
    printf("\r\n");
}