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
 * @file planets.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示结构数组的使用
 * @version 1.0
 * @date 2024-11-18
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>
#include <string.h>

#define N   8

// 定义结构类型
struct planets_tag {
    char name[8];       // 行星名
    char symbol[4];     // 符号
    float mass;         // 质量（相对于地球）
    unsigned radius;    // 半径
    unsigned moons;     // 卫星数
};

// 定义结构类型的别名
typedef struct planets_tag planets_t;

// 定义结构数组并初始化
planets_t planets[N] = {
    {"Mercury", "☿",   0.05f,    2440,   0},
    {"Venus",   "♀",   0.82f,    6052,   0},
    {"Earth",   "⊕",    1.0f,   6378,   1},
    {"Mars",    "♂",   0.11f,    3398,   2},
    {"Jupiter", "♃",   317.94f, 71492,  79},
    {"Saturn",  "♄",   95.1f,    60268, 83},
    {"Uranus",  "♅",   14.6f,   25559,  29},
    {"Neptune", "♆",   17.2f,   24718,  14}
};

/**
 * @brief 打印行星信息
 * 
 * @param pl 行星信息数组
 * @param n 行星数
 */
void print_planets(planets_t pl[], int n) {
    // 打印表头
    printf("\033[92mName\tSymbol\t  Mass\tRadius\t  Moons\n");
    printf("----------------------------------------\033[0m\n");
    for (int i = 0; i < n; ++i)
        printf("%s\t  %s\t%6.2f\t%5ukm\t%6u\n", pl[i].name, pl[i].symbol, pl[i].mass, pl[i].radius, pl[i].moons);
    putchar('\n');
}

/**
 * @brief 数组排序
 * 
 * @param pl 行星信息数组
 * @param n 行星数
 */
void sort_planets(planets_t pl[], int n) {
    int i, j;
    planets_t t;

    for (i = 0; i < n - 1; ++i) {
        for (j = 0; j < n - i - 1; ++j) {
            // TODO
            
            // END
        }
    }
}

int main() {
    print_planets(planets, N);

    sort_planets(planets, N);

    print_planets(planets, N);

    return 0;
}