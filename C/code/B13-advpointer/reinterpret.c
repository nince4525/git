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
 * @file reinterpret.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示内存重解释
 * @version 1.0
 * @date 2024-11-25
 *
 * @copyright Copyright (c) 白忠建. All rights reserved.
 *
 */

// 如果你在Linux下编译此程序，请加上 -fsanitize=address 选项

#include <stdio.h>

int main() {
    {
        int n = 1;
        float *p = (float *)&n; // 注意: sizeof(int) === sizeof(float)
        printf("%d, %f\n", n, *p); // 1, 0.000000  内存冲解释失败
    }

    {
        int n = 1;
        double *p = (double *)&n; // 注意: sizeof(int) < sizeof(double)
        // printf("%d, %lf\n", n, *p); // 这种内存重解释是危险的, 将导致stack-buffer-overflow异常
    }

    {
        int n = 0x01020304;
        void *p = (void *)&n; // p指向了未知基类型的数组
        printf("0x%x\n", n);
        for (int i = 0; i < sizeof(n); ++i)
            printf("0x%x ", ((char *)p)[i]);  // 又一次的内存重解释
        putchar('\n');
    }

    {
        union { int n; double d; } u;
        u.n = 1;
        printf("%d, %lf\n", u.n, u.d); // 1, 0.000000  整数和浮点数的内存映像不一样，所以内存重解释失败

        u.d = 3.14;
        printf("%d, %lf\n", u.n, u.d); // 1374389535, 3.140000
    }

    {
        union { int n; char c[sizeof(int)]; } u;
        u.n = 0x01020304;
        printf("0x%x\n", u.n);

        for (int i = 0; i < sizeof(int); ++i)
            printf("0x%x ", u.c[i]);
        putchar('\n');
    }

    return 0;
}