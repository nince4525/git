/* 
 * Copyright (c) 2024 白忠建 电子科技大学信息与软件工程学院
 * C语言程序示例 is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2. 
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2 
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PSL v2 for more details. 
 */

/**
 * @file cmp-cascading.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示比较运算符和比较运算符的级联
 * @version 1.0
 * @date 2025-01-03
 * 
 * @copyright Copyright (C) 2025 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

int main() {
    int a = 9, b = 7, c = 5;

    printf("%d, %d\n", a > b, b > c); // 逻辑上正确的，都是真
    printf("%d\n", a > b > c); // 逻辑上错误的，因为 a > b 为真，而 b > c 为假，所以 a > b > c 为假

    return 0;
}