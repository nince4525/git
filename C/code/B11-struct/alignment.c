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
 * @file alignment.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示结构及其成员的对齐方式
 * @version 1.0
 * @date 2025-11-03
 *
 * @copyright Copyright (c) 白忠建. All rights reserved.
 *
 */

#include <stdio.h>

//如果gcc不支持C23
#if __STDC_VERSION__ < 202311L
#include <stdalign.h>
#endif

/*
 * 背景知识：alignof和alignas运算符。设T是一种类型，t是T类型的对象，则
 * - alignof(T) 或 alignof(t) 用于获取类型T（或其对象）的对齐方式
 * - alignas(T) 或 alignas(t) 用于指定类型T（或其对象）的对齐方式
 * 
 * 简单类型（含指针）T的默认对齐值 = T类型的大小
 * 即有：default alignof(T) == sizeof(T) 
 * 注意：对齐方式不影响对象的大小!!!
 */

//以下描述的是结构的对齐方式
//结构的对齐值 = 成员对齐值中的最大者

//默认对齐
struct A {   //结构对齐按成员i的对齐：4 字节对齐
    char ch; //默认 1 字节对齐
    //为使i达成默认的 4 字节对齐，这里需填充 3 字节
    int i;   //默认 4 字节对齐
    //以上总字节数 = 1 + 3(padding) + 4 = 8
    //满足结构 4 字节对齐要求，因此这里不需要填充
} a; //大小：1 + 3(padding) + 4 = 8

//指定成员的对齐方式
struct B {   //结构 16 字节对齐，即成员ch的对齐
    alignas(16) char ch; //指定 16 字节对齐
    //为使i达成默认的 4 字节对齐，这里需填充 3 字节
    int i; //默认 4 字节对齐
    //以上总字节数 = 1 + 3(padding) + 4 = 8
    //为使结构达成 16 字节对齐，这里需要填充 8 字节
} b; //大小：1 + 3(padding) + 4 + 8(padding) = 16

//指定成员的对齐方式
struct C {   //结构 8 字节对齐，即成员i的对齐
    char ch; //默认 1 字节对齐
    //为使i达成指定的 8 字节对齐，这里需填充 7 字节
    alignas(8) int i; //指定 8 字节对齐
    //以上总字节数 = 1 + 7(padding) + 4 = 12
    //为使结构达成 8 字节对齐，这里需要填充 4 字节
} c; //大小：1 + 7(padding) + 4 + 4(padding) = 16

//指定结构的对齐方式
alignas(8) struct D { //结构指定 8 字节对齐
    char ch; //默认 1 字节对齐
    //为使i达成默认的 4 字节对齐，这里需填充 3 字节
    int i;   //默认 4 字节对齐
    //以上总字节数 = 1 + 3(padding) + 4 = 8
    //满足结构 8 字节对齐要求，因此这里不需要填充
} d; //大小：1 + 3(padding) + 4 = 8


//指定对象对齐方式为1字节。pack的参数必须是2的幂数
#pragma pack(1)

//上述指令仅对E有效
struct E {   //结构 1 字节对齐
    char ch; //默认 1 字节对齐
    //没有填充
    int i;   //默认 1 字节对齐
    //没有填充
} e; //大小：1 + 4 = 5

#define show_info(s) { \
    printf("=== %s ===\n", #s); \
    printf("align = %lu, size = %lu\n", alignof(s), sizeof(s)); \
    printf("alignof(.ch) = %lu, alignof(.i) = %lu\n", alignof(s.ch), alignof(s.i)); \
    printf("padding between .ch and .i = %lu\n\n", (void*)&s.i - (void*)&s.ch - sizeof(char)); \
}

int main() {
    printf("=== default alignment ===\nalignof(char) = %lu, alignof(short) = %lu, alignof(int) = %lu, alignof(long) = %lu\n"
        "alignof(float) = %lu, alignof(double) = %lu, alignof(void*) = %lu\n\n", 
        alignof(char), alignof(short), alignof(int), alignof(long), alignof(float), alignof(double), alignof(void*));

    printf("=== total size of members = %lu\n\n", sizeof(char) + sizeof(int));

    show_info(a);
    show_info(b);
    show_info(c);
    show_info(d);
    show_info(e);

    return 0;
}