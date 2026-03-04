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
 * @file var-static.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 静态变量：全局的和局部的
 * @version 1.0
 * @date 2024-11-11
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

// 全局变量（无论有没有static修饰）和静态局部变量具有静态存储期，即程序开始它们就存在，程序结束它们才失效
// 静态变量一般需要初始化。如果没有显式初始化，则编译器使用0初始化规则


// i是不用static修饰的全局变量。具有潜在的外部链接属性
int i; // i -> 0

void print_static(int j) {
    // 此函数中，全局变量i被掩蔽了
    
    static int i = 0; // 静态局部变量 
    
    printf("static: %d\n", (i++) + j); // 注意：后缀表达式
    // 静态变量i的作用域至此
    // 但它的存储期没有结束，因此保留了此次计算的结果
}

// j是用static修饰的全局变量。作用域被限制在本源程序文件中，不具有外部链接属性
// j对前面的所有函数（例如函数print_static）是不可见的
static int j = 1; 

// 调用这个函数将把i和j的改变广播到其他函数
void print_inc_global() { 
    // 使用全局i和j
    printf("global: i=%d, j=%d\n", ++i, ++j);
}

// 调用这个函数将把i和j的改变广播到其他函数
void print_global() {
    // 使用全局i和j
    printf("global: i=%d, j=%d\n", --i, --j);
}

int main() {
    for (int j = 0; j < 3; ++j) // 这条语句将掩蔽全局变量j
        print_static(j); // 依次输出：0 2 4
    
    ++j; // j -> 2
    print_inc_global(); // 输出：i=1, j=3
    print_global(); // 输出：i=0, j=2
    
    return 0;
}