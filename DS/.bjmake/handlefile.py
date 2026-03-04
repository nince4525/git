# 作者: 白忠建. Copyright (c) 2021.
# 你可以自由修改和重新发布此程序
# 如果你喜欢这个小工具，那么请提出宝贵意见，并将你的修改分享给我：baizj@uestc.edu/cn
# 我们一起把这个程序做得更易用，更安全。谢谢！

import os
import shutil

from auxfn import halt, path_exists


def copy_files(dest: str, srcs: list[str]) -> None:
    """
    @brief  复制文件到指定目标文件或目录。复制成功返回True，否则结束程序
    @param  dest：目标文件/目录路径 string
    @param  srcs：源文件路径列表 list
    @return None
    """

    for src in srcs:
        # 检查源文件/目录是否存在
        path_exists(src)
        # 如果src是个文件。此时目标文件不存在的话，会被创建
        if os.path.isfile(src):
            shutil.copy2(src, dest)
        # 如果src是个目录，即要复制此目录下的所有源文件
        elif os.path.isdir(src):
            for file in os.listdir(src):
                file = os.path.join(src, file)
                if os.path.isfile(file):
                    # 将源文件原样（包括时间戳等元数据）复制到目标目录
                    # 这样可以避免复制Makefile时，可能因复制件太新而导致make产生警告信息
                    shutil.copy2(file, dest)
        else:
            halt(f'无法复制文件到 "{dest}"')
    return
    # end of copy_files()


def prepare_sourcefile(base: str, src_paths: list[str]) -> str:
    """
    @brief  准备构建的源代码文件
    @param  base: 课程资源主目录 string
    @param  src_paths: 项目依赖的源代码文件的目录列表 list
    @return builddir: 构建目录 string
    """

    builddir = os.path.join(base, 'build')
    # 删除builddir目录，以免前次残留旧文件干扰此次构建
    shutil.rmtree(builddir, True)
    # 重新创建builddir
    os.mkdir(builddir)
    # 将所有源文件复制到build目录中
    copy_files(builddir, src_paths)
    return builddir
    # end of prepare_sourcefile()


def gen_extra_file(lang: str, defaulttype: str, section: str, builddir: str) -> None:
    """
    @brief  生成最基础元素类型头文件elemtype.h（如果需要的话）, 这使得原始代码不依赖于任何类型,以及项目所需要的环境变量（写在.c或者.cpp源文件里）
    @param  lang: 语言类型 string
    @param  defaulttype: 项目的默认元素类型 string
    @param  section: 节 dict
    @param  builddir: 项目的构建目录 string
    @return None
    """

    fn = 'env.c'
    envvar = 'DSHOME'
    if lang == 'C':
        # 如果是C语言项目
        et = 'elemtype'
        # 如果项目没有指定元素类型，那么就是用默认的类型
        elemtype = defaulttype if et not in section.keys() else section[et]     
        if elemtype:
            # 如果指定了元素类型，则在构建目录下生成elemtype.h头文件
            with open(os.path.join(builddir, f'{et}.h'), mode = 'w', encoding = 'utf-8') as f:
                f.write('#pragma once\n\n')
                # 将元素配置中的每一行写入头文件
                for s in elemtype: f.write(f'{s}\n')
    elif lang == 'C++':
        # 如果是C++项目
        fn += 'pp'
        envvar += 'CXX'

    with open(os.path.join(builddir, fn), mode = 'w', encoding = 'utf-8') as f:
        f.write(f'const char *HOMEENV="{envvar}";')
    
    return
    # end of gen_extr_file()


def remove_builddir(base: str, builddir : str = 'build') -> None:
    """
    @brief  删除构建目录
    @param  base: 课程资源主目录 string
    @param  builddir: 构建目录 string
    @return None
    """

    shutil.rmtree(os.path.join(base, builddir), True)
    print(f'{builddir}目录已被移除')
    return
    # end of remove_builddir()