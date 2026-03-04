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
 * @file list.h
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 单链表演示程序：头文件
 * @version 1.0
 * @date 2024-11-24
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

#pragma once

// 定义数据元素类型
typedef int elem_t;

// 将elem_t类型的空初始化值定义为ZERO。这是一个复合字面常量，用于初始化
#define ZERO (elem_t){}