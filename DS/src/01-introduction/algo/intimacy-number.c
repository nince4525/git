#include <stdio.h>

unsigned sum_of_factors(unsigned n) {
    unsigned sum = 0;
    for (unsigned i = 1; i <= n / 2; ++i)
        if (n % i == 0) sum += i;
    return sum;
}

int main() {
    unsigned n, a, b, c;

    scanf("%u", &n);
    for (a = 1; a <= n; ++a) {
        b = sum_of_factors(a);
        c = sum_of_factors(b);
        if (a == c && a < b)
            printf("(%u,%u)", a, b);
    }
    putchar('\n');

    return 0;
}

