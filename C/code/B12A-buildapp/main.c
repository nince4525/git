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
 * @file main.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 多源文件应用构建：接口应用
 * @version 1.0
 * @date 2024-11-24
 *
 * @copyright Copyright (c) 白忠建. All rights reserved.
 *
 */

#include "student.h"

int main() {
    student s1 = {2024091001, "Zhang", 'M', {2006, 5, 15}};
    student s2 = {2024091002, "Li", 'F', {2005, 3, 26}};
    
    print_stu(&s1);
    print_stu(&s2);

    return 0;
}