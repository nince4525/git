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
 * @file ptr-array.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 指针数组
 * @version 1.0
 * @date 2024-10-30
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

int main() {
    int a = 5, b = 4, c = 3, d = 2, e = 1;
    int *pa[5] = {&a, &b, &c, &d, &e};

    for (int i = 0; i < 5; i++)
        printf("%p ---> %d\n", pa[i], *pa[i]);

    return 0;
}