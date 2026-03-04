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
 * @file ptr-const.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示用const修饰指针
 * @version 1.0
 * @date 2024-10-30
 *
 * @copyright Copyright (c) 白忠建. All rights reserved.
 *
 */

#include <stdio.h>

int main() {
    int a = 0, b = 1;

    // 指向常量的变量指针
    { // 形成一个局部块。不同块中的变量可以重名
        const int *p;
        // int const *p; // 和上面一行等价，因为 const int 和 int const 等价
        p = &a; // OK
        printf("*p=%d\n", *p);
        // *p = 1; // error！通过p的视角，它指向的单元是常量
        p = &b; // OK。p是变量，因此可以改变
        printf("*p=%d\n", *p);
    }

    // 常量指针指向变量
    {
        int * const p = &b;  // 指针p是常量，因此必须被初始化。它指向的却是变量
        printf("*p=%d\n", *p);
        ++ *p; // OK
        printf("*p=%d\n", *p);
        // p = &b; // error! p是常量，不能被改变
    }

    // 常量指针指向常量
    {
        const int c = 3;
        const int * const p = &c; // 常量指针必须被初始化
        printf("*p=%d\n", *p);
        // p = &a; // error! p是常量，不能被改变
        // *p = 4; // error！通过p的视角，它指向的单元是常量
    }

    return 0;
}