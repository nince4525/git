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
 * @file stack.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 堆栈的实现：使用全局变量模拟栈
 * @version 1.0
 * @date 2024-11-11
 *
 * @copyright Copyright (c) 白忠建. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 定义栈最大深度
#define STACK_SIZE  100

// 用一维数组模拟栈的存储
int contents[STACK_SIZE];
// 栈顶指针
int top = 0;

/**
 * @brief 栈溢出，退出程序
 * 
 */
void stack_overflow() {
    printf("Stack Overflow\n");
    exit(EXIT_FAILURE);
}

/**
 * @brief 栈空，退出程序
 * 
 */
void stack_underflow() {
    printf("Stack is empty\n");
    exit(EXIT_FAILURE);
}

/**
 * @brief 判断栈是否满
 * 
 * @return true 栈满
 * @return false 栈未满
 */
bool is_full() {
    return top == STACK_SIZE; // TODO
}

/**
 * @brief 判断栈是否空
 * 
 * @return true 栈空
 * @return false 栈未空
 */
bool is_empty() {
    return top == 0; // TODO
}

/**
 * @brief 压栈
 * 
 * @param i 待压栈的元素
 */
void push(int i) {
    if (is_full()) // 如果栈满
        stack_overflow();
    else
        contents[top++] = i; // TODO
}

/**
 * @brief 弹栈
 * 
 * @return int 弹出的元素 
 */
int pop() {
    if (is_empty()) // 如果栈空
        stack_underflow();
    else
        return contents[--top]; // TODO
}

int main() {
    for (int i = 0; i < 5; ++i) push(i);
    
    int v;
    v = pop();
    printf("%d,%d\n", v, pop()); //output 4,3

    return 0;
}