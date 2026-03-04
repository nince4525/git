/*
 * 队列的典型操作接口声明。所有类型的队列都应该实现这些接口。
 */

#include <stdbool.h>

#include "auxf.h"

/*
 * 以下列出队列的典型操作接口声明。所有类型的队列都应该实现这些接口。
 * 
 * 接口函数描述中：
 * in： 表示输入参数
 * out：表示输出参数
 */

/*
 * 初始化队列
 * 参数：
 *      Q：in，队列指针
 * 返回值类型：
 *      无
 */
extern void InitQueue(QueuePtr Q);

/*
 * 压队列
 * 参数
 *      Q：in/out，队列指针
 *      x：in，待压入的值
 * 返回值类型
 *      bool值：true表示插入成功，false表示失败
 */
extern bool EnterQueue(QueuePtr Q, QueueElementType x);

/*
 * 获取队列顶值，但不弹队列（退队列）
 * 参数
 *      Q：in/out，队列指针
 *      x：out，保存获取的值
 * 返回值类型
 *      bool值：true表示成功，false表示失败
 */
extern bool GetHead(QueuePtr Q, QueueElementType* x);

/*
 * 弹队列（退队列）
 * 参数
 *      Q：in/out，队列指针
 *      x：out，保存弹出的值
 * 返回值类型
 *      bool值：true表示删除成功，false表示失败
 */
extern bool DeleteQueue(QueuePtr Q, QueueElementType* x);

/*
 * 销毁队列，将其置为空
 * 参数
 *      Q：in/out，队列指针
 * 返回值类型
 *      无
 */
extern void ClearQueue(QueuePtr Q);

/*
 * 测试队列是否为空
 * 参数
 *      Q：in/out，队列指针
 * 返回值类型
 *      bool值：true表示队列空，false表示未空
 */
extern bool IsEmpty(QueuePtr Q);

/*
 * 测试队列是否满
 * 参数
 *      Q：in/out，队列指针
 * 返回值类型
 *      bool值：true表示队列满，false表示未满
 */
extern bool IsFull(QueuePtr Q);

