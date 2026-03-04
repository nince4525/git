#include <stdio.h>

/*
 * 求两个数a和b的最大公约数
 * 算法思路
 * 用一个测试数i，从大的那个数的一半开始，测试i是否能同时被a和b除尽
 * 如果能，那么i就是它俩的最大公约数
 * 否则，i减一，再次测试，直到i等于0为止
 * 
 * 当参数较大时，算法收敛较慢，性能不好
*/
int gcd1(int a, int b) {
    for (int i = (a < b ? b : a) / 2; i > 0; --i)
        if (a % i == 0 && b % i == 0)
            return i;

    return 1;
}

//利用同余定理的辗转除法
//算法收敛很快
int gcd2(int a, int b) {
    //保证a不小于b
    if (a < b) {
        int t = b;
        b = a;
        a = t;
    }

    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

//辗转除法的递归形式，代码更加简洁
int gcd3(int a, int b) {
    if (a < b) return gcd3(b, a);

    return b == 0 ? a : gcd3(b, a % b);
}

int main() {
    int x, y;

    scanf("%d%d", &x, &y);
    printf("%d, %d, %d\n", gcd1(x, y), gcd2(x, y), gcd3(x, y));

    return 0;
}
