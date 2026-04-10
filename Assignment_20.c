#include <stdio.h>

void swapVal(int a, int b) {
    int t = a; a = b; b = t;
}

void swapRef(int *x, int *y) {
    int t = *x; *x = *y; *y = t;
}

int main() {
    int a, b, x, y;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    x = a; y = b;
    swapVal(a, b);
    printf("After swap by value: a=%d b=%d\n", a, b);
    swapRef(&x, &y);
    printf("After swap by reference: x=%d y=%d\n", x, y);
    return 0;
}
