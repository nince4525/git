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
 * @file fibo.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 求Fibonacci数列的第n项
 * @version 1.0
 * @date 2024-10-18
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

int main() {
    unsigned long n;
    printf("please input n: ");
    scanf("%lu", &n);

    unsigned long f1 = 1lu, f2 = 1lu, f3;
    for (unsigned long i = 3lu; i <= n; ++i) {
        f3 = f2 + f1;
        f1 = f2;
        f2 = f3;
    }

    printf("%lu\n", f3);

    return 0;
}