#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void InitList(LListPtr *L) {
    (*L) = (NodePtr)malloc(sizeof(Node));
    //TODO
}

bool InsList(LListPtr L, int i, ElemType e) {
    NodePtr p = NULL; //TODO
    int k = 1; //TODO

    //TODO

    if (1 /*TODO*/) return false;

    NodePtr q = (NodePtr)malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;

    return true;
}

bool DelList(LListPtr L, int i, ElemType *e) {
    //TODO

    NodePtr q = p->next;
    p->next = q->next;
    free(q);
    
    return true;
}

void DestroyList(LListPtr L) {
    NodePtr p = L, q;
    do { //请大家思考，为什么这里要用到do...while，而不是while？
        q = p;
        p = p->next;
        free(q);
    } while (p != L);
}

void Traverse(LListPtr L, CALLBACK f) {
    for (LListPtr p = L->next; p != L; p = p->next)
        f(&p->data);
}

void ReverseList(LListPtr L) {
    nope();
}