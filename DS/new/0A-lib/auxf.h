#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tree-nodetype.h"
#include "graph-basic-type.h"

extern const char *HOMEENV;

//定义换行的宏
#define NL putchar('\n')

/*
 * 这个函数被没有实现的函数调用
 * 参数：无
 * 返回值：0
 */
extern int nope();

//------------------------------------------------------

/*
 * 用于打开应用用到的数据文件，并将标准输入重定向到打开的文件
 * 参数：
 * datafile: 数据文件名
 * 返回值：
 * 文件成功打开返回文件指针，否则结束应用
 */
extern FILE* redirect_stdin_to_datafile(const char *datafile);

//------------------------------------------------------
//树
//未使用ref_table定义的宏
#define NO_REF  '~'
#define NO_REFS "~"

//全局变量
extern DataType ref_table[];

//根据tag查找参照想
extern DataType* find_ref_entry(char tag);

#define MAXSTRLEN      256
#define MAXLINES       30

//选择树模型
extern void choose_tree_model(const char *appname, int argc, char *argv[], char nodes1[], char nodes[]);
//用字符画出输的形状
extern void tree_figure();

//------------------------------------------------------
//图
#define MAX_NAME_LEN  10

extern void choose_graph_model(const char *appname, bool argc, char *argv[], const char *options);
extern void graph_figure();
extern void close_model();

extern char vertex_map[][MAX_NAME_LEN]; //顶点名称
extern void FillVertexMap(int n);
extern char *Vertex2Name(char d);
