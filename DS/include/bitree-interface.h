/*
 * 二叉树的典型操作接口声明。
 */

#pragma once

#include "auxf.h"

/*
 * 以下列出二叉树的典型操作接口声明。
 * 
 * 接口函数描述中：
 * in： 表示输入参数
 * out：表示输出参数
 */

/*
 * 用于访问二叉树节点数据的回调函数类型
 */
typedef void CALLBACK(DataType);

/*
 * 创建二叉树
 * 参数：
 *      nodes1：in，包含节点数据的字符串。
 *      nodes2：in，如果不是NULL，那么说明两个字符串参数是两种遍历顺序生成的串。
 * 返回值类型：
 *      二叉树根节点指针
 */
extern BiTree CreateBiTree(char *nodes1, char *nodes2);

/*
 * 通过先序和中序创建二叉树
 * 参数：
 *      pre：in，包含先序遍历的字符串
 *      in：in，包含中序遍历的字符串
 * 返回值类型：
 *      二叉树根节点指针
 */
extern BiTree CreateBiTreeByPreIn(char *pre, char *in);

/*
 * 销毁二叉树
 * 参数：
 *      root：in，二叉树根节点指针
 * 返回值类型：
 *      无
 */
extern void DestroyBiTree(BiTree root);

/*
 * 先序遍历二叉树
 * 参数：
 *      root：in，二叉树根节点指针
 *      Visit：in，访问二叉树节点数据的回调函数
 * 返回值类型：
 *      无
 */
extern void PreOrder(BiTree root, CALLBACK Visit);

/*
 * 先序遍历二叉树
 * 参数：
 *      root：in，二叉树根节点指针
 *      Visit：in，访问二叉树节点数据的回调函数
 * 返回值类型：
 *      无
 */
extern void InOrder(BiTree root, CALLBACK Visit);

/*
 * 先序遍历二叉树
 * 参数：
 *      root：in，二叉树根节点指针
 *      Visit：in，访问二叉树节点数据的回调函数
 * 返回值类型：
 *      无
 */
extern void PostOrder(BiTree root, CALLBACK Visit);

