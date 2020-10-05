#include "node.h"

extern void InitializeStack(void);
extern void Push(Node *);
extern Node *Pop(void);
extern int IsStackEmpty();

void InitializeTree(void);
void MakeTree(void);
void Traverse(Node *);
void Visit(Node *);

Node *Parent, *LeftChild, *RightChild;
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
    Parent = (Node *)malloc(sizeof(Node));
    Parent->Data = 'A';

    LeftChild = (Node *)malloc(sizeof(Node));
    LeftChild->Data = 'B';

    RightChild = (Node *)malloc(sizeof(Node));
    RightChild->Data = 'C';

    Parent->Left = LeftChild;
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

void Traverse(Node *ptrNode){
    Push(ptrNode);

    while(!IsStackEmpty()){
        ptrNode = Pop();
        Visit(ptrNode);

        if(ptrNode->Right != EndNode){
            Push(ptrNode->Right);
        }
        if(ptrNode->Left != EndNode){
            Push(ptrNode->Left);
        }
    }
}

void Visit(Node *ptrNode){
    printf("%2d -> ", ptrNode->Data);
}


int main(){
    InitializeStack();
    InitializeTree();
    MakeTree();
    Traverse(HeadNode->Left);
    printf("\r\n");
    return 0;
}
