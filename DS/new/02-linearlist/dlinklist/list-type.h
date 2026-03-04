#pragma once

#define __LIST_TYPE__ "双向链表"

typedef struct _node
{ 
	ElemType data;
	struct _node  *next, *prior;
} Node, *NodePtr, LList, *LListPtr;

