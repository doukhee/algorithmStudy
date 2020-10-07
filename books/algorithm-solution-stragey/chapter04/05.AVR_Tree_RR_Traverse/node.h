#ifndef __NODE_H__
#define __NODE_H__

#include <stdio.h>

#define TRUE            1
#define FALSE           0

typedef struct _Node{
    char Data;
    int Balance;
    struct _Node *Left;
    struct _Node *Right;
} Node;

Node *HeadNode, *EndNode;

#endif