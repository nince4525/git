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
 * @file cmdline-args.c
 * @author 白忠建 (baizj@uestc.edu.cn)
 * @brief 演示main函数的命令行参数的使用
 * @version 1.0
 * @date 2024-11-12
 *
 * @copyright Copyright (c) 白忠建. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("argc: %d\n", argc);
    for (int i = 0; i <= argc; ++i)
        printf("argv[%d]: %s\n", i, argv[i]);

    if (argc == 3) {
        int a = atoi(argv[1]); // 将字符串转换为整数。以下同此
        int b = atoi(argv[2]);
        printf("%d + %d = %d\n", a, b, a + b);
    }

    return 0;
}