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
 * @file string.c
 * @author 白忠建 (baizj@uestc.edu.cn)
 * @brief 模仿C的字符串处理函数的实现
 * @version 1.0
 * @date 2024-11-12
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

/**
 * @brief 求字符串的长度。不计结尾'\0'
 * 
 * @param s 字符串（指针）
 * @return int 字符串长度
 */
int Strlen(const char *s) {
    const char *p = s;
    while (*p) ++p;
    return p - s;
}

/**
 * @brief 将源字符串s复制到目的字符串t中
 * 
 * @param t 目的字符串
 * @param s 源字符串。注意：是指向常量的指针
 * @return char* 目的字符串
 */
char * Strcpy(char *t, const char *s) {
    char * p = t;
    while ((*p++ = *s++));
    return t;
}

/**
 * @brief 比较两个字符串s和t的大小。字符串的比较定义为串的字典序的比较
 * 
 * @param s 字符串1
 * @param t 字符串2
 * @return int 比较结果。如果s大于、等于、小于t，分别返回正值、0、负值。注：有些实现中，大于返回1，小于返回-1
 */
int Strcmp(const char *s, const char *t) {
    while (*s || *t) {
        if (*s != *t) return *s - *t; // positive: greater; nagetive: lesser

        ++s;
        ++t;
    }

    return 0; // equal
}

/**
 * @brief 字符串拼接：将源字符串s拼接到目的字符串t的尾部（注：要覆盖其封尾0）
 * 
 * @param t 目的字符串
 * @param s 源字符串
 * @return char* 目的字符串
 */
char * Strcat(char *t, const char *s) {
    char *p = t;
    while (*p) ++p;
    Strcpy(p, s);
    return t;
}

/**
 * @brief 测试函数
 * 
 * @return int 
 */
int main() {
    char buf1[128], buf2[128];
    char *str = buf1;

    // 输入源字符串
    printf("please input a string: ");
    scanf("%s", str);

    // 测试字符串长度
    printf("strlen: %d\n", Strlen(str));

    // 测试字符串复制
    Strcpy(buf2, str);
    printf("strcpy: %s\n", buf2);
    
    // 测试字符串比较
    buf2[0] = buf2[1];
    int k = Strcmp(buf1, buf2);
    if (k == 0) {
        printf("strcmp: euqal\n");
    }
    else if (k > 0) {
        printf("strcmp: greater\n");
    }
    else {
        printf("strcmp: lesser\n");
    }

    // 测试字符串拼接
    printf("strcat: %s\n", Strcat(buf2, "xyz"));
    
    return 0;
}