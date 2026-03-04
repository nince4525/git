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
 * @file cosx.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 使用迭代法，用泰勒级数前n项和求cosx
 * @version 1.0
 * @date 2024-10-21
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

/*
 * 如果在Ubuntu下，编译或者调试时出现这个错误：undefined reference to `cos'
 * 那么请手动编译程序，发出如下命令（指明链接数学库）：
 * gcc cosx.c -lm
 */

#include <stdio.h>
#include <math.h>

const double _2pi = 2.0 * 3.1415926;

int main() {
    long n;
    printf("please input n(5~20): ");
    scanf("%ld", &n);
    
    double x;
    printf("please input x: ");
    scanf("%lf", &x);
    x -= (int)(x / _2pi) * _2pi; // 将x缩小到一个2pi以内
    
    double x2 = x * x; // x的平方

    double cosx = 1.0; // cosx的近似值。初值为级数第一项：1
    double a = x2; // 分子。初值为级数第二项的分子：x^2
    double b = 2.0; // 分母，阶乘值。初值为级数第二项的分母：2，即2!
    long sign = -1l; // 当前项的符号

    long i;
    for (i = 2l; i <= 2l * n; i += 2l) { // 从第二项起开始累加
        cosx += sign * a / b;
        a *= x2;
        b *= (i + 1l) * (i + 2l);
        sign *= -1l; // 下一次项反号
    }

    // 输出：迭代次数，程序计算值，库函数值
    printf("iterated: %ld, cosx=%.7lf, cos(x)=%.7lf\n", i / 2l - 1l, cosx, cos(x));

    return 0;
}