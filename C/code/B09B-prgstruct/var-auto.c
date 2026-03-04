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
 * @file var-auto.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 自动变量
 * @version 1.0
 * @date 2024-11-11
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

void print_i(int i) { // 形参i具有自动存储期
    printf("%d\n", i);
} // 形参i的作用域和存储期至此截止

int main() {
    // 在{}之间定义的变量具有自动存储期
    int i = -1; // 1
    print_i(i); // 输出：-1

    {
        int i = 1; // 2  掩蔽1中定义的i
        print_i(i); // 输出：1
    } // 2中定义的i的作用域和存储期至此截止

    for (int i = 20; i <= 60; i += 20) 
        print_i(i); // 3 掩蔽1、2中定义的i。输出：20 40 60
    // 3中定义的i的作用域和存储期至此截止
    
    print_i(++i); // 使用1中的i。输出：0

    // 冷门知识
    // 如果复合语句（语句块）被一对()括起，且块中最后一条语句至少包含一个可以得到值的表达式
    // 那么这条复合语句将产生一个结果，这个结果就是最后一个被计算的表达式的值
    int j = ({ // 这是一条用{}括起来的复合语句（语句块）。此语句又被()括起来
        print_i(--i); // i = -1。输出：-1
        (void)i; // 避免编译器警告。这条语句无实质效果，结果被丢弃
        0, --i; // 最后一条由逗号表达式构成的语句，包含两个可得结果的表达式 0和--i。最终结果最后一个被计算的表达式--i的值，即-2
        // print_i(--i); // 如果这是最后一条语句，那么将会导致编译错误，因为该函数的返回值类型是void
    }); // j = -2
    printf("j=%d\n", j);
    
    return 0;
    // 1中定义的i的作用域和存储期至此截止
}