#include <stdbool.h>

#include "list.h"
#include "list-type.h"

//为了和其他类型的线性表保持一直，这里的参数使用了指针的指针
void InitList(LListPtr *L) {
    //TODO
}

bool InsList(LListPtr L, int i, ElemType e) {
    //当插入位置不合理时
    if (i < 1 || i > L->last + 2)
        return false;

    //TODO

    return true;
}

bool DelList(LListPtr L, int i, ElemType *e) {
    if (/*TODO*/)
        return false;

    *e = L->elem[i - 1];
    //TODO

    return true;
}

void DestroyList(LListPtr L) {
    //顺序表采用了数组作为存储，因此在销毁时不需要做任何事情
}

//参数f是个回调函数
void Traverse(LListPtr L, CALLBACK f) {
    for (int i = 0; i <= L->last; ++i)
        f(&L->elem[i]); //调用f函数处理表的元素
}

void ReverseList(LListPtr L) {
    nope();
}