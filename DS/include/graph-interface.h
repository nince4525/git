#pragma once

#include "auxf.h"

/*
 * 以下列出图的典型操作接口声明。
 * 
 * 接口函数描述中：
 * in： 表示输入参数
 * out：表示输出参数
 */

struct Graph; //forwarding

/*
 * 创建图
 * 参数：
 *      G：out，待创建的图指针。
 * 返回值类型：
 *      无
 */
extern void CreateGraph(Graph *G);

/*
 * 销毁图
 * 参数：
 *      G：in，图指针。
 * 返回值类型：
 *      无
 */
extern void DestroyGraph(Graph *G);

/*
 * "绘制"图
 * 参数：
 *      G：in，图指针。
 * 返回值类型：
 *      无
 */
extern void DrawGraph(Graph *G);

/*
 * 在图中定位顶点
 * 参数：
 *      G：in，带创建的图指针。
 *      v：in，顶点数据
 * 返回值类型：
 *      v在顶点列表中的位置（下标）
 */
extern int LocateVertex(Graph *G, VertexData v);

/*
 * 查找当前顶点v的第一个邻接顶点
 * 参数：
 *      G：in，图指针。
 *      v：in，当前顶点的位序
 * 返回值类型：
 *      连接两个顶点的弧
 */
extern Arc FirstAdjVertex(Graph *G, int v);

/*
 * 查找当前顶点v相对于弧w的下一个邻接顶点
 * 参数：
 *      G：in，图指针。
 *      v：in，当前顶点的位序
 * 返回值类型：
 *      连接两个顶点的弧
 */
extern Arc NextAdjVertex(Graph *G, int v, Arc w);
