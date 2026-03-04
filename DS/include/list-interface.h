/*
 * 线性表的典型操作接口声明。所有类型的线性表都应该实现这些接口。
 * 参见教材p39 2.1.2
 */

#include <stdbool.h>

#include "auxf.h"

/*
 * 以下列出线性表的典型操作接口声明。所有类型的线性表都应该实现这些接口。
 * 
 * 接口函数描述中：
 * in： 表示输入参数
 * out：表示输出参数
 */

/*
 * 初始化线性表
 * 参数：
 *      L：in/out，线性表指针
 * 返回值类型：
 *      无
 */
extern void InitList(LListPtr *L);

/*
 * 在线性表指定位置插入元素
 * 参数
 *      L：in/out，线性表指针
 *      i：in，插入位置。位置从1开始。在位置i插入元素，意味着插入元素将成为第i个，原来的元素位次依次后移一位
 *      e：in，待插入的值
 * 返回值类型
 *      bool值：true表示插入成功，false表示失败
 */
extern bool InsList(LListPtr L, int i, ElemType e);

/*
 * 在线性表指定位置删除元素
 * 参数
 *      L：in/out，线性表指针
 *      i：in，删除位置。位置从1开始。在位置i删除元素，意味着原来的元素位次依次前移一位
 *      e：out，保存删除的那个元素的值
 * 返回值类型
 *      bool值：true表示删除成功，false表示失败
 */
extern bool DelList(LListPtr L, int i, ElemType *e);

/*
 * 销毁线性表，将其置为空
 * 参数
 *      L：in/out，线性表指针
 * 返回值类型
 *      无
 */
extern void DestroyList(LListPtr L);

/*
 * 为线性表遍历函数接口定义的回调（callback）函数类型
 * 属于这种类型的函数拥有如下特征：
 * 带有一个ElemType*类型的参数，无返回值
 * 这种回调函数用来访问线性表中的数据
 * 在具体的项目中，应该定义属于这种类型的函数以便传递给遍历函数使用
 * 例如：
 * void print(ElemType *e) {
 *     printf("%d", *e);
 * }
 * 这个print函数的类型就是CALLBACK。
 */
typedef void CALLBACK(ElemType *);

/*
 * 从头到尾遍历线性表
 * 参数
 *      L：in/out，线性表指针
 *      f：in，回调函数。遍历函数在遍历过程中，将当前元素的数据值传递给f使用
 * 返回值类型
 *      无
 */
extern void Traverse(LListPtr L, CALLBACK f);

/*
 * 获取线性表中的第一个元素
 * 参数
 *      L：in/out，线性表指针
 *      e：out，保存获取的那个元素的值
 * 返回值类型
 *      bool值：true表示成功，false失败
 */
extern bool FirstList(LListPtr L, ElemType *e);

/*
 * 测试线性表是否为空。教材上是EmptyList，这个名字容易理解成清空线性表，
 * 参数
 *      L：in/out，线性表指针
 * 返回值类型
 *      bool值：true表示线性表空，false表示未空
 */
extern bool ListEmpty(LListPtr L);

/*
 * 测试线性表是否满
 * 参数
 *      L：in/out，线性表指针
 * 返回值类型
 *      bool值：true表示线性表满，false表示未满
 */
extern bool ListFull(LListPtr L);

/*
 * 将数据添加到线性表的尾部
 * 参数
 *      L：in/out，线性表指针
 *      e：in，待添加的元素值
 * 返回值类型
 *      无
 */
extern void PushList(LListPtr L, ElemType e);

/*
 * 将线性表逆序
 * 参数
 *      L：in/out，线性表指针
 * 返回值类型
 *      无
 */
extern void ReverseList(LListPtr L); 
