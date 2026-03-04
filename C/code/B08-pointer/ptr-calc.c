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
 * @file ptr-calc.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示指针运算
 * @version 1.0
 * @date 2024-10-30
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

int main() {
    int i = 0, *p;
    int j = 1, *q;

    // 指针间的赋值
    p = &i; q = &j;
    q = p;
    printf("i=%d, j=%d\t*p=%d, *q=%d\n", i, j, *p, *q); // i=0, j=1        *p=0, *q=0
    
    // 指针指向单元的赋值
    p = &i; q = &j;
    *q = *p;
    printf("i=%d, j=%d\t*p=%d, *q=%d\n", i, j, *p, *q); // i=0, j=0        *p=0, *q=0

    // 指针加减整数
    int n = 2;
    printf("p=%p, p+%d=%p\n", p, n, p + n);

    return 0;
}