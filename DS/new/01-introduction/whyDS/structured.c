#include <stdio.h>

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

/* 
 * 用id作为关键字排序
 * 代码更简单，但不通用。例如，不能针对name排序
 * 究其原因，是排序用的关键字是固定的
 */
void sort(employee_t a[], int len) {
    int i, j;
    employee_t t;

    for (i = 0; i < len - 1; ++i)
        for (j = 0; j < len - i - 1; ++j)
            if (a[j].id > a[j + 1].id) {  //这里固定用id作为关键字来进行比较
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
}

void list(employee_t a[], int len) {
    for (int i = 0; i < len; ++i)
        printf("%d\t%s\n", a[i].id, a[i].name);
}

int main() {
    sort(employees, N);
    list(employees, N);

    return 0;
}