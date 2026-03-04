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
 * @file list-test.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 单链表演示程序：主程序
 * @version 1.0
 * @date 2024-11-24
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "error.h"

void print_list(listptr L) {
    list_traverse(L);
    putchar('\n');
}

int main(int argc, char *argv[]) {
    char *datafile = "data.in"; // 默认的数据文件名
    if (argc == 2) datafile = argv[1]; // 如果命令行指定了数据文件，就用它
        
    // 定义链表对象
    list l, *L = &l;

    // 链表初始化
    list_init(L);

    // 测试链表创建
    list_create(L, datafile);
    printf("=== origin: %u elements\n", list_length(L));
    print_list(L);

    // 测试链表头插入
    elem_t e = -2;
    list_push_front(L, e);
    printf("=== '%d' pushed front: %u elements\n", e, list_length(L));
    print_list(L);

    // 测试链表中间插入
    int pos = 2;
    e = 11;
    list_insert(L, pos, e);
    printf("=== '%d' inserted at %d: %u elements\n", e, pos, list_length(L));
    print_list(L);

    // 测试链表删除
    pos = list_length(L);
    list_remove(L, pos);
    printf("=== 1 element removed at %d: %u elements\n", pos, list_length(L));
    print_list(L);

    // 测试链表尾插入
    e = 10;
    list_push_back(L, e);
    printf("=== '%d' inserted at tail: %u elements\n", e, list_length(L));
    print_list(L);

    // 试图在不正确位置删除，将导致错误
    // list_remove(L, 100);

    // 销毁链表对象
    list_destroy(L);

    // 清除链表，将导致警告
    list_clear(L);
    
    return 0;
}
