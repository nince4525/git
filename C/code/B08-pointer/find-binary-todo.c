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
 * @file find-binary.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 折半查找法：查找键值是否在数组中存在
 * @version 1.0
 * @date 2024-10-30
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>
#include <stdbool.h>

#define N   20

int main() {
    int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int key;

    printf("please input a key(1~20): ");
    scanf("%d", &key);

    bool found = false;

    int *l, *r, *m;
    //TODO：在数组a中查找key是否存在。如果存在，将found置为true

    //END OF TODO

    if (found)
        printf("found key %d@%ld\n", key, m - a);
    else
        printf("not found.\n");

    return 0;
}