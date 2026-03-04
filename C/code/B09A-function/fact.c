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
 * @file fact.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 计算阶乘
 * @version 1.0
 * @date 2024-11-06
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

// 定义本程序用到的数据类型
typedef unsigned long ULONG;

/**
 * @brief 计算阶乘。是阶乘数学模型的直接翻译
 * 
 * @param n 阶乘的基数
 * @return ULONG n的阶乘结果
 */
ULONG fact(ULONG n) {
    // TODO
    ULONG f = 1;
    for (ULONG i = 2; i <= n; i++) {
        f *= i;
    }
    return f;
}

int main() {
    ULONG n;

    scanf("%lu", &n);
    printf("%lu\n", fact(n));

    return 0;
}
