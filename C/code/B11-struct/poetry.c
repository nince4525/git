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
 * @file poetry.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示结构数组的使用
 * @version 1.0
 * @date 2025-11-05
 *
 * @copyright Copyright (c) 白忠建. All rights reserved.
 *
 */

/*
 * 在Windows下使用mingw gcc编译时，使用如下命令：
 * gcc -finput-charset=utf-8 -fexec-charset=gbk poetry.c
 */

#include <stdio.h>
#include <string.h>

#define MAX_VERSES 20

// 定义诗句结构类型
typedef struct {
    unsigned id;    // 诗句的id
    unsigned char verse[41]; // 诗句
} verse_t;

// 定义诗词结构类型
typedef struct {
    char poet[21];  // 诗人
    char title[61]; // 标题
    unsigned lines; // 诗句数
    verse_t verses[MAX_VERSES]; // 诗句
} poetry_t;

/**
 * @brief 数组排序
 *
 * @param poetry 诗词
 */
void sort_poetry(poetry_t *poetry) {
    int i, j;
    verse_t t;

    // TODO

    verse_t *p = poetry->verses;
    int n = poetry->lines;
    for (i = 0; i < n - 1; ++i) {
        for (j = 0; j < n - i - 1; ++j) {
            if (p[j].id > p[j + 1].id) {
                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }
    }

    // END
}

/**
 * @brief 打印诗词信息
 *
 * @param poetry 诗词
 */
void print_poetry(poetry_t *poetry) {
    sort_poetry(poetry); //先排序在打印

    printf("\033[91m%s•《%s》\033[0m\n", poetry->poet, poetry->title);
    printf("\033[90m================\033[0m\n");
    for (int i = 0; i < poetry->lines; ++i)
        puts(poetry->verses[i].verse);
}

int main() {
    // 定义结构数组并初始化
    // 高版本C标准允许使用UTF-8字符作为标志符名
    poetry_t 苏轼_定风波 = {
        "苏轼", "定风波", 11,
        {
            8,  "山头斜照却相迎。",
            4,  "谁怕？",
            5,  "一蓑烟雨任平生。",
            2,  "何妨吟啸且徐行。",
            11, "也无风雨也无晴。",
            6,  "料峭春风吹酒醒，",
            3,  "竹杖芒鞋轻胜马，",
            10, "归去，",
            9,  "回首向来萧瑟处，",
            1,  "莫听穿林打叶声，",
            7,  "微冷，",
        }
    };

    poetry_t 杜甫_登高 = {
        "杜甫", "登高", 8,
        {
            5, "万里悲秋常作客，", 
            7, "艰难苦恨繁霜鬓，",
            2, "渚清沙白鸟飞回。",
            8, "潦倒新停浊酒杯。",
            4, "不尽长江滚滚来。",
            1, "风急天高猿啸哀，",
            6, "百年多病独登台。",
            3, "无边落木萧萧下，",
        }
    };

    print_poetry(&苏轼_定风波);

    printf("\n\n");

    print_poetry(&杜甫_登高);

    return 0;
}