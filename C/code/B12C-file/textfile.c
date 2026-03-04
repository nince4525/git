/*
 * Copyright (c) 2024 白忠建 电子科技大学信息与软件工程学院
 * C语言程序示例 is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PSL v2 for more details.
 */

/**
 * @file textfile.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示文本文件的读写
 * @version 1.0
 * @date 2025-01-04
 * 
 * @copyright Copyright (C) 2025 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

void copy(const char *src, const char *dest) {
    FILE *in, *out;

    in = fopen(src, "rt");
    if (in == NULL) {
        printf("cannot open file '%s' for reading\n", src);
        exit(1);
    }

    out = fopen(dest, "wt");
    if (out == NULL) {
        printf("cannot open file '%s' for writing\n", dest);
        exit(1);
    }

    while (!feof(in)) {
        char c = fgetc(in);
        fputc(c, out);
    }

    printf("file '%s' was copied into '%s'\n", src, dest);

    fclose(in);
    fclose(out);
}

int main() {
    copy("textfile.c", "textfile-copy.c");

    return 0;
}