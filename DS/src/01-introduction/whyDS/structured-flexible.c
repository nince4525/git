/*
 * 更灵活的排序算法
 * 将“比较操作”抽象出来，作为回调函数(callback)传递给排序算法
 */

#include <stdio.h>
#include <string.h>

#define N   5

//更合理的数据结构
typedef struct {
    int id;
    char name[10];
} employee_t, *emp_pointer;

employee_t employees[N] = {
    {1005, "xyz"},
    {1003, "abc"},
    {1004, "mno"},
    {1002, "def"},
    {1001, "rst"}
};

/*
 * 类型定义
 * 定义一个三向比较函数类型
 * 如果第一个参数比第二个参数“小”，返回负值；“相等”返回0；“大”返回正值
 * 函数的参数采用指针，是为了避免值参数的复制
*/
typedef int COMPARE_FUNCTION(emp_pointer, emp_pointer);

/*
 * 参数 compare 是一个回调函数，这会更灵活地处理不同关键字的排序
 * 但还是不够通用，sort只能针对employee_t类型的数组排序
 */
void sort(employee_t a[], int len, COMPARE_FUNCTION compare) {
    int i, j;
    employee_t t;

    for (i = 0; i < len - 1; ++i)
        for (j = 0; j < len - i - 1; ++j)
            if (compare(&a[j], &a[j + 1]) > 0) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
}

void list(employee_t a[], int len) {
    for (int i = 0; i < len; ++i)
        printf("%d\t%s\n", a[i].id, a[i].name);
}

//定义两个回调函数，分别用不同的属性作为排序关键字
int emp_comp_by_id(emp_pointer a, emp_pointer b) {
    return a->id - b->id;
}

int emp_comp_by_name(emp_pointer a, emp_pointer b) {
    return strcmp(a->name, b->name);
}

int main() {
    int i;

    printf("Please choose sort by what(1 by id, other by name): ");
    scanf("%d", &i);
    sort(employees, N, i == 1 ? emp_comp_by_id : emp_comp_by_name);

    list(employees, N);

    return 0;
}