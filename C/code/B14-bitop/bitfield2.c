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
 * @file bitfield2.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示位域
 * @version 1.0
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>
#include <inttypes.h>

// 地址类型：整数，点分十进制
typedef enum {INT_ADDR, DOT_ADDR} ip_type;

// 下面联合类型的两个成员共享一个内存区域
// 通过这个特性，可以将32位整数IP地址分解成点分十进制地址的4个字节
// 同理，也可以将点分十进制地址的4个字节合成为一个32位整数IP地址
typedef union {
	uint32_t ip32;
    struct { // 这个位域是匿名的，那么它的成员将被视为是union的成员
        unsigned byte3: 8; // 注意：字节序与系统有关。这是 x86_64 的例子，小端序
        unsigned byte2: 8; // 数的低字节在低地址存放，高字节在高地址存放，这种顺序称为小端序（little endian）
        unsigned byte1: 8;
        unsigned byte0: 8; // 如果你的系统是大端序，那么将这四个域的定义顺序调整颠倒一下
    };
} ip_address;

void print_ip_address(ip_address ip, ip_type type) {
    switch (type) {
    case INT_ADDR:
        printf("%u\n", ip.ip32);
        break;

    case DOT_ADDR:
        printf("%d.%d.%d.%d\n", ip.byte0, ip.byte1, ip.byte2, ip.byte3);
        break;

    default:
        printf("wrong ip type\n");
    }
}

int main() {
    ip_address ip = {.byte0 = 192, .byte1 = 168, .byte2 = 1, .byte3 = 1};

    print_ip_address(ip, INT_ADDR);
    print_ip_address(ip, DOT_ADDR);

    ip.ip32 += 35;
    print_ip_address(ip, INT_ADDR);
    print_ip_address(ip, DOT_ADDR);

    return 0;
}