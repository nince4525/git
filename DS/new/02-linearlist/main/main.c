#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void print(ElemType *e) {
    printf("%4d", *e);
}

int main() {
    LList list, *L = &list;

    printf("==== 正在测试%s ==== \n", __LIST_TYPE__);

    printf("1. 初始化线性表...\n");
    InitList(&L);

    printf("2. 在线性表中插入元素...\n");
    int i;
    for (i = 1; i < 10; ++i)
        InsList(L, i, i + 10);
    printf(">>> 遍历线性表，打印所有元素...\n");
    Traverse(L, print); NL;

    printf("3. 在线性表的不合理位置99插入元素...\n");
    i = 99;
    if (!InsList(L, i, 99))
        printf("   不合理的插入位置：%d\n", i);

    i = 3;
    printf("4. 在线性表中删除位置%d下的元素...\n", i);
    ElemType e;
    DelList(L, i, &e);
    printf(">>> 遍历线性表，打印所有元素...\n");
    Traverse(L, print); NL;

    printf("5. 在线性表的不合理位置99删除元素...\n");
    i = 99;
    if (!DelList(L, i, &e))
        printf("   不合理的删除位置：%d\n", i);

    printf("6. 测试线性表逆序...\n");
    ReverseList(L);
    Traverse(L, print); NL;

    printf("7. 销毁线性表...\n");
    DestroyList(L);

    printf("==== 测试完成 ====\n");

    return 0;
}