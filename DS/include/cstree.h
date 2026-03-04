#pragma once

#include "tree-nodetype.h"

typedef struct CSNode {
    DataType data;
    struct CSNode *FirstChild;
    struct CSNode *NextSibling;
} CSNode, *CSTree;

typedef void CALLBACK(DataType);

extern CSTree CreateCSTree(const char *nodes);
extern void DestroyCSTree(CSTree root);
extern void RootFirst(CSTree root, CALLBACK Visit);
extern void RootLast(CSTree root, CALLBACK Visit);