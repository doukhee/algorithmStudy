#include "node.h"

extern void InitializeStack();
extern void Push(Node *ptrNode);
extern Node *Pop(void);
extern int IsStackEmpty();

void InitializeTree(void);
void MakeTree(void);
void Recursive_Traverse(Node *);
void Stack_Traverse(Node *);
void Visit(Node *);

Node *Parent, *LeftChild, *RightChild, *HeadNode, *EndNode;

void InitializeTree(void){
    HeadNode = (Node *)malloc(sizeof(Node));
    EndNode = (Node *)malloc(sizeof(Node));
    
    HeadNode->Left = EndNode;
    HeadNode->Right = EndNode;

    EndNode->Left = EndNode;
    EndNode->Right = EndNode;
}

void MakeTree(void){
    Parent = (Node *)malloc(sizeof(Node));
    Parent->Data = 'A';

    LeftChild = (Node *)malloc(sizeof(Node));
    LeftChild->Data = 'B';
    Parent->Left = LeftChild;

    RightChild = (Node *)malloc(sizeof(Node));
    RightChild->Data = 'C';
    Parent->Right = RightChild;

    HeadNode->Left = Parent;
    HeadNode->Right = Parent;

    Parent = Parent->Left;

    LeftChild = (Node *)malloc(sizeof(Node));
    LeftChild->Data = 'D';
    LeftChild->Left = EndNode;
    LeftChild->Right = EndNode;

    RightChild = (Node *)malloc(sizeof(Node));
    RightChild->Data = 'E';
    RightChild->Left = EndNode;
    RightChild->Right = EndNode;

    Parent->Left = LeftChild;
    Parent->Right = RightChild;
    Parent = HeadNode->Right->Right;

    LeftChild = (Node *)malloc(sizeof(Node));
    LeftChild->Data = 'F';
    LeftChild->Left = EndNode;
    LeftChild->Right = EndNode;

    RightChild = (Node *)malloc(sizeof(Node));
    RightChild->Data = 'G';
    RightChild->Left = EndNode;
    RightChild->Right = EndNode;

    Parent->Left = LeftChild;
    Parent->Right = RightChild;
}

void Recursive_Traverse(Node *ptrNode){
    if(ptrNode != EndNode){
        Recursive_Traverse(ptrNode->Left);
        Recursive_Traverse(ptrNode->Right);
        Visit(ptrNode);
    }
}

void Stack_Traverse(Node *ptrNode){
    int Finish = 0;
    Node *ptrVisited = EndNode;
    Node *ptrPushed = EndNode;

    do{
        while(ptrNode != EndNode && ptrNode != ptrVisited){
            if(ptrNode != ptrPushed){
                Push(ptrNode);
            }

            if(ptrNode->Right != EndNode){
                Push(ptrNode->Right);
            }

            if(ptrNode->Left != EndNode){
                Push(ptrNode->Left);
            }
            ptrPushed = ptrNode->Left;
            ptrNode = ptrNode->Left;
        }

        if(!IsStackEmpty()){
            ptrNode = Pop();

            if(ptrNode->Left != EndNode && ptrNode->Right == EndNode && ptrNode->Left != ptrVisited){
                Push(ptrNode);
                ptrNode = ptrNode->Left;
            }

            if(ptrNode->Right == EndNode || ptrNode->Right == ptrVisited){
                Visit(ptrNode);
                ptrVisited = ptrNode;
            }
        }else{
            Finish = 1;
        }
    }while(!Finish);
}

void Visit(Node *ptrNode){
    printf("%2c ->", ptrNode->Data);
}

int main(){
    InitializeStack();
    InitializeTree();
    MakeTree();
    printf("재귀 호출을 사용한 후위 순회 : ");
    Recursive_Traverse(HeadNode->Left);
    printf("\r\n스택을 사용한 후위 순회 : ");
    Stack_Traverse(HeadNode->Left);
    printf("\r\n");
    return 0;
}