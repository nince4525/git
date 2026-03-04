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
 * @file string-literal.c
 * @author 白忠建 (baizj@uestc.edu.cn)
 * @brief 字符串字面常量
 * @version 1.0
 * @date 2024-11-12
 *
 * @copyright Copyright (c) 白忠建. All rights reserved.
 *
 */

#include <stdio.h>

char print_char(char c) {
    if (c != '\0')
        putchar(c);
    else
        putchar('^');
    
    return c;
}

int main() {
    {
        // 构造一个块级局部环境。以下同此
        for (int i = 0; ; ++i) {
            if (print_char("this is a string literal"[i]) == '\0') break;
        }
        putchar('\n');
    }

    {
        for (const char *p = "this is a string literal"; ; ++p) {
            if (print_char(*p) == '\0') break;
        }
        putchar('\n');
    }

    return 0;
}