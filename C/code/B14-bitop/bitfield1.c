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
 * @file bitfield1.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示位域
 * @version 1.0
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

typedef struct {
	unsigned day: 5;	//成员day只占据5位
	unsigned month: 4;	//成员month只占据4位
	unsigned year: 23;	//成员year填满剩下的23位
} date;

void print_date(date d) {
    printf("%4d-%02d-%02d\n", d.year, d.month, d.day);
}

int main() {
    date d;

    d.day = 31;
    d.month = 12;
    d.year = 2024;

    print_date(d);

    return 0;
}