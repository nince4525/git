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
 * @file value-of-expr.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 每一个合法的C表达式都要计算出一个值
 * @version 1.0
 * @date 2025-01-03
 * 
 * @copyright Copyright (C) 2025 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

int main() {
    int a = 0, b = 1;

    // 一元运算符
    printf("(a = %d, b = %d) ", a, b);
    printf("-a = %d, +b = %d\n", -a, +b); // 负号和正号

    printf("(a = %d, b = %d) ", a, b);
    printf("!a = %d\n", !a); // 逻辑非

    printf("(a = %d, b = %d) ", a, b);
    printf("++a = %d, b-- = %d\n", ++a, b--); // 前缀++和后缀--

    // 二元运算符
    printf("(a = %d, b = %d) ", a, b);
    printf("'a + b' = %d\n", a + b); 

    printf("(a = %d, b = %d) ", a, b);
    printf("'a -= b' = %d\n", a -= b); // 复合赋值

    printf("(a = %d, b = %d) ", a, b);
    printf("'a && b' = %d\n", a && b); // 逻辑与

    printf("(a = %d, b = %d) ", a, b);
    printf("'a < b' = %d\n", a < b); // 比较

    // 其他运算符
    printf("(a = %d, b = %d) ", a, b);
    printf("'a < b ? a : b' = %d\n", a < b ? a : b); // 三元条件

    printf("(a = %d, b = %d) ", a, b);
    printf("'a, b' = %d\n", (a, b)); // 逗号

    printf("return of printf = %d characters\n", printf("(a = %d, b = %d) ", a, b)); // 函数返回值

    printf("value of compound statement = %d\n", ({
            printf("(a = %d, b = %d) ", a, b);
            a++;
            b += 3;
            a * b; // 这个最后计算的表达式是括号括起的复合语句的值
            // (void)(a * b); // 放开注释会导致编译错误
        }));

    return 0;
}