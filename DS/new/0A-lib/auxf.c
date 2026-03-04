/*
 * 用于课程资源的辅助数据结构和函数
 * 为了不干扰课程资源源代码的阅读，这个源文件单独存在并被编译成动态库libauxf.so
 * 建议你不用太关注这个文件，因为这里的代码与课程内容关系不大
 * 如果你实在是感兴趣，那么请参阅0A-lib目录和Makefile
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

#include "auxf.h"

//------------------------------------------------------
//本编译单元的公共函数
//内部数据。存储树或者图的形状
static char _figure[MAXSTRLEN * MAXLINES];

//组装要打开文件的绝对路径
static void _make_path(char *path, const char *format, ...) {
    va_list argv;
    va_start(argv, format);
    vsnprintf(path, 255, format, argv);
    va_end(argv);
}

//获取文件的大小
static int _sizeof_file(FILE *fp) {
    fseek(fp, 0, SEEK_END);     //文件指针移动到文件尾
    int len = ftell(fp);        //获取文件大小（字节数）
    fseek(fp, 0, SEEK_SET);     //回到文件头
    return len;
}

//打开指定文件。成功打开返回文件指针，否则退出程序。
static FILE *_openfile(const char *filename, bool redirect) {
    FILE *fp = redirect ? freopen(filename, "rt", stdin) : fopen(filename, "rt");
    if (!fp) {
        printf("无法打开文件: %s\n", filename);
        exit(1);
    }
    return fp;
}

//------------------------------------------------------
//占位函数
int nope() {
    printf("**** 这个函数还没有实现 ****\n");
    return 0;
}

//------------------------------------------------------
//线性表
FILE *redirect_stdin_to_datafile(const char *datafile) {
    char path[256];
    _make_path(path, "%s/data/%s/%s", getenv(HOMEENV), "list", datafile);
    return _openfile(path, true);
}

//------------------------------------------------------
//树

#define MAXNODENUM  128

DataType ref_table[MAXNODENUM] = {{NO_REF, NO_REFS}};

//根据tag查找对照表
DataType *find_ref_entry(char tag) {
    //未找到对照项时，返回t的地址
    static DataType t;

    for (DataType *p = ref_table; p->tag != NO_REF && p->s[0] != NO_REF; ++p)
        if (p->tag == tag)
            return p;

    t.tag = tag;
    t.s[0] = NO_REF;
    return &t;
}

//定义模型文件名
//模型实际上上用字符“画”出的树的大致形状
#define TREE_MODEL_FILE "tree-model.txt"

//打开指定文件。成功打开返回文件指针，否则返回NULL。
static FILE *_open_tree_datafile(const char *filename) {
    char path[256];
    _make_path(path, "%s/data/%s/%s", getenv(HOMEENV), "tree", filename);
    return _openfile(path, false);
}

/*
 * 内部操作。读取树的生成数据
 * 生成数据由多行构成，第一行是可用的模型数目，再下每行是一棵树的生成数据。例如：
 * AB.C..DE..FG.H..I.. $   tree-figure1.txt tree-map2.txt
 * 第一个串是先序定位串；第二个串是$，表明用只用定位串生成树；第三个串是树的形状文件名；第四个串是对照表文件名
 * 对照表中的每一行说明定位串的每一个字母对应的字符串
 * 如果没有对照表，那么这个位置的值是$
 * 再例如：
 * ABCDEFGHI   BCAEDGHFI    tree-figure2.txt    $
 * 前两个串分别是先序和后序序列，表明要用遍历顺序生成树。
 * 详见 06-tree/model/tree-model.txt
 *
 * 参数：t：模型文件编号，输入参数。nodes1和nodes2是生成串，输出参数
 */
static void get_tree_model(int t, char *nodes1, char *nodes2) {
    FILE *fp = _open_tree_datafile(TREE_MODEL_FILE);
    //读取第一行：模型数量
    int mn;
    fscanf(fp, "%d", &mn);
    if (t < 1 || t > mn) {
        fclose(fp);
        printf("错误的模型编号: %d。有效的模型编号是从1到%d\n", t, mn);
        exit(-1);
    }

    //依次读取一行，直到读到参数t指定的行数
    char modelfile[64], mapfile[64];
    for (int i = 1; i <= t; ++i)
        fscanf(fp, "%s%s%s%s", nodes1, nodes2, modelfile, mapfile);
    fclose(fp);

    //打开形状文件，读入到_figure中
    fp = _open_tree_datafile(modelfile);
    int len = _sizeof_file(fp);
    fread(_figure, 1, len, fp); //读取文件的所有字符
    fclose(fp);

    //如果树启用了对照表
    DataType *p = ref_table;
    if (mapfile[0] != '$') {
        fp = _open_tree_datafile(mapfile);
        //逐行读取格式为 标签:对照值 的数据
        for (; !feof(fp); ++p) {
            fscanf(fp, "%c:%s\n", &p->tag, p->s);
            //将字符串值转换为整型值。如果转换失败，则说明应用只使用字符串值，而不使用整型值
            p->i = atoi(p->s);
        }
        fclose(fp);
    }
    //设置最后一行标志。如果没有启用对照表，那么p指向第一行
    p->s[0] = p->tag = NO_REF;

    return;
}

