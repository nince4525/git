//算法的时间度量

#include <stdio.h>

//O(n^3)
//100*100*100
void f1() {
    int i, j, k;

    for (i = 0; i <= 100; ++i)
        for (j = 0; j <= 100; ++j)
            for (k = 0; k <= 100; ++k)
                if (i + j + k == 100 && 15 * i + 9 * j + k == 300)
                    printf("%d, %d, %d\n", i, j, k);
}

//O(n^3)
//20*33*100
void f2() {
    int i, j, k;

    for (i = 0; i <= 20; ++i)
        for (j = 0; j <= 33; ++j)
            for (k = 0; k <= 100; ++k)
                if (i + j + k == 100 && 15 * i + 9 * j + k == 300)
                    printf("%d, %d, %d\n", i, j, k);
}

//O(n^2)
//20*33
void f3() {
    int i, j, k;

    for (i = 0; i <= 20; ++i)
        for (j = 0; j <= 33; ++j) {
            k = 100 - i - j;
            if (i + j + k == 100 && 15 * i + 9 * j + k == 300)
                printf("%d, %d, %d\n", i, j, k);
        }
}

int main() {
    f3();

    return 0;
}