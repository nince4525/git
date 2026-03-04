//算法的优化

#include <stdio.h>

typedef long long LLONG;

LLONG fibo1(LLONG n) {
    return n <= 2 ? 1 : fibo1(n-1) + fibo1(n-2);
}

static LLONG _fibo2(LLONG n, LLONG f1, LLONG f2) {
    return n <= 2 ? f2 : _fibo2(n-1, f2, f1 + f2);
}

LLONG fibo2(LLONG n) {
    return _fibo2(n, 1, 1);
}

int main() {
    int i;
    LLONG n;

    scanf("%d%lld", &i, &n);
    printf("%lld\n", i == 1 ? fibo1(n) : fibo2(n));

    return 0;
}