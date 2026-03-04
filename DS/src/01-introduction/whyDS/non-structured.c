#include <stdio.h>
#include <string.h>

#define N   5

/* 
 * 雇员信息
 * 采用了离散的多个数组来存储信息，这割裂了数据原本的内在联系
 */
int id[N] = { 1005, 1003, 1004, 1002, 1001 };
char name[N][10] = { "xyz", "idbc", "mno", "def", "rst"};

/*
 * 数据没有合理组织，算法变得更复杂，并且不利于功能扩展。
 * 例如，如果再增加一个属性gender，那么排序算法必须增加对这个属性的交换代码。
 */
void sort(int len) {
    int i, j;
    int t;
    char s[5];

    for (i = 0; i < len - 1; ++i)
        for (j = 0; j < len - i - 1; ++j)
            if (id[j] > id[j + 1]) {
                t = id[j];
                id[j] = id[j + 1];
                id[j + 1] = t;

                strcpy(s, name[j]);
                strcpy(name[j], name[j+1]);
                strcpy(name[j+1], s);
            }
}

void list(int len) {
    for (int i = 0; i < len; ++i)
        printf("%d\t%s\n", id[i], name[i]);
}

int main() {
    sort(N);
    list(N);
    
    return 0;
}