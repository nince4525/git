#include <stdio.h>
#include <stdlib.h>

#include "list.h"

//在主程序中，采用了头结点模式使用链表。因此，这里的代码都是基于头结点的

void InitList(LListPtr *L) {
    //生成头结点，并将头结点的指针域置为空
    //TODO
}

bool InsList(LListPtr L, int i, ElemType e) {
    NodePtr p = L;
    int k = 1;
    //从头开始移动工作指针，同时计数，数到i-1，即找到要插入位置的前一个位置
    //TODO

    //如果遍历完了链表，还没有数到i-1，则说明插入位置不合理
    if (/*TODO*/)
        return false;

    //生成新节点并插入到结点p之后
    //

    return true;
}

bool DelList(LListPtr L, int i, ElemType *e) {
    NodePtr p = L;
    int k = 1;

    //TODO

    return true;
}

void DestroyList(LListPtr L) {
    //TODO
}

void Traverse(LListPtr L, CALLBACK f) {
    NodePtr p = L->next;
    while (p != NULL) {
        f(&p->data);
        p = p->next;
    }
}

bool FirstList(LListPtr L, ElemType *e) {
    if (ListEmpty(L)) return false;

    *e = L->next->data;

    return true;
}

bool ListEmpty(LListPtr L) {
    //TODO
    return true;
}

bool ListFull(LListPtr S) {
    return false;
}

void ReverseList(LListPtr L) {
    nope();
}