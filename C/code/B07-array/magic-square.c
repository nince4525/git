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
 * @file magic-square.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 填充奇阶幻方
 * @version 1.0
 * @date 2024-10-23
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

#define MAXN 19

int main() {
    unsigned N;
    do {
        printf("Please input a length(<%d):", MAXN);
        scanf("%d", &N);
    } while (N > MAXN || N % 2 == 0);

	unsigned a[MAXN][MAXN] = {};
	unsigned m = 1;
    int i = 0, j = N / 2; // 不能是unsigned，因为可能得到负值
    while (m <= N * N) {
        if (a[i][j] == 0) { // 如果格子未填过
            a[i][j] = m++;

            --i; ++j; // 向右上角走一步。注意：下标可能超界！
            if (i < 0) i += N;  // 如果向上超界，则卷绕到下面
            if (j >= N) j -= N; // 如果向右超界，则卷绕到左面
        } else { // 格子已填过
            i += 2; --j; // 正确位置在当前错误位置的下2行左边一格。注意：下标可能超界！
            if (i >= N) i -= N; // 如果向下超界，则卷绕到上面
            if (j < 0) j += N; // 如果向左超界，则卷绕到右面
        }
    }

    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j)
            printf("%5d", a[i][j]);
        putchar('\n');
    }

    return 0;
}