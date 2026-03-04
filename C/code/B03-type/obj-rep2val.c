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
 * @file obj-rep2val.cpp
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示对象类型在对象的表示和值之间的核心地位
 * @version 1.0
 * @date 2025-01-01
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

int main() {
    int a = 0b01000100001100110010001001010101; // 0x44332255，对象表示

    printf("0x%x\n", a); // 用（16进制）整数类型解释对象表示，对象的值是整数
    printf("%f\n", *((float*)&a)); // 对象的值用浮点类型解释相同的对象表示，对象的值是浮点数。注：这种解释不总是能成功的
    
    char *p = (char *)&a; // 用字符数组类型解释相同的对象表示，对象的值是字符串
    for (size_t i = 0; i < sizeof(int); ++i)
        printf("'%c'(0x%x) ", p[i], p[i]);
    printf("\n");

    return 0;
}