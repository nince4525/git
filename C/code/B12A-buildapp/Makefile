# Copyright (c) 白忠建 电子科技大学信息与软件工程学院
# C语言程序示例 is licensed under Mulan PSL v2.
# You can use this software according to the terms and conditions of the Mulan PSL v2. 
# You may obtain a copy of Mulan PSL v2 at:
#          http://license.coscl.org.cn/MulanPSL2 
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
# See the Mulan PSL v2 for more details. 


# 变量定义
# 源文件列表
sources = main.c student.c date.c
# 目标文件名
target = stu

# 平台相关变量或选项
ifdef windir 
# Windows下没有asan库
ASAN =
# 删除命令
DEL = del
# 可执行程序名
exe = $(target).exe
else
ASAN = -fsanitize=address
DEL = rm
exe = $(target)
endif

# 指定编译器
CC = gcc
# 指定编译选项，依次是：生成调试信息，开启所有警告，把警告当成错误，使用地址消毒器
CCFLAG = -g -Wall -Werror

# 指定phony目标
.PHONY: all clean

# 默认任务
all:
	$(CC) $(sources) $(CCFLAG) $(ASAN) -o $(exe)

# 清理任务
clean:
	$(DEL) $(exe)
