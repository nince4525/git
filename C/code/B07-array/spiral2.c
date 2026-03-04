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
 * @file spiral.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 填充螺旋方阵：变长数组
 * @version 1.0
 * @date 2024-10-23
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

// 方阵行列的最小最大长度
#define MINN    5
#define MAXN    20

// 枚举类型，定义方向
enum { EAST, SOUTH, WEST, NORTH };

// 定义长得像函数的宏
#define STEP_EAST()     (++j)   //向东走一步。实际上是列号自加。以下同理。
#define STEP_SOUTH()    (++i)
#define STEP_WEST()     (--j)
#define STEP_NORTH()    (--i)

int main() {
    int n; // 实际的方阵的长度

    // 用此循环，防止输入不合规的长度
    do {
        printf("please input the length of square matrix:");
        scanf("%d", &n);
    } while (n < MINN || n > MAXN);

    int a[n+2][n+2] = {}; // 定义大一圈的方阵，并全部初始化为0。使用了C99的变长数组（因此初始化列表为空）。
    int i, j;

    // 将最外面一圈全部置为1，表示已填过
    for (i = 0; i < n + 2; ++i) {
        a[i][0] = a[i][n + 1] = 1;
        a[0][i] = a[n + 1][i] = 1;
    }

    i = j = 1; // 从“左上角”开始填起。i：行号，j：列号
    int m = 1;
    int dir = EAST; // 移动方向。初始方向是东
    while (m <= n * n) {
        if (a[i][j] == 0) { // 未填过数
            a[i][j] = m++;

            switch (dir) {
                case EAST:  STEP_EAST();  break;
                case SOUTH: STEP_SOUTH(); break;
                case WEST:  STEP_WEST();  break;
                case NORTH: STEP_NORTH(); break;
            }
        }
        else { // 已填过。这表明上一步走过头了，需要调整到正确的位置并转向
            switch (dir) {
                case EAST:  STEP_WEST();  STEP_SOUTH(); dir = SOUTH; break; // 向东走过头，则正确位置是：退一步并再向下一步。以下同理。
                case SOUTH: STEP_NORTH(); STEP_WEST();  dir = WEST;  break;
                case WEST:  STEP_EAST();  STEP_NORTH(); dir = NORTH; break;
                case NORTH: STEP_SOUTH(); STEP_EAST();  dir = EAST;  break;
            }
        }
    }

    // 打印方阵
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= n; ++j)
            printf("%4d", a[i][j]);
        putchar('\n');
    }

    return 0;
}