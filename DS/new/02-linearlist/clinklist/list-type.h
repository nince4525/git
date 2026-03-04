#pragma once

#define __LIST_TYPE__ "循环单链表"

typedef struct _node {
    ElemType data;
    struct _node  *next;
} Node, *NodePtr, LList, *LListPtr;

