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
 * @file student1.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示结构的定义、结构变量的定义和输入输出
 * @version 1.0
 * @date 2024-11-18
 *
 * @copyright Copyright (c) 白忠建. All rights reserved.
 *
 */

#include <stdio.h>

struct student {
    unsigned long id;    // 学号
    char name[50]; // 姓名
    char gender; // 性别
    int age; // 年龄
};

int main() {
    struct student stu;

    printf("Please input Sid, Name, Gender and Age:\t");
    scanf("%lu %s %c %d", &stu.id, stu.name, &stu.gender, &stu.age);

    printf("SID:\t%lu\n", stu.id);
    printf("Name:\t%s\n", stu.name);
    printf("Gender:\t%c\n", stu.gender);
    printf("Age:\t%d\n", stu.age);

    struct student stu2;
    stu2 = stu; // 结构变量可以整体赋值，即使有数组成员也可以
    printf("SID:\t%lu\n", stu2.id);
    printf("Name:\t%s\n", stu2.name);
    printf("Gender:\t%c\n", stu2.gender);
    printf("Age:\t%d\n", stu2.age);

    return 0;
}