/*
 * 在main中调用的接口函数，用于选择生成树的数据
 *
 * 参数：
 * appname：应用的名字。输入参数。
 * argc：命令行参数的个数，包括命令自己。输入参数。
 * argv：命令行参数的字符串数组，包括命令自己。输入参数。
 * nodes1和nodes2：生成树用到的串。输出参数。
 */
void choose_tree_model(const char *appname, int argc, char *argv[], char *nodes1, char *nodes2) {
    if (argc != 2) {
        printf("\nUsage: %s <tree-id>\n"
               "e.g.   %s 1\n", appname, appname);
        exit(-1);
    }

    int t = atoi(argv[1]);
    get_tree_model(t, nodes1, nodes2);
}

//“画出”树的形状
void tree_figure() {
    printf("%s\n\n", _figure);
}

//------------------------------------------------------
//图

//定义用到模型文件名
//模型实际上上用字符“画”出的图的大致形状
#define GRAPH_MODEL_FILE "graph-model"
#define POSTFIX "figure.txt"

//打开指定文件。成功打开返回文件指针，否则返回NULL。
static FILE *_open_graph_datafile(const char *prefix, const char *postfix) {
    char path[256];
    _make_path(path, "%s/data/%s/%s.%s", getenv(HOMEENV), "graph", prefix, postfix);
    return _openfile(path, false);
}

/*
 * 内部操作。读取图的生成数据
 * 详见 07-graph/model/graph-model.txt
 *
 * 参数：t：模型文件编号，输入参数。
 */
static FILE *_stdin_data = NULL;

static void _get_graph_model(int t) {
    FILE *fp = _open_graph_datafile(GRAPH_MODEL_FILE, "txt");
    //读取第一行：模型数量
    int mn;
    fscanf(fp, "%d", &mn);
    if (t < 1 || t > mn) {
        fclose(fp);
        printf("错误的模型编号: %d。有效的模型编号是从1到%d\n", t, mn);
        exit(-1);
    }

    //依次读取一行，直到读到参数t指定的行数
    char fileprefix[64], algo[64];
    for (int i = 1; i <= t; ++i)
        fscanf(fp, "%s%s", fileprefix, algo);
    fclose(fp);

    //打开形状文件，读入到_figure中
    fp = _open_graph_datafile(fileprefix, POSTFIX);
    int len = _sizeof_file(fp);
    fread(_figure, 1, len, fp); //读取文件的所有字符
    fclose(fp);
    _figure[len + 1] = _figure[len] = '\n';
    strcat(_figure, algo);

    //将标准输入重定向到指定的数据文件
    char datafile[256];
    _make_path(datafile, "%s/data/%s/%s.data.txt", getenv(HOMEENV), "graph", fileprefix);
    _stdin_data = _openfile(datafile, true);
}

/*
 * 在main中调用的接口函数，用于选择生成图的数据
 *
 * 参数：
 * appname：应用的名字。输入参数。
 * cond：命令行参数的个数是否达标。输入参数。
 * argv：命令行参数的字符串数组，包括命令自己。输入参数。
 * option：命令行除了模型id外的其他选项参数集合。输入参数。
 * 返回值：
 * char，选项的参数
 */
void choose_graph_model(const char *appname, bool argc, char *argv[], const char *options) {
    if (!argc) {
        printf("Usage: %s <graph-id>", appname);
        if (options) printf(" %s", options);
        putchar('\n');
        exit(-1);
    }

    int t = atoi(argv[1]);
    _get_graph_model(t);
}

//“画出”图的形状
void graph_figure() {
    printf("%s\n\n", _figure);
}

void close_model() {
    fclose(_stdin_data);
}


//顶点标签-名字对照表
char vertex_map[MAX_VERTEX_NUM][MAX_NAME_LEN]; //顶点名称

void FillVertexMap(int n) {
    for (int i = 0; i < n; ++i)
        scanf("%s", vertex_map[i]);
    getchar();
}

char *Vertex2Name(char d) {
    return vertex_map[d - 'A'];
}
