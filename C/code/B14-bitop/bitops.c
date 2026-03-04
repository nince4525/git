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
 * @file bitops.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示位运算
 * @version 1.0
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

typedef char byte;

void println_byte(const char *str, byte b) {
    const byte mask = 0b10000000; // 如果编译器不支持二进制常量，则用0x80

    if (str) printf("%s", str);
    printf("0b");
    for (int i = 0; i < 8; ++i) {
        putchar(b & mask ? '1' : '0');
        b <<= 1;
    }
    putchar('\n');
}

int main() {
    byte a = 0b11000101; // 0xc5
    byte b = 0b10010100; // 0x94

    println_byte("a=\t", a);
    println_byte("b=\t", b);

    println_byte("~a=\t", ~a);
    println_byte("a&b=\t", a & b);
    println_byte("a|b=\t", a | b);
    println_byte("a^b=\t", a ^ b);

    println_byte("a>>2=\t", a >> 2);
    println_byte("b<<3=\t", b << 3);

    return 0;
}