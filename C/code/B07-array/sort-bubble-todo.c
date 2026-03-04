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
 * @file sort-bubble.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 一维数组排序：最基本的冒泡排序法
 * @version 1.0
 * @date 2024-10-23
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define N   30

int main() {
    srand(time(NULL)); // 初始化随机数发生器。只在main函数里调用一次即可

    int a[N];
    int i, j;

    // 用随机数填充数组
    for (i = 0; i < N; ++i) {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }
    putchar('\n');

    // TODO

    // END

    for (i = 0; i < N; ++i)
        printf("%d ", a[i]);
    putchar('\n');

    return 0;
}