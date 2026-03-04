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
 * @file palindrome.c
 * @author 白忠建 (baizj@uestc.edu.cn)
 * @brief 判断输入的字符串是否是回文（palindrome）
 * @version 1.0
 * @date 2024-11-12
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief 判断参数字符串是否是回文
 * 
 * @param s 字符串
 * @return bool 如果是，返回true；否则返回false
 */
bool is_palindrome(const char *s) {
    const char *p = s;
    // 工作指针p从字符串头开始移动，一直到指向封尾0
    while (*p) ++p;
    // 现在退回一步，则指向了字符串的最后一个字符
    --p;

    // 如果左边的指针s没有超过右边的指针p，则继续循环
    while (s < p) {
        // 如果两个指针指向的字符不同，则一定不是回文
        if (*s != *p) return false;
        // 两个指针相向移动
        ++s;
        --p;
    }

    return true;
}

int main() {
    char str[128];

    scanf("%s", str);
    printf(is_palindrome(str) ? "Yes\n" : "No\n");

    return 0;
}