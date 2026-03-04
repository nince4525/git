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
 * @file ptr-2-ptr.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示指向指针的指针
 * @version 1.0
 * @date 2024-11-25
 *
 * @copyright Copyright (c) 白忠建. All rights reserved.
 *
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// 这个函数无法正确地修改指针
void make_ptr1(int *p) {
    p = (int *)malloc(sizeof(int) * 10);
}

// 这个函数可以正确地修改指针
void make_ptr2(int **p) {
    *p = (int *)malloc(sizeof(int) * 10);
}

// 这个函数返回指针
int* make_ptr3() {
    return (int *)malloc(sizeof(int) * 10);
}

int main() {
    {
        int *p = NULL;
        make_ptr1(p);
        printf(p == NULL ? "failed\n" : "successful\n"); // failed

        // 分配的内存不会被释放，将导致内存泄露
    }

    {
        int *p = NULL;
        make_ptr2(&p);
        printf(p == NULL ? "failed\n" : "successful\n"); // successful

        free(p);
    }

    {
        int *p = NULL;
        p = make_ptr3();
        printf(p == NULL ? "failed\n" : "successful\n"); // successful

        free(p);
    }

    return 0;
}