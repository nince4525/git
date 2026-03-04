/* 
 * Copyright (c) 白忠建 电子科技大学信息与软件工程学院
 * C语言程序示例 is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2. 
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2 
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PSL v2 for more details. 
 */


/**
 * @file const-parameter.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示了参数用const约束时的情况，同时演示了const修饰指针的情况
 * @version 1.0
 * @date 2024-11-06
 * 
 * @copyright Copyright (c) 白忠建. All rights reserved.
 * 
 */

typedef int* INTP;


int main() {
    int i = 0;
    int j = 1;
    
    // --- case 1
    const int *p = &i; // 指向常量的变量指针：const修饰的是int
    *p = 1; // error：在p“眼里”，它指向的是个常量
    p = &j; // OK, p本身是变量，可以指向其它整数变量

    // --- case 2
    // const int 和 int const是等价的！
    const int a = 0;
    int const b = 0; // 等价于：const int b = 0;

    // case 2 涉及的内容，我在课堂上说，const修饰的是*。这是错误的！！！
    // 这里，我诚挚地向大家道歉，同时向指出这个问题的同学表示深深的感谢！
    int const *q = &i; // 等价于 const int *q，q是指向常量的变量指针。
    *q = 1; // error：在p“眼里”，它指向的是个常量
    q = &j; // OK, p本身是变量，可以指向其它整数变量

    // --- case 3
    // case 3 涉及的内容，我在课堂上讲的也有些模糊甚至错误。这里给出更清晰的解释。同样向大家道歉！
    int * const t = &i; // 指向了变量单元的常量指针：const修饰的是int *。
    // 这说明int *是个常量，即指针是常量；而该指针的基类型是int，没有const约束，因此是变量
    *t = 1; // OK，t是常量，但它指向的变量
    t = &j; // error，t是常量不能修改

    // --- case 4
    const INTP x = &i; // 等价于：int * const x;
    INTP const y = &j; // 等价于：int * const y;
    *x = 1; // OK
    *y = 2; // OK
    x = &j; // error
    y = &i; // error

    return 0;
}

// 以下展示指针作为参数的情况。
// 以下，f1和f2的参数列表等价
void f1(const int *x) { // case 1
    int i = -1;
    *x = i; // error
    x = &i; // OK
} 

void f2(int const *x) { // case 2
    int i = -1;
    *x = i; // error
    x = &i; // OK
}

// 以下，f3、f4和f5的参数列表等价
void f3(int * const x) { // case 3
    int i = -1;
    *x = i; // OK
    x = &i; // error
}

void f4(const INTP x) { // case 4
    int i = -1;
    *x = i; // OK
    x = &i; // error
} 

void f5(INTP const x) { // case 4
    int i = -1;
    *x = i; // OK
    x = &i; // error
}