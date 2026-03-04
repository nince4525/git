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
 * @file student4.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示嵌套的结构定义
 * @version 1.0
 * @date 2024-11-18
 *
 * @copyright Copyright (c) 白忠建. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>

typedef struct {
    unsigned long id;
    char name[50];
    char gender;
    struct date {
        int year, month, day;
    } dob;
} student;


void print_date(struct date d) {
    printf("%d-%02d-%02d", d.year, d.month, d.day);
}

void print_stu(student stu) {
    printf("SID:\t%lu\n", stu.id);
    printf("Name:\t%s\n", stu.name);
    printf("Gender:\t%c\n", stu.gender);
    printf("DOB:\t"); 
    print_date(stu.dob);
    printf("\n\n");
}

int main() {
    student stu[] = {
        {2024091001, "Zhang", 'M', {2006, 5, 15}},
        {2024091002, "Li", 'F', {2005, 3, 26}},
        {2024091003, "Yang", 'M', {2006, 11, 2}},
        {2024091004, "Peng", 'M', {2006, 7, 31}},
        {2024091005, "Chen", 'F', {2006, 4, 22}}
    };

    for (int i = 0; i < sizeof(stu) / sizeof(student); ++i)
        print_stu(stu[i]);

    return 0;
}