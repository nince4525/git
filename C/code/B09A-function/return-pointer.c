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
 * @file return-pointer.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示函数返回指针
 * @version 1.0
 * @date 2024-11-06
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

int* f(int *a) {
    return a;
}

// 潜在的错误：函数返回局部变量的地址
// 原因：函数返回局部变量的地址，局部变量在函数结束后会被释放，导致返回的地址无效，返回的指针成为悬空指针
int* g() {
    int b = 1;
    return &b;
}

int main() {
    int a = 0;

    int *p = f(&a);
    printf("a=%d\n", *p);

    printf("b=%d\n", *g()); // segment fault
    
    return 0;
}