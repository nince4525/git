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
 * @file sum.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 求 1/1! + 1/2! + 1/3! + ... + 1/n!
 * @version 1.0
 * @date 2024-10-18
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

int main() {
    int n;
    printf("please input n: ");
    scanf("%d", &n);

    double s = 0.0;
    unsigned long fact = 1lu, i;
    i = 1;
    while (i <= n) {
        s += 1.0 / fact;
        ++i;
        fact *= i;
    }

    printf("%lf\n", s);

    return 0;
}