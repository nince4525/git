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
 * @file student.h
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 多源文件应用构建：接口定义
 * @version 1.0
 * @date 2024-11-24
 *
 * @copyright Copyright (c) 白忠建. All rights reserved.
 *
 */

//---------------------------------------------------------------------------
// 1. 编译设置：头文件保护
#pragma once

//---------------------------------------------------------------------------
// 2. 标准和/或自定义头文件包含
#include "date.h"

//---------------------------------------------------------------------------
// 3. 宏定义
#define MAX_NAME_LEN    65

//---------------------------------------------------------------------------
// 4. 类型定义
typedef struct _student {
    unsigned long id;
    char name[MAX_NAME_LEN];
    char gender;
    date dob;
} 
student, // 结构类型struct _student的别名。typeof(student) === typeof(struct _student)
*pstudent; // 指向结构类型struct _student的指针类型的别名。typeof(pstudent) === typeof(struct _student *)

//---------------------------------------------------------------------------
// 5. 外部对象声明


//---------------------------------------------------------------------------
// 6. 函数签名

/**
 * @brief 打印学生信息
 * 
 * @param pstu 学生对象的指针
 */
extern void print_stu(pstudent pstu);