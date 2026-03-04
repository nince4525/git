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
 * @file union.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示联合类型的定义，以及和结构类型的对比
 * @version 1.0
 * @date 2024-11-18
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

union {
    int i;
    double d;
} u;

struct {
    int i;
    double d;
} s;

union {
    int i;
    long l;
} n;

int main() {
    printf("sizeof(u) = %d, sizeof(s) = %d\n", sizeof(u), sizeof(s));

//---------------------------------------------------
    u.i = 1;
    printf("u.d = %lf\n", u.d);

    u.d = 3.14;
    printf("u.i = %d\n", u.i);

//---------------------------------------------------
    n.i = 123;
    printf("n.l = %ld\n", n.l);

    n.l = 321l;
    printf("n.i = %d\n", n.i);

    return 0;
}

