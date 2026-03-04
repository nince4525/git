/* 
 * Copyright (c) 白忠建 电子科技大学信息与软件工程学院
 * C语言程序示例 is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2. 
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2 
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PSL v2 for more details. 
 */


#include <stdio.h>

int main() {
    unsigned year;

    printf("please input a year: ");
    scanf("%4u", &year);
    
    if ( (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0) )
        printf("%u is a leap year\n", year);
    else
        printf("%u is not a leap year\n", year);

    return 0;
}