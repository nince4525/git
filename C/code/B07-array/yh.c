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
 * @file yh.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 利用二维数组生成并打印杨辉三角
 * @version 1.0
 * @date 2024-10-23
 *
 * @copyright Copyright (c) 白忠建. All rights reserved.
 *
 */

#include <stdio.h>

#define N   8

int main() {
    int yh[N][N] = {1};
    int i, j;

    for (i = 0; i < N; ++i) {
        yh[i][0] = 1;
        for (j = 1; j <= i; ++j)
            yh[i][j] = yh[i - 1][j - 1] + yh[i - 1][j];
    }

    for (i = 0; i < N; ++i) {
        for (j = 0; j <= i; ++j)
            printf("%4d", yh[i][j]);
        putchar('\n');
    }

    return 0;
}