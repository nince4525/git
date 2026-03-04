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
 * @file callback.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示回调函数的使用
 * @version 1.0
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

typedef void callback_t(int *);

void print_v(int *v) {
    printf("%4d", *v);
}

void inc_v(int *v) {
    ++*v;
}

void array_walk(int *a, int n, callback_t visit) {
    for (int *p = a; p != a + n; ++p) visit(p);
}

int main() {
    #define N 10
    int a[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    array_walk(a, N, print_v);
    printf("\n");

    array_walk(a, N, inc_v);
    array_walk(a, N, print_v);
    printf("\n");

    return 0;
}