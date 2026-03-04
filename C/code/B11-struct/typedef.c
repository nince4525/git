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
 * @file typedef.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示typedef
 * @version 1.0
 * @date 2024-11-18
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

typedef int INT;
typedef char* STRING;
typedef int ARRAYI5[5]; // 数组类型：int [5]
// typedef typeof(int [5]) ARRAYI5; // c23 新特性


int main() {
    INT a = 1; // --> int a = 1;
    STRING b = "hello"; // --> char* b = "hello";
    ARRAYI5 c = {1, 2, 3, 4, 5}; // --> int c[5] = {1, 2, 3, 4, 5};
    
    printf("a = %d, b = %s\n", a, b);

    for (int i = 0; i < 5; ++i)
        printf("%d ", c[i]);
    printf("\n");

    return 0;
}