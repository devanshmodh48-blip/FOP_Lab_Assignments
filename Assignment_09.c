#include <stdio.h>

int main() {
    int num, original, rem, res = 0;
    printf("Enter a three-digit number: ");
    scanf("%d", &num);

    original = num;
    while (original != 0) {
        rem = original % 10;
        res += rem * rem * rem;
        original /= 10;
    }

    if (res == num) printf("%d is an Armstrong number.\n", num);
    else printf("%d is not an Armstrong number.\n", num);

    return 0;
}
