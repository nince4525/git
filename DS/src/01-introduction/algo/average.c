#include <stdio.h>

typedef unsigned short ushort;

ushort average(ushort a, ushort b) {
    ushort c = (ushort)(a + b) / 2;
    return c;
}

ushort average2(ushort a, ushort b) {
    ushort c = a / 2 + b / 2 + (a & b & 1);
    return c;
}

int main() {
    ushort a, b;
    scanf("%hu%hu", &a, &b);
    printf("%hu\n", average2(a, b));

    return 0;
}