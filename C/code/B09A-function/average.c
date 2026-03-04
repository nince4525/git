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
 * @file average.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 求两个数的平均值
 * @version 1.0
 * @date 2024-11-06
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

// 原型声明
double average2(double x, double y);

// 原型声明中的参数可以只有类型，没有名字
// 但这是不推荐的方式，因为很难猜到每个参数的用途
// 函数声明可以只有原型声明但没有定义。只要不调用它就没有问题
double average3(double, double);

// 函数定义隐含了原型声明
double average(double x, double y) {
    return (x + y) / 2.0;
}

int main() {
    // double average2(double x, double y); // 原型声明可以放在函数里

    double a, b;
    scanf("%lf%lf", &a, &b);

    double c = average(a, b);
    printf("avg=%lf\n", c);
    printf("avg2=%lf\n", average2(a, b));

    return 0;
}

double average2(double x, double y) {
    return (x + y) / 2.0;
}