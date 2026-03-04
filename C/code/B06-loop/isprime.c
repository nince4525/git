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
 * @file isprime.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 穷举法：判断数n是否是素数
 * @version 1.0
 * @date 2024-10-21
 *
 * @copyright Copyright (c) 白忠建. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    printf("please input n: ");
    scanf("%d", &n);

    bool is_prime;

    if (n == 2) {
        is_prime = true;
    } else if (n % 2 == 0) {
        is_prime = false;
    } else {
        is_prime = true;
        for (int i = 3; i <= n / 2; i += 2)
            if (n % i == 0) {
                is_prime = false;
                break;
            }
    }

    printf(is_prime ? "yes\n" : "no\n");

    return 0;
}