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
 * @file list.h
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 单链表演示程序：头文件
 * @version 1.0
 * @date 2024-11-24
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

// 1. 头文件保护 ------------------------------------------------------------------------------
#pragma once


// 2. 标准库头文件和/或自定义头文件包含 ------------------------------------------------------------------------------
#include <stdbool.h>

#include "elem-type.h"


// 3. 宏定义 ------------------------------------------------------------------------------
// 定义单链表的哨兵是空指针
#define SENTINEL NULL


// 4. 类型定义 ------------------------------------------------------------------------------
// 结点类型的超前声明
struct node; 

// 定义指向结点的指针类型
typedef struct node* nodeptr;

// 定义链表结点类型。与超前声明的类型名应该完全一致
typedef struct node {
    elem_t data;    // 结点的数据域
    nodeptr next;   // 结点的指针域，指向下一个结点
} node;

// 定义单向链表类型，以及指向链表的指针类型
typedef struct {
    nodeptr head;       // 指向头结点的指针
    unsigned length;      // 链表长度。尺寸相关的数据，类型一般都是size_t
} list, *listptr;



// 5. 函数签名 ------------------------------------------------------------------------------
// 链表初始化
extern void list_init(listptr L);

// 销毁链表
extern void list_destroy(listptr L);

// 根据数据文件创建链表
extern void list_create(listptr L, const char *data_file);

// 在链表头部插入结点
extern void list_push_front(listptr L, const elem_t v);

// 在链表尾部插入结点
extern void list_push_back(listptr L, const elem_t v);

// 在链表指定位置插入结点
extern void list_insert(listptr L, int pos, const elem_t v);

// 在链表指定位置删除结点
extern void list_remove(listptr L, int pos);

// 获取链表的长度
extern unsigned list_length(listptr L);

// 判断链表是否为空
extern bool list_empty(listptr L);

// 清空链表
extern void list_clear(listptr L);

// 遍历链表
extern void list_traverse(listptr L);