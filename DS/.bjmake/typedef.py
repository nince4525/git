# 作者: 白忠建. Copyright (c) 2021.
# 你可以自由修改和重新发布此程序
# 如果你喜欢这个小工具，那么请提出宝贵意见，并将你的修改分享给我：baizj@uestc.edu/cn
# 我们一起把这个程序做得更易用，更安全。谢谢！

from typing import Literal, TypedDict, Required


# 节类别类型
type category_t = Literal['infrastructure', 'infrastructure|hidden', 'application']


# 依赖的基础类型类型
type dependency_t = Literal['standalone'] | dict[str, list[str]]


class section_t(TypedDict, total = False):
    """
    @brief 节配置类型
    """
    title: Required[str] # 节标题
    category: Required[category_t] # 节类别
    dependency: Required[dependency_t] # 依赖的基础类型
    executable: str # 可执行文件名。可选


# 节配置字典类型
type sections_t = dict[str, section_t]


class config_t(TypedDict, total = False):
    """
    @brief 章配置类型
    """
    home: Required[str] # 章目录名
    chapter: Required[str] # 章标题
    defaulttype: Required[list[str]] # 默认的基础元素类型
    defaultexec: Required[str] # 默认的可执行文件名
    section: Required[sections_t] # 节配置
    base: Required[str] # 课程资源主目录
    src: Required[str] # 所有源码的主目录
    lang: Required[str] # 编程语言
    description: Required[str] # 课程描述
    chapter_name: str # 章标题
    section_name: str # 节标题
    underlying: str # 底层依赖
