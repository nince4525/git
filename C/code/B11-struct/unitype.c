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
 * @file unitype.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示联合的用途
 * @version 1.0
 * @date 2024-11-18
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

// #define CHR     0
// #define INT     1
// #define DBL     2

typedef enum {CHR = 0, INT, DBL} TYPE;

typedef struct {
	TYPE kind; //类型标签
	union {
		char c;
		int i;
		double d;
	}; //匿名联合，它的成员被认为是外层结构的成员
} unitype;


int main() {
    unitype ua[] = {
        {CHR, {.c = 'a'}},
        {INT, {.i = 123}},
        {DBL, {.d = 3.14}}
    };
    
    for (int i = 0; i < 3; ++i) {
        switch (ua[i].kind) {
            case CHR:
                printf("char: %c\n", ua[i].c);
                break;
                
            case INT:
                printf("int: %d\n", ua[i].i);
                break;
                
            case DBL:
                printf("double: %lf\n", ua[i].d);
                break;
                
            default:
                printf("error!\n");
        }
    }

    return 0;
}