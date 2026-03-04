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
 * @file int-overflow.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示整型溢出
 * @version 1.0
 * @date 2025-01-01
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

int main() {
    {
        int a = 0b01111111111111111111111111111111; // 0xefffffff
        printf("a = %d\n", a);
        a += 2; // overflow
        printf("a = %d\n", a);
    }

    {
        unsigned a = 0b11111111111111111111111111111111; // 0xffffffff
        printf("a = %u\n", a);
        a += 2; // overflow
        printf("a = %u\n", a);
    }

    return 0;
}