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
 * @file extern1.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示外部变量的使用。第二部分。
 * @version 1.0
 * @date 2024-11-11
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */


// !!! 本程序需要同时编译两个源文件，才能运行。
// 请不用调试方式运行，而用如下方式手动编译程序：
// gcc extern1.c extern2.c -o extern
// 或者：
// gcc extern*.c -o extern
// 然后用这种方式运行程序：
// ./extern

#include <stdio.h>

extern int a; // 声明变量a来自于另一个源文件。不应该初始化

// extern int b; // 仅声明无问题，一旦求值将导致链接错误！
// extern int g(int); // 仅声明无问题，一旦求值将导致链接错误！

int f() { // 链接属性为external
    // printf("b=%d\n", b); // 链接错误！
    // printf("g(100)=%d\n", g(100)); // 链接错误！
    
    // extern int a; // 外部声明可以放在函数中
    return a * 5;
}

// 这个源文件中不能再有main()函数