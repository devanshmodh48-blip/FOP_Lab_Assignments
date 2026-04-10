#include <stdio.h>

long int factorialIterative(int n) {
    long int res = 1;
    for (int i = 1; i <= n; i++) res *= i;
    return res;
}

long int factorialRecursive(int n) {
    if (n <= 1) return 1;
    return n * factorialRecursive(n - 1);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) return 1;

    printf("Iterative: %ld\n", factorialIterative(num));
    printf("Recursive: %ld\n", factorialRecursive(num));

    return 0;
}
