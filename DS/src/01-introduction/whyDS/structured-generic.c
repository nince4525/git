/*
 * 更通用的排序算法
 * 将“比较操作”抽象出来，作为回调函数(callback)传递给排序算法
 * 此外，数组的类型采用“万能指针”void*。这使得算法具有了一点“泛型(generics)”的特性
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef void* POINTER;

/*
 * 类型定义
 * 定义一个三向比较函数类型
 * 如果第一个参数指向的值比第二个参数指向的值“小”，返回负值；“相等”返回0；“大”返回正值
 * 函数的参数采用指针，是为了避免值参数的复制
*/
typedef int COMPARE_FUNCTION(POINTER, POINTER);

/*
 * 函数的数组参数无类型，这使得sort算法适用于任意类型
 * 参数说明
 * a:       没有类型的字节数组。这意味着，数组a的元素的大小是1字节
 * len:     待排序原始数组的长度
 * size:    待排序原始数组的元素的大小
 * compare: 三向比较函数
*/
void sort(POINTER a, int len, int size, COMPARE_FUNCTION compare) {
    int i, j;
    POINTER t, s, d;

    t = malloc(size);
    for (i = 0; i < len - 1; ++i)
        for (j = 0; j < len - i - 1; ++j) {
            /*
                因为a是无类型的字节数组，所以其元素的大小为1字节
                这样，表达式&a[j]或者a+j计算出的地址是a加上j个字节
                这个地址显然不是原始数组第j个元素的地址（除非原始数组元素的大小是1字节）
                又因为原始数组的每个元素的大小是size字节
                所以正确的地址应该是：a + j * size
            */
            s = a + j * size;   //&a[j]
            d = s + size;       //&a[j+1]
            if (compare(s, d) > 0) {
                memcpy(t, s, size); //字节复制
                memcpy(s, d, size);
                memcpy(d, t, size);
            }
        }
    free(t);
}

#define N   5

//更合理的数据结构
typedef struct {
    int id;
    char name[10];
} employee_t;

employee_t employees[N] = {
    {1005, "xyz"},
    {1003, "abc"},
    {1004, "mno"},
    {1002, "def"},
    {1001, "rst"}
};

void list(employee_t a[], int len) {
    for (int i = 0; i < len; ++i)
        printf("%d\t%s\n", a[i].id, a[i].name);
}

//定义两个回调函数，分别用不同的属性作为排序关键字
int emp_comp_by_id(POINTER a, POINTER b) {
    employee_t* x = (employee_t*)a, *y = (employee_t*)b; //强制类型转换
    return x->id - y->id;
}

int emp_comp_by_name(POINTER a, POINTER b) {
    employee_t* x = (employee_t*)a, *y = (employee_t*)b; //强制类型转换
    return strcmp(x->name, y->name);
}

int main() {
    int i;

    printf("Please choose sort by what(1 by id, other by name): ");
    scanf("%d", &i);
    sort(employees, N, sizeof(employee_t), i == 1 ? emp_comp_by_id : emp_comp_by_name);

    list(employees, N);

    return 0;
}