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
 * @file string-var.c
 * @author 白忠建 (baizj@uestc.edu.cn)
 * @brief 字符串变量
 * @version 1.0
 * @date 2024-11-12
 *
 * @copyright Copyright (c) 白忠建. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>

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
        printf("string saved as array of char: length is designated\n");
        char s[8] = "HELLO"; // 效果等价于：char s[8] = {'H', 'E', 'L', 'L', 'O', '\0'};
        printf("[s]=");
        for (int i = 0; i < sizeof(s); ++i)
            print_char(s[i]);
        printf("\ts=");
        s[4] = 'o';
        puts(s);
    }

    {
        printf("string saved as array of char: length is determined by initializer\n");
        char s[] = "HELLO"; // 效果等价于：char s[] = {'H', 'E', 'L', 'L', 'O', '\0'};
        printf("[s]=");
        for (int i = 0; i < sizeof(s); ++i)
            print_char(s[i]);
        printf("\ts=");
        s[4] = 'o';
        puts(s);
    }

    {
        printf("const string pointed by a pointer\n");
        const char *s = "HELLO";
        printf("[s]=");
        for (int i = 0; i <= strlen(s); ++i)
            print_char(s[i]);
        printf("\ts=");
        // s[5] = 'o'; // error! 试图修改常量内存！
        puts(s);
    }

    {
        printf("input string by fgets\n");
        char s[128]; // 因为输入的字符串长度未知，所以先预估一个长度。请注意要计入封尾的'\0'
        fgets(s, 126, stdin); // 从标准输入读入最多126个字符，因为fgets函数要读入最后的'\n'，还要附加封尾'\0'
        printf("%s", s);
    }

    {
        printf("input string by getchar\n");
        char s[128]; // 因为输入的字符串长度未知，所以先预估一个长度。请注意要计入封尾的'\0'
        int i;
        for (i = 0; (s[i] = getchar()) != '\n'; ++i); 
        s[i] = '\0';
        printf("%s\n", s);
    }

    return 0;
}