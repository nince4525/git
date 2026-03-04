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
 * @file broken-in-two.c
 * @author 白忠建 (baizj@uestc.edu.cn)
 * @brief 将字符串从空格处分割为两个字符串
 * @version 1.0
 * @date 2024-11-20
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

/**
 * @brief 将字符串s从空格处分割为两个字符串，分别存在t和s中
 * 
 * @param s 待分割的字符串
 * @param t 分割出的前部分
 * @param u 分割出的后部分
 */
void Strbreak(const char *s, char *t, char *u) {
    // TODO

    // END
}

/**
 * @brief 测试函数
 * 
 * @return int 
 */
int main() {
    char s[128] = "hello world";
    char t[128], u[128];

    Strbreak(s, t, u);
    printf("%s\n%s\n", t, u);
    
    return 0;
}