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
 * @file arr-io.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 压缩的一维数组还原为二维数组
 * @version 1.0
 * @date 2024-10-23
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

#define N   4

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[N][N] = {0};

    int i, j, k = 0;
    for (i = 0; i < N; ++i) {
        for (j = 0; j <= i; ++j) {
            b[i][j] = a[k++];
        }
    }

    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) 
            printf("%3d", b[i][j]);
        putchar('\n');       
    }
    
    return 0;
}