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
 * @file findmax.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 在一维数组中找到最大值及其下标
 * @version 1.0
 * @date 2024-10-23
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N   30

int main() {
    srand(time(NULL)); // 初始化随机数发生器。只在main函数里调用一次即可

    int a[N];
    int i;

    // 用随机数填充数组
    for (i = 0; i < N; ++i) {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }
    putchar('\n');

    int j = 0; // j存储最大值的下标
    int max = a[j]; // 假设元素j是值最大的那个
    for (i = 0; i < N; ++i)
        if (max < a[i]) { // 如果元素i的值比max大
            max = a[i]; // 记录下当前的最大值及其下标
            j = i;
        }

    printf("max: %d@%d\n", max, j);
    
    return 0;
}