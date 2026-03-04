/* 
 * Copyright (c) 白忠建 电子科技大学信息与软件工程学院
 * C语言程序示例 is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2. 
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2 
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PSL v2 for more details. 
 */


/**
 * @file list.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 单链表演示程序
 * @version 1.0
 * @date 2024-11-24
 *
 * @copyright Copyright (c) 白忠建. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "list.h"
#include "error.h"

// 内部函数定义 ----------------------------------------------------------------------------------

/**
 * @brief 生成新结点并填充
 *
 * @param v 新结点的数据值
 * @return nodeptr 新结点指针。返回值不能被丢弃
 */
static nodeptr _make_node(elem_t v) {
    nodeptr p = (nodeptr)malloc(sizeof(node)); // 为节点动态分配内存
    p->data = v; // 填充数据域
    p->next = SENTINEL; // 填充指针域
    return p;
}

/**
 * @brief 生成新节点p，然后在当前结点pre后插入结点p。
 *
 * @param L 链表指针
 * @param pre 当前结点
 * @param v 新节点的数据值
 */
static void _link_after(listptr L, nodeptr pre, const elem_t v) {
    /*
     * 如图所示，节点X插入到A之后、B之前
     * 插入前：
     * ---> A ---> B ---> C ---> ...
     *      ↑
     *     pre     p ---> X ---> NULL
     *
     * 插入后：
     * ---> A      B ---> C ---> ...
     *      ↑\      ↖_______
     *      | \__________   \
     *      |            ↘   |
     *     pre     p ---> X -+
     */
    // TODO：4条语句：创建新节点、链接结点、改变链表长度
    nodeptr p = _make_node(v);
    p->next = pre->next;
    pre->next = p;
    ++L->length;
    // END
}

/**
 * @brief 指针从当前位置p向前移动n步
 *
 * @param L 链表指针
 * @param p 指向结点的指针
 * @param n 步数
 * @return nodeptr 移动后的结点指针。返回值不能被丢弃
 */
static nodeptr _advance(listptr L, nodeptr p, int n) {
    if (n < 0 || n > L->length)
        error("invalid advancing step %d\n", n);

    // TODO：1条语句：p指针后移
    for (int i = 0; i < n; ++i) p = p->next;
    // END

    return p;
}

/**
 * @brief 在当前结点pre之后删除结点。
 *
 * @param L 链表指针
 * @param pre 当前结点
 */
static void _remove_after(listptr L, nodeptr pre) {
    /*
     * 删除前：
     * ---> A ---> B ---> C ---> ...
     *      ↑      ↑
     *     pre     p
     *
     * 删除后：
     *             X
     * ---> A      B      C ---> ...
     *      ↑\___________↗
     *      |
     *     pre
     */
    // TODO：链接结点、释放结点、改变链表长度
    nodeptr p = pre->next;
    pre->next = p->next;
    free(p);
    --L->length;
    // END
}


// 接口函数实现 ----------------------------------------------------------------------------------

/**
 * @brief 链表初始化。生成链表的头结点
 *
 * @param L 链表指针
 */
void list_init(listptr L) {
    L->head = _make_node(ZERO); // 创建头结点，并用head指针指向
    L->length = 0; // 初始化长度为0
}

/**
 * @brief 销毁链表
 *
 * @param L 链表指针
 */
void list_destroy(listptr L) {
    list_clear(L);
    free(L->head);
}

/**
 * @brief 根据数组创建链表
 *
 * @param L 链表指针
 * @param data_file 保存数据的文件名
 */
 void list_create(listptr L, const char *data_file) {
    // 注意：数据文件最后尽量不要有空行
    FILE *fp = fopen(data_file, "rt");
    if (!fp) error("create: cannot open file %s", data_file);

    // 在链表尾部追加结点
    elem_t t;
    nodeptr tail = L->head; // 先让tail指针指向头结点，
    while (!feof(fp)) { // 如果没有读到文件尾
        fscanf(fp, "%d", &t); // 从文件读入一个数据
        _link_after(L, tail, t); // 在tail结点后插入新结点
        tail = tail->next; // tail指针后移，使之始终指向最有一个结点
    }
    tail->next = SENTINEL; // 为链表添加哨兵

    fclose(fp);
}

/**
 * @brief 在链表头部插入结点
 *
 * @param L 链表指针
 * @param v 数据值
 */
void list_push_front(listptr L, const elem_t v) {
    // TODO：1条语句：将新节点链在头结点之后
    _link_after(L, L->head, v);
    // END
}

/**
 * @brief 在链表尾部插入结点
 *
 * @param L 链表指针
 * @param v 数据值
 */
void list_push_back(listptr L, const elem_t v) {
    list_insert(L, list_length(L) + 1, v);
}

/**
 * @brief 在指定位置插入结点
 *
 * @param L 链表指针
 * @param pos 位置。从1开始
 * @param v 数据值
 */
void list_insert(listptr L, int pos, const elem_t v) {
    // TODO：2条语句：移动指针到指定位置，然后在此位置后插入新结点
    nodeptr pre = _advance(L, L->head, pos - 1);
    _link_after(L, pre, v);
    // END
}

// 在链表指定位置删除结点
void list_remove(listptr L, int pos) {
    // TODO：2条语句：移动指针到指定位置，然后在此位置后删除结点
    nodeptr pre = _advance(L, L->head, pos - 1);
    _remove_after(L, pre);
    // END
}

/**
 * @brief 获取链表的长度
 *
 * @param L 链表指针
 * @return unsigned 链表长度
 */
unsigned list_length(listptr L) {
    return L->length;
}

/**
 * @brief 判断链表是否为空
 *
 * @param L 链表指针
 * @return bool 为空返回true，否则返回false
 */
bool list_empty(listptr L) {
    return L->length == 0;
}

/**
 * @brief 清空链表
 *
 * @param L 链表指针
 */
void list_clear(listptr L) {
    if (list_empty(L)) {
        warning("clear: empty list");
        return;
    }

    // TODO：2条语句：遍历链表，删除每个结点；链表封尾
    while (!list_empty(L))
        _remove_after(L, L->head);
    L->head->next = SENTINEL;
    // END
}

/**
 * @brief 遍历链表
 *
 * @param L 链表指针
 */
void list_traverse(listptr L) {
    for (nodeptr p = L->head->next; p != SENTINEL; p = p->next) {
        printf("%4d", p->data);
    }
}