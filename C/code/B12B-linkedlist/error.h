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
 * @file error.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 出错处理：头文件
 * @version 1.0
 * @date 2024-11-24
 *
 * @copyright Copyright (c) 白忠建. All rights reserved.
 *
 */

#pragma once

// 定义可以在Powershell终端和Bash终端显示的颜色代码
#define RED "\033[91m"
#define AMBER "\033[33m"
#define NORMAL "\033[0m"

/**
 * @brief 警告处理。仅显示警告信息
 *
 * @param format 警告信息格式字符串
 * @param ... 变长参数包
 */
extern void warning(const char *format, ...);

/**
 * @brief 致命错误处理。此函数将退出程序，永不返回
 *
 * @param format 错误信息格式字符串
 * @param ... 变长参数包
 */
extern void error(const char *format, ...);