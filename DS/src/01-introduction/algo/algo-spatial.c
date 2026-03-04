//算法的空间度量

#include <stdio.h>

/*
 * 这个程序展示了查找算法
 * 算法查找一个乱序数组中是否存在指定的值
 * 假设该数组中没有重复值，最大值是MAX，最小值是MIN
 */

#define N   9

#define MAX 17
#define MIN -2

int x[] = {16, 8, MIN, 15, 13, MAX, 5, 11, 2};

/*
 * 顺序查找法
 * 没有用到辅助空间，因此，S: O(1), T: O(n)
 */
int find1(int a[], int len, int key) {
    for (int i = 0; i < len; ++i)
        if (a[i] == key) return i;
    return -1;
}

/*
 * 这是Hash算法的一个超级简化的特例
 * 首先，将原始数组a中的元素分散到一个hash数组h中
 * 一般情况下，h数组的长度要大于a的长度
 * 通过一种映射算法，将a[i]的值转换成在h中的下标
 * 根据假定，原始数组a中没有重复值，这个下标也是唯一的
 * 此后，查找就在h数组中进行
 */
int h[MAX - MIN + 1];

//key到下标的映射算法
static int HASH_KEY(int key) {
    return key - MIN;
}

//将原始数组分散到一个hash数组中
static void hash(int a[], int len, int h[]) {
    for (int i = 0; i < len; ++i)
        h[HASH_KEY(a[i])] = a[i];
}

/*
 * hash数组比原始数组要长。
 * 设 a = ((MAX-MIN+1) / N) - 1
 * 则hash数组要比原始数组多用 a*N 个单元
 * S: O(a*n), T: O(1)
 */
int find2(int h[], int key) {
    return (key < MIN || key > MAX) ? -1 : HASH_KEY(key);
}

int main() {
    int i, key;

    printf("Please input a key: ");
    scanf("%d", &key);

    i = find1(x, N, key);
    if (i >= 0)
        printf("sequential: %d @ %d\n", key, i);
    else
        printf("not found\n");

    hash(x, N, h);
    i = find2(h, key);
    if (i >= 0)
        printf("hashed: %d @ %d\n", key, i);
    else
        printf("not found\n");

    return 0;
}