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
 * @file hanoi.c
 * @author 白忠建 (baizj@uestc.edu.cn)
 * @brief Hanoi塔问题求解。演示递归算法设计
 * @version 0.1
 * @date 2023-11-01
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

/**
 * @brief Hanoi塔问题可以转述为如下数学问题：
 * 根据大片不能盖小片的规则，问题求解可以分为三大部：
 * 1. 将n-1片从 源 移到 辅助 上。这样才能将最大片暴露出来
 * 2. 将最大片从 源 移到 目的 上。一次将最大片移到 目的 上
 * 3. 将n-1片从 辅助 移到 源 上。
 * 
 * 形式化一点，设n阶问题的解决方案是Hanoi(n, A, B, C)。那么：
 *           片数   源  目的  辅助
 * Hanoi(     n,   A,   B,   C) { // 这里，柱子的名字(A/B/C)不重要，重要的是位置 
 *     Hanoi( n-1, A,   C,   B)  // Step 1
 *     Hanoi( 1,   A,   B,   C)  // Step 2
 *     Hanoi( n-1, C,   B,   A)  // Step 3
 * }
 *
 */

/**
 * @brief n阶Hanoi塔问题求解
 * 
 * @param n 片数
 * @param A 源柱子（的代号）
 * @param B 目的柱子（的代号）
 * @param C 辅助柱子（的代号）
 */
void hanoi(unsigned n, char A, char B, char C) {
    if (n == 1) {
        printf("%c ---> %c\n", A, B); // 只有一片，直接移动
        return;
    }

    //     片数   源  目的  辅助
    hanoi(n - 1,  A,  C,   B);  // Step 1
    hanoi(1,      A,  B,   C);  // Step 2
    hanoi(n - 1,  C,  B,   A);  // Step 3
}

int main() {
    unsigned n;

    do {
        printf("How many pieces(1~6)? ");
        scanf("%u", &n);
    } while (n > 6); // 此循环控制n不要太大，否则输出太多

    hanoi(n, 'A', 'B', 'C');

    return 0;
}