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
 * @file ptr-2-function.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示指向函数的指针
 * @version 1.0
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

// 定义函数类型的别名
typedef int FN(int);
// typedef typeof(int (int)) FN;

// 定义指向函数的指针类型的别名
typedef int (*FPTR)(int);
// typedef typeof(int (*)(int)) FPTR;

int f(int x) {
    return ++x;
}

int g1(int fn(int), int x) {
    return fn(x);
}

int g2(FN fn, int x) {
    return fn(x);
}

int g3(int (*fn)(int), int x) {
    return fn(x); // => (*fn)(x)
}

int g4(FPTR fn, int x) {
    return fn(x); // => (*fn)(x)
}

int main() {
    FPTR fp = f; // => fp = &f;
    printf("%d, %d, %d, %d\n", g1(f, 1), g2(f, 1), g3(fp, 1), g4(fp, 1));

    return 0;
}