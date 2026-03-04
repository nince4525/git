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
 * @file lvalue-rvalue.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示左值和右值
 * @version 1.0
 * @date 2025-01-03
 * 
 * @copyright Copyright (C) 2025 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

int five() {
    return 5;
}

int main() {
    int a = 0, b = 3, c = 5;

    a ++; // OK 变量元表达式的结果是左值
    (a) = b; // OK (变量元表达式)的结果是左值

    // ++2; // error 字面常量元表达式的结果是右值
    // "abc" = "cdef"; // error 字符串字面量的类型是数组类型，数组类型的直接赋值是错误的
    // (a + b) = c; // error (算数表达式)的结果是右值
    // five() = b; // error five()函数返回右值
    // ++(a = b); // error 赋值表达式的结果是右值
    // (a *= b) = c; // error 复合赋值表达式的结果是右值
    // a + b = c; // error 算数表达式的结果是右值
    // ++ a ++; // error 自加表达式的结果是右值
    // ++ +a; // error 正负号运算符的结果是右值
    // (a, b) = c; // error 逗号运算符的结果是右值
    // (a > b ? a : b) = c; // error 条件运算符的结果是右值
    // a > b = c; // error 比较运算符的结果是右值
    // a && b = c; // error 逻辑运算符的结果是右值
    // (double)a = 3.14; // error 类型强制转换运算符的结果是右值

    const int d = 7;
    // ++d; // error 被const约束的对象是只读的
    
    printf("a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);

    return 0;
}