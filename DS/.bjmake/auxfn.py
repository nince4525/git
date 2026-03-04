# 作者: 白忠建. Copyright (c) 2021.
# 你可以自由修改和重新发布此程序
# 如果你喜欢这个小工具，那么请提出宝贵意见，并将你的修改分享给我：baizj@uestc.edu/cn
# 我们一起把这个程序做得更易用，更安全。谢谢！

import sys
import os
import json
from typing import NoReturn

from constdef import SRC_DIR, MINE_DIR, WHICH_DIR
from typedef import *

def halt(msg: str) -> NoReturn:
    """
    @brief  因严重错误结束程序
    @param  msg：错误信息 string
    @return never return
    """

    print(f'=== 错误 === \n{msg}')
    sys.exit(-1)
    # end of halt()


def path_exists(path: str) -> str | NoReturn:
    """
    @brief  检查路径是否存在。如果不存在，结束程序
    @param  path：文件/目录的路径 string
    @return str: 如果路径存在，返回路径；否则结束程序
    """
    
    if os.path.exists(path): return path

    halt(f'目录或文件 {path} 不存在')
    # end of path_exists()


def parse_args() -> list[str, tuple]:
    """
    @brief  解析命令行参数
    @return tuple: (action, param-pack)
    """

    R = {
        #        action param-pack
        'help': ['help', ()],
        'clean': ['clean', ()],
        'listchap': ['listchap', ()],
        'version': ['version', ()]
    }

    # 没有命令行参数，或者错误的参数，都会显示帮助信息
    r = R['help']

    argc = len(sys.argv)
    argv = sys.argv

    # 只有一个命令行参数
    if argc == 2:
        o = argv[1]
        if o in ['-h', '--help']:
            r = R['help']
        elif o in ['-c', '--clean']:
            r = R['clean']
        elif o in ['-a', '--chapter']:
            r = R['listchap']
        elif o in ['-v', '--version']:
            r = R['version']
    # 有两个命令行参数
    elif argc == 3:
        if argv[1] in ['-s', '--section']:
            r = ['listsec', (argv[2], None)]
        else:
            # 此时，命令行参数应该类似于：章 节[@基础类型]
            [chapter, sectunder] = argv[1:]
            a = sectunder.split("@")
            section = a[0]
            # underlying是可选的基础类型名
            # 有些项目可以依赖的基础类型可能有多个
            # 例如：stack章expreval节，程序可依赖的栈有顺序栈和链栈
            # 如果命令行参数没有指定，那么选默认的
            underlying = a[1] if len(a) == 2 else 'default'
            r = ['build', (chapter, section, underlying)]

    return r
    # endof parse_args()


def load_config(base_path: str, chapter: str) -> config_t:
    """
    @brief  载入并解析配置文件
    @param  base_path: 主目录名 string
    @param  chapter: 章名 string
    @return config_t:配置 
    """

    # 从json文件中读取配置
    # 先读取全局配置
    conf_path = os.path.join(base_path, 'conf', f'global.conf.json')
    with open(path_exists(conf_path), mode='r', encoding='utf-8') as fp:
        gconfig: dict = json.load(fp)

    # 再读取章配置
    conf_path = os.path.join(base_path, 'conf', f'{chapter}.conf.json')
    with open(path_exists(conf_path), mode='r', encoding='utf-8') as fp:
        config: dict = json.load(fp)
    
    # 添加必要的配置项
    config['lang'] = gconfig['lang']
    config['description'] = gconfig['description']
    config['base'] = base_path
    config['src'] = SRC_DIR if os.path.exists(os.path.join(base_path, MINE_DIR, WHICH_DIR)) else MINE_DIR

    return config
    # end of load_config()


def section_exits(config: dict, chap: str, sec: str) -> str | NoReturn:
    """
    @brief  检查节目录是否存在。如果节在配置中不存在则结束程序
    @param  config: 章配置 dict
    @param  chap: 章名 string
    @param  sec: 节名 string
    @return str: sec 节存在
    @return NoReturn: 节不存在
    """

    if sec in config.keys(): return sec

    halt(f'''章或节目录 "{sec}" 不存在
请用 "bjmake -a"列出可用章
请用 "bjmake -s {chap}"列出该章可用的节''')
    
        # end of section_exists()
