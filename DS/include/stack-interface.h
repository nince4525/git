/*
 * 栈的典型操作接口声明。所有类型的栈都应该实现这些接口。
 */

#include <stdbool.h>

#include "auxf.h"

/*
 * 以下列出栈的典型操作接口声明。所有类型的栈都应该实现这些接口。
 * 
 * 接口函数描述中：
 * in： 表示输入参数
 * out：表示输出参数
 */

/*
 * 初始化栈
 * 参数：
 *      S：in，栈指针
 * 返回值类型：
 *      无
 */
extern void InitStack(StackPtr *S);

/*
 * 压栈
 * 参数
 *      S：in/out，栈指针
 *      x：in，待压入的值
 * 返回值类型
 *      bool值：true表示插入成功，false表示失败
 */
extern bool Push(StackPtr S, StackElementType x);

/*
 * 获取栈顶值，但不弹栈（退栈）
 * 参数
 *      S：in/out，栈指针
 *      x：out，保存获取的值
 * 返回值类型
 *      bool值：true表示成功，false表示失败
 */
extern bool GetTop(StackPtr S, StackElementType* x);

/*
 * 弹栈（退栈）
 * 参数
 *      S：in/out，栈指针
 *      x：out，保存弹出的值
 * 返回值类型
 *      bool值：true表示删除成功，false表示失败
 */
extern bool Pop(StackPtr S, StackElementType* x);

/*
 * 销毁栈，将其置为空
 * 参数
 *      S：in/out，栈指针
 * 返回值类型
 *      无
 */
extern void ClearStack(StackPtr S);

/*
 * 测试栈是否为空
 * 参数
 *      S：in/out，栈指针
 * 返回值类型
 *      bool值：true表示栈空，false表示未空
 */
extern bool IsEmpty(StackPtr S);

/*
 * 测试栈是否满
 * 参数
 *      S：in/out，栈指针
 * 返回值类型
 *      bool值：true表示栈满，false表示未满
 */
extern bool IsFull(StackPtr S);
