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
 * @file decompose.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 将传入的double数据分解为整数和小数两部分
 * @version 1.0
 * @date 2024-11-06
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

void decompose(double d, int *i, double *f) {
    *i = (int)d; // 强制类型转换
    *f = d - *i;
}

int main() {
    double d;
    scanf("%lf", &d);

    int i; // 整数部分
    double f; // 小数部分
    decompose(d, &i, &f);
    printf("d=%lf, i=%d, f=%lf\n", d, i, f);

    /*
    int *i;
    double *f;
    decompse(d, i, f);  // 错误：i和f都是野指针
    */

    return 0;
}