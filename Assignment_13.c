#include <stdio.h>

int main() {
    int num, rem;
    printf("Number: ");
    scanf("%d", &num);

    printf("Digits in reverse order: ");
    if (num == 0) printf("0");
    while (num != 0) {
        rem = num % 10;
        printf("%d ", rem);
        num /= 10;
    }
    printf("\n");
    return 0;
}
