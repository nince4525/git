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
 * @file 100-chicken.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 穷举法：百鸡问题求解
 * @version 1.0
 * @date 2024-10-21
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

int main() {
    int x, y, z; // 分别对应公鸡、母鸡和小鸡的数量

    for (x = 0; x <= 20; ++x) // 公鸡最多 100 / 5 = 20 只
        for (y = 0; y <= 34; ++y) { // 母鸡最多 100 / 3 = 34 只
            z = 100 - x - y; // 剩下的小鸡数量
            if (300 == 15 * x + 9 * y + z)
                printf("rooster=%2d, hen=%2d, chicken=%2d\n", x, y, z);
        }

    return 0;
}