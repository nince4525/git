# 作者: 白忠建. Copyright (c) 2021.
# 你可以自由修改和重新发布此程序
# 如果你喜欢这个小工具，那么请提出宝贵意见，并将你的修改分享给我：baizj@uestc.edu/cn
# 我们一起把这个程序做得更易用，更安全。谢谢！

# 颜色常量
green = "\033[32m"
blue = "\033[36m"
amber = "\033[33m"
ende = "\033[0m"

# 版本信息
VERSION = {'major': 1, 'minor': 1, 'bugfix': 1}
VERSION_STR = f'''bjmake Version {VERSION["major"]}.{VERSION["minor"]}.{VERSION["bugfix"]}
{blue}Copyright (C) 白忠建, UESTC. 你可以任意修改和重发布此程序.{ende}\n'''

# bjmake用法信息
HELP = f'''用法:
    bjmake {blue}[选项]{ende} {amber}[<章> <节{ende}{green}[@基础类型]{ende}{amber}>]{ende}
选项:
    {blue}-a, --chapter{ende}        列出可用的章
    {blue}-c, --clean{ende}          清理构建项目（删除构建目录）
    {blue}-h, --help{ende}           显示帮助信息
    {blue}-s, --section{ende} {amber}<chap>{ende} 列出章<chap>中所有可用的节，以及节可以依赖的基础类型
    {blue}-v, --version{ende}        显示版本信息
示例:
    bjmake --clean
    bjmake -s list
    bjmake list seqlist
    bjmake stack expreval@linklist'''

CHAPLIST = '可用的章有：'
SECLIST = '"%s"章中可用的节有（@号后是可选的基础类型）：'

# 构建信息
BUILDING = '正在构建应用(%s)：【 %s 】...'
BUILD_SUC = '应用构建成功，生成可执行代码"%s"。用如下命令运行程序：\nbuild/%s'
BUILD_MAKE = 'make -s -C %s target=%s'

# 源代码子目录
SRC_DIR = 'src'
MINE_DIR = 'mine'
WHICH_DIR = '.laobai'
