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
 * @file student3.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示使用typedef简化结构定义
 * @version 1.0
 * @date 2024-11-18
 *
 * @copyright Copyright (c) 白忠建. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>

typedef struct student {
    unsigned long id;    // 学号
    char name[50]; // 姓名
    char gender; // 性别
    int age; // 年龄
} student;

void print_stu(student stu) {
    printf("SID:\t%lu\n", stu.id);
    printf("Name:\t%s\n", stu.name);
    printf("Gender:\t%c\n", stu.gender);
    printf("Age:\t%d\n\n", stu.age);
}

student make_student(unsigned long id, char *name, char gender, int age) {
    student s = {id, "", gender, age};
    strcpy(s.name, name);
    return s;
}

int main() {
    student s1 = {2024091001, "Zhang", 'M', 18};
    student s2 = {2024091002, "Li"}; //0初始化规则
    student s3 = {.name = "Wang"}; //C99

    print_stu(s1);
    print_stu(s2);
    print_stu(s3);

    print_stu(make_student(2024091004, "Sun", 'F', 19));

    return 0;
}