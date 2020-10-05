#ifndef __NODE_H__
#define __NODE_H__

#include <stdio.h>
#include <stdlib.h>

#define TRUE        1
#define FALSE       0


typedef struct _Node
{
    char Data;
    struct _Node *Left;
    struct _Node *Right;
} Node;

Node *HeadNode, *EndNode;

#endif