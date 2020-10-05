#include "node.h"

extern void InitializeStack();
extern void Push(Node *ptrNode);
extern Node *Pop();
extern int IsStackEmpty();

void InitializeTree(void);
void MakeTree(void);
void Recursive_Traverse(Node *);
void Stack_Traverse(Node *);
void Visit(Node *);

Node *ParentNode, *LeftChild, *RightChild;
Node *HeadNode, *EndNode;

void InitializeTree(void){
    HeadNode = (Node *)malloc(sizeof(Node));
    EndNode = (Node *)malloc(sizeof(Node));

    HeadNode->Left = EndNode;
    HeadNode->Right = EndNode;

    EndNode->Left = EndNode;
    EndNode->Right = EndNode;
}

void MakeTree(void){
    ParentNode = (Node *)malloc(sizeof(Node));
    ParentNode->Data = 'A';

    LeftChild = (Node *)malloc(sizeof(Node));
    LeftChild->Data = 'B';

    RightChild = (Node *)malloc(sizeof(Node));
    RightChild->Data = 'C';

    ParentNode->Left = LeftChild;
    ParentNode->Right = RightChild;

    HeadNode->Left = ParentNode;
    HeadNode->Right = ParentNode;

    ParentNode = ParentNode->Left;

    LeftChild = (Node *)malloc(sizeof(Node));
    LeftChild->Data = 'D';
    LeftChild->Left = EndNode;
    LeftChild->Right = EndNode;

    RightChild = (Node *)malloc(sizeof(Node));
    RightChild->Data = 'E';
    RightChild->Left = EndNode;
    RightChild->Right = EndNode;

    ParentNode->Left = LeftChild;
    ParentNode->Right = RightChild;

    ParentNode = HeadNode->Right->Right;

    LeftChild = (Node *)malloc(sizeof(Node));
    LeftChild->Data = 'F';
    LeftChild->Left = EndNode;
    LeftChild->Right = EndNode;

    RightChild = (Node *)malloc(sizeof(Node));
    RightChild->Data = 'G';
    RightChild->Left = EndNode;
    RightChild->Right = EndNode;

    ParentNode->Left = LeftChild;
    ParentNode->Right = RightChild;
}

void Recursive_Traverse(Node *ptrNode){
    if(ptrNode != EndNode){
        Recursive_Traverse(ptrNode->Left);
        Visit(ptrNode);
        Recursive_Traverse(ptrNode->Right);
    }
}

void Stack_Traverse(Node *ptrNode){
    int Finish = 0;
    do{
        while(ptrNode != EndNode){
            Push(ptrNode);
            ptrNode = ptrNode->Left;
        }
        if(!IsStackEmpty()){
            ptrNode = Pop();
            Visit(ptrNode);
            ptrNode = ptrNode->Right;
        }else{
            Finish = 1;
        }
    }while(!Finish);
}

void Visit(Node *ptrNode){
    printf("%c ->", ptrNode->Data);
}

int main(){
    
    InitializeStack();
    InitializeTree();
    MakeTree();
    
    printf("재귀 호출을 사용한 중위 순회 : ");
    Recursive_Traverse(HeadNode->Left);

    printf("\r\n스택을 사용한 중위 순회 : ");
    Stack_Traverse(HeadNode->Left);
    printf("\r\n");
    
    return 0;
}