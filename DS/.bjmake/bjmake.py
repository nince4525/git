# 作者: 白忠建. Copyright (c) 2021.
# 你可以自由修改和重新发布此程序
# 如果你喜欢这个小工具，那么请提出宝贵意见，并将你的修改分享给我：baizj@uestc.edu/cn
# 我们一起把这个程序做得更易用，更安全。谢谢！

import os
import re
from typing import Any, Literal

from constdef import *
from auxfn import *
from handlefile import *
from typedef import *


def prepare(config: config_t) -> tuple[str, str, str]:
    """
    @brief  构建项目前的准备工作
    @param  config: 配置 config_t
    @return 元组(项目名，构建目录，可执行代码名) tuple
    """

    def add_dependency_paths(cur_chap: str, cur_config: config_t, src_paths: list[str], dependency: dict, underlying: str) -> list[str]:
        """
        @brief  递归地添加依赖的源码路径
        @param  cur_chap: 当前章  string
        @param  cur_config: 当前章配置 dict
        @param  src_paths: 源码路径列表 list
        @param  dependency: 依赖配置  dict
        @param  underlying: 可选的基础类型名 string
        @return 无
        """

        if underlying == 'default':
            underlying = list(dependency.keys())[0]
            
        section_exits(dependency, cur_chap, underlying)
        for d in dependency[underlying]:
            [chap, sect] = d.split("/")
            # 如果依赖章节不在本章，那么载入对应的配置
            cfg = load_config(cur_config['base'], chap) if chap != cur_chap else cur_config
            # 检查依赖的章节是否存在
            section_exits(cfg['section'], chap, sect)
            src_paths.append(os.path.join(src_base, cfg['home'], sect))
            # 如果依赖还有依赖，则递归加入路径
            s = cfg['section'][sect]
            if 'dependency' in s.keys():
                add_dependency_paths(chap, cfg, src_paths, s['dependency'], 'default')
        return [] if 'elemtype' not in s.keys() else s['elemtype']
        # end of add_dependency_paths()

    def handle_dependency(seccate: str) -> tuple[list[str], list[str]]:
        """
        @brief  获取本项目（在节中）的依赖源码列表，以及元素类型数组
        @param  seccate: 节类型
        @return tuple(src_paths, et): (包含依赖目录的列表 list, 元素类型数组 list)
        """

        # 先将本项目的路径加入
        src_paths = [os.path.join(src_base, home, section_name)]
        # 预设的元素类型数组。默认为空
        et = []

        # 获取项目依赖
        dependency = None if 'dependency' not in section.keys() else section['dependency']
        # 如果是独立应用，那么说明此项目不依赖于任何基础类型，并且有自己的Makefile。否则
        if dependency != 'standalone': 
            src_paths.append(os.path.join(src_base, '0B-misc/Makefile'))
            if (not dependency) or re.search('infrastructure', seccate):
                # 如果dependency为空，或者类型是infra，则说明项目至少要依赖于main
                src_paths.append(os.path.join(src_base, home, 'main'))

            if dependency:
                # 如果项目有依赖，则将项目依赖的路径加入
                et = add_dependency_paths(chapter_name, config, src_paths, dependency, underlying)

        return (src_paths, et)
        # end of handle_dependency()

    # 课程资源主目录
    base = config['base']
    # 所有源码的主目录
    src_base = f'{base}/{config['src']}'
    # 章目录
    home = config['home']

    chapter_name = config['chapter_name']
    section_name = config['section_name']
    underlying = config['underlying']

    # 在章配置中检查参数指定的节是否存在
    section_exits(config['section'], chapter_name, section_name)
    section = config['section'][section_name]

    src_paths, et = handle_dependency(section['category'])
    builddir = prepare_sourcefile(base, src_paths)
    
    if et: section['elemtype'] = et
    gen_extra_file(config['lang'], config['defaulttype'], section, builddir)

    target = config['defaultexec'] if 'executable' not in section.keys() else section['executable']
    return (section['title'], builddir, target)
    # end of prepare()


# 主函数
def main() -> Literal[0]:
    """
    @brief  列出可用的章
    @param  base: 课程资源主目录 string
    @return 0
    """

    def listchap(base: str) -> None:
        """
        @brief  列出可用的章
        @param  base: 课程资源主目录 string
        @return None
        """

        print(CHAPLIST)
        # 对base目录下的子目录conf中的所有配置文件（*.conf.json）
        for file in os.listdir(os.path.join(base, 'conf')):
            a = file.split('.')
            if a[0] not in ['global']: print(' - ', a[0])
        return
        # end of listchap

    def listsec(base: str, chap: str, *_: Any) -> None:
        """
        @brief  列出章中可用的节
        @param  base: 课程资源主目录 string
        @param  chap: 章 string
        @param  _: 忽略的参数包 Any
        @return None
        """

        # 载入章排至
        config = load_config(base, chap)
        print(SECLIST % chap)

        section = config['section']
        # 对本章所有的节
        for sec in section.keys():
            sect = section[sec]
            # 不显示隐藏的节
            if not re.search('hidden', sect['category']):
                # 显示节信息
                print(f' + {sec} \033[32m#{sect["title"]}\033[0m')
                # 如果节有依赖，则列出所有依赖信息
                if 'dependency' in sect:
                    dep = sect['dependency']
                    # 如果依赖是个dict，并且至少有一个键值对
                    if isinstance(dep, dict) and len(dep) > 1:
                        for dk in dep:
                            m = '(默认基础类型，可以不写)' if dk == 'default' else ''
                            print(f'   \033[33m@ {dk}{m}\033[0m')
        return
        #endo of listsec()

    def build(base: str, chap: str, sec: str, under: str) -> int:
        """
        @brief  构建项目
        @param  base: 课程资源主目录 string
        @param  chap: 章 string
        @param  sec: 节 string
        @param  under: 基础类型 string
        @return int: 构建结果代码
        """

        # 载入章配置
        config = load_config(base, chap)
        # 为配置添加必要的配置项
        config['chapter_name'] = chap
        config['section_name'] = sec
        config['underlying'] = under

        # 构建应用
        print(f'\033[33m{config["description"]}\033[0m', '\n')

        apptitle, builddir, target = prepare(config)
        print(BUILDING % (config['src'], apptitle))
        r = os.system(BUILD_MAKE % (builddir, target))
        if r == 0: print(BUILD_SUC % (target, target))
        return r
        # end of build()

    # 操作集合 dict: {action: 操作函数}
    operation = {
        'help': lambda _: print(HELP),
        'version': lambda _: print(VERSION_STR),
        'clean': remove_builddir,
        'listchap': listchap,
        'listsec': listsec,
        'build': build
    }

    # 解析命令行参数
    action, params = parse_args()
    # 调用action指定的函数
    operation[action](os.getcwd(), *params)

    return 0
    # end of main()


# 启动程序
if __name__ == '__main__':
    main()
