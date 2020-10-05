#include "node.h"

extern void InitializeQueue(void);
extern void Put(Node *ptrNode);
extern Node *Get(void);
extern int IsQueueEmpty();

void InitializeTree(void);
void MakeTree(void);
void Level_Traverse(Node *);
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
void Level_Traverse(Node *ptrNode){
    Put(ptrNode);
    while(!IsQueueEmpty()){
        ptrNode = Get();
        Visit(ptrNode);

        if(ptrNode->Left != EndNode){
            Put(ptrNode->Left);
        }

        if(ptrNode->Right != EndNode){
            Put(ptrNode->Right);
        }
    }
}

void Visit(Node *ptrNode){
    printf("%2c -> ", ptrNode->Data);
}

int main(){
    InitializeQueue();
    InitializeTree();

    MakeTree();
    printf("Queue step traverse : ");
    Level_Traverse(HeadNode->Left);
    printf("\r\n");

    return 0;
}