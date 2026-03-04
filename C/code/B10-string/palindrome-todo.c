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
    // TODO

    return true;
    // END
}

int main() {
    char str[128];

    scanf("%s", str);
    printf(is_palindrome(str) ? "Yes\n" : "No\n");

    return 0;
}