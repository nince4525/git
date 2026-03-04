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
 * @file swap-by-pointer.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 交换两个数的值：指针作为参数
 * @version 1.0
 * @date 2024-11-06
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

/*
    1. 通过形参指针，间接修改实参
    2. 指针参数具有潜在的将（多个）计算结果携带出函数的能力
*/
void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int main() {
    int a, b;

    scanf("%d%d", &a, &b);
    printf("a=%d, b=%d\n", a, b);
    swap(&a, &b);
    printf("a=%d, b=%d\n", a, b);

    return 0;
}