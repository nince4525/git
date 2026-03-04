#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void InitList(LListPtr *L) {
    (*L) = (NodePtr)malloc(sizeof(Node)); //生成头结点
    (*L)->prior = (*L)->next = NULL; //头结点的指针域为空
}

//请根据教材自行完成下列函数的编码
bool InsList(LListPtr L, int i, ElemType e) {
    NodePtr p = L;
    int k = 1;

    while (p != NULL && k < i) {
        p = p->next;
        ++k;
    }

    if (p == NULL) return false;

    NodePtr s = (NodePtr)malloc(sizeof(Node));
    s->data = e;
    //TODO

    return true;
}

bool DelList(LListPtr L, int i, ElemType *e) {
    NodePtr p = L;
    int k = 1;

    while (p != NULL && k < i) {
        p = p->next;
        ++k;
    }

    if (p == NULL || p->next == NULL) return false;

	//TODO

	free(p);

    return true;
}

void DestroyList(LListPtr L) {
    NodePtr p = L, q;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
}

void Traverse(LListPtr L, CALLBACK f) {
    NodePtr p = L->next;
    while (p != NULL) {
        f(&p->data);
        p = p->next;
    }
}

void ReverseList(LListPtr L) {
    nope();
}