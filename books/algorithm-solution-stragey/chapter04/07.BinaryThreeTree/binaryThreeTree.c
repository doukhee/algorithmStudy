#include <stdio.h>
#include <stdlib.h>
#include "node.h"



#define TRUE        1
#define FALSE       0

#define RR          1
#define LL          2


Node *HeadNode;
Node *ParentNode;

void InitializeTree(void);
void InsertNode(int);
Node *SplitNode(Node *, Node *);
void Level_Traverse(Node *);
void Visit(Node *);

extern void InitializeQueue(void);
extern void Put(Node *);
extern Node *Get(void);
extern int IsEmptyQueue();

void InitializeTree(void){
    HeadNode = (Node *)malloc(sizeof(Node));
    HeadNode->Left = HeadNode;
    HeadNode->Right = HeadNode;
    HeadNode->Mid = HeadNode;
}

void InsertNode(int Data){
    int FlagSplit = 0;
    Node *tmpNode;

    if(HeadNode->Right == HeadNode){
        Node *ptrNode = (Node *)malloc(sizeof(Node));

        ptrNode->LeftData = Data;
        ptrNode->RightData = -1;
        ptrNode->Left = HeadNode;
        ptrNode->Right = HeadNode;
        ptrNode->Mid = HeadNode;

        HeadNode->Right = ptrNode;
        HeadNode->Mid = ptrNode;
        HeadNode->Left = ptrNode;
    }else{
        tmpNode = HeadNode->Left;
        ParentNode = HeadNode;

        while(1){
            if(tmpNode->LeftData < Data){
                if(tmpNode->RightData == -1){
                    break;
                }else{
                    if(tmpNode->Left == HeadNode){
                        FlagSplit = 1;
                        break;
                    }else{
                        if(tmpNode->RightData < Data){
                            if(tmpNode->Mid == HeadNode){
                                break;
                            }else{
                                ParentNode = tmpNode;
                                tmpNode = tmpNode->Mid;
                            }
                        }else{
                            if(tmpNode->Mid == HeadNode){
                                break;
                            }else{
                                ParentNode = tmpNode;
                                tmpNode = tmpNode->Mid;
                            }
                        }
                    }
                }
            }else{
                if(tmpNode->Left == HeadNode){
                    if(tmpNode->RightData == -1){
                        FlagSplit = 0;
                    }else{
                        FlagSplit = 1;
                    }
                    break;
                }else{
                    ParentNode = tmpNode;
                    tmpNode = tmpNode->Left;
                }
            }
        }

        if(tmpNode->RightData == -1 && FlagSplit == 0){
            if(tmpNode->LeftData < Data){
                tmpNode->RightData = Data;
            }else{
                tmpNode->RightData = tmpNode->LeftData;
                tmpNode->LeftData = Data;
            }
        }else if(FlagSplit > 0){
            Node *ptrNode = (Node *)malloc(sizeof(Node));

            ptrNode->LeftData = Data;
            ptrNode->RightData = -1;
            ptrNode->Left = HeadNode;
            ptrNode->Mid = HeadNode;
            ptrNode->Right = HeadNode;


            if(FlagSplit == 1){
                ParentNode->Left = SplitNode(tmpNode, ptrNode);
                tmpNode = ParentNode->Left;

                if(ParentNode->RightData == -1){
                    ParentNode->RightData = ParentNode->LeftData;
                    ParentNode->LeftData = tmpNode->LeftData;
                    ParentNode->Right = ParentNode->Mid;
                    ParentNode->Mid = tmpNode->Mid;
                    ParentNode->Left = tmpNode->Left;
                }
            }
        }
    }
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
        if(ptrNode->Mid != HeadNode){
            Put(ptrNode->Mid);
        }
        if(ptrNode->Right != HeadNode){
            Put(ptrNode->Right);
        }
    }
}

Node *SplitNode(Node *tmpNode, Node *ptrNode){
    Node *NewNode = (Node *)malloc(sizeof(Node));
    NewNode->RightData = -1;
    NewNode->Left = HeadNode;
    NewNode->Mid = HeadNode;
    NewNode->Right = HeadNode;

    if(tmpNode->LeftData < ptrNode->LeftData){
        if(ptrNode->LeftData < tmpNode->RightData){
            NewNode->LeftData = tmpNode->RightData;
            tmpNode->RightData = -1;
        }else{
            NewNode->LeftData = ptrNode->LeftData;
            ptrNode->LeftData = tmpNode->RightData;
            tmpNode->RightData = -1;
        }
    }else{
        NewNode->LeftData = tmpNode->RightData;
        tmpNode->RightData = ptrNode->LeftData;
        ptrNode->LeftData = tmpNode->LeftData;
        tmpNode->LeftData = tmpNode->RightData;
        tmpNode->RightData = -1;
    }
    ptrNode->Left = tmpNode;
    ptrNode->Mid = NewNode;

    return ptrNode;
}

void Visit(Node *ptrNode){
    printf("%2d ", ptrNode->LeftData);
    if(ptrNode->RightData != -1){
        printf("%2d ", ptrNode->RightData);
    }
}


int main(){
    InitializeTree();

    InsertNode(10);
    InsertNode(20);
    Level_Traverse(HeadNode->Left);
    printf("\r\n=======================================================\r\n");

    InsertNode(15);
    Level_Traverse(HeadNode->Left);
    printf("\r\n=======================================================\r\n");

    InsertNode(13);
    Level_Traverse(HeadNode->Left);
    printf("\r\n=======================================================\r\n");

    InsertNode(5);
    Level_Traverse(HeadNode->Left);
    printf("\r\n=======================================================\r\n");

    InsertNode(12);
    Level_Traverse(HeadNode->Left);
    printf("\r\n=======================================================\r\n");
    return 0;
}