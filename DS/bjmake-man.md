# bjmake使用说明

### 一 关于Python版本
**macOS用户可以忽略此步骤**

1. 获取python3版本。在终端中发出：
    ```bash
    python3 -V
    ```
    结果可能是这样的：
    ```bash
    3.12.x
    ```
    如果版本不小于3.12，那么就OK了，直接跳到**步骤二**。

2. 如果版本小于3.12，那么要先看看Ubuntu的版本。在终端中发出如下指令：
    ```bash
    lsb_release -a
    ```
    如果显示版本小于**23.04**，那么你需要将Ubuntu升级到23.04或更高版本。详情参阅博文：
    `https://bzjuestc.github.io/blog/c/c++%E5%BC%80%E5%8F%91%E7%8E%AF%E5%A2%83/2022/01/01/04-%E7%BB%B4%E6%8A%A4%E5%92%8C%E9%85%8D%E7%BD%AELinux.html` part 2.

3. 升级python
    在终端中发出如下命令：
    ```bash
    sudo apt install python3.12-full
    ```

### 二 配置环境变量
#### 一）. Linux用户
假设你拉去了我的仓库`paf`，并将其放在`/mnt/d/`（即Windows的D:盘根）目录下。

1. 在终端中发出如下命令：
    ```bash
    vim ~/.profile
    ```
    在vim编辑器中，将光标移到到文件末尾最后一行的最后一个字符上，按`a`键，然后先按一次回车，接着将如下内容输入进去：
    ```bash
    export DSHOME="/mnt/d/paf/DS"
    export PATH=$PATH:.
    ```
    然后按`ESC`键，再按`:`键，输入`wq`后保存退出。

2. 在终端中发出如下命令（一次就够了）使更改生效：
    ```bash
    source ~/.profile
    ```

#### 二）. macOS用户
假设你拉去了我的仓库`paf`，并将其放在`~/paf`目录下。

1. 在终端中发出如下命令：
    ```zsh
    vim ~/.zshrc
    ```
    在vim编辑器中，将光标移到到文件末尾最后一行的最后一个字符上，按`a`键，然后先按一次回车，接着将如下内容输入进去：
    ```zsh
    export DSHOME="~/paf"
    export PATH=$PATH:.
    ```
    然后按`ESC`键，再按`:`键，输入`wq`后保存退出。

2. 在终端中发出如下命令（一次就够了）使更改生效：
    ```bash
    source ~/.zshrc
    ```

### 三 准备工作
1. 创建工作目录

    首先，要在`/mnt/d/paf/DS`或者`~/paf`目录下创建一个你自己的工作目录`mine`。
    ```bash
    cd $DSHOME
    mkdir mine
    ```
    此后，你所有的代码编写工作都在此目录下进行。

    **不要修改 mine 目录外的任何文件！！！否则，下次拉取仓库将会失败！！！**

2. 复制源代码

    将`src`子目录下的代码全部复制粘贴到`mine`目录下。

3. 创建动态库

    打开一个终端，发出如下命令：
    ```bash
    cd $DSHOME/src/0A-lib
    make
    make install
    ```

### 四 使用bjmake
在终端中发出如下命令：
```bash
cd $DSHOME
bjmake
```
脚本会显示帮助信息。请根据帮助信息使用。

这里给出一些使用例子：
1). 列出可用的章
```bash
bjmake -a
```

2). 列出`list`章中可用的节，以及节可以依赖的基础类型
```bash
bjmake -s list
```

3). 构建`list`章中的`linklist`项目
```bash
bjmake list linklist
```

4). 构建`stack`章中的`expreval`项目，并指定使用`linkstack`基础类型
```bash
bjmake stack expreval@linkstack
```
###### 注：项目可以依赖的基础类型可能有多个。如果没有指定基础类型，项目用默认的基础类型构建。

5). 清除构建的项目
```bash
bjmake -c
```