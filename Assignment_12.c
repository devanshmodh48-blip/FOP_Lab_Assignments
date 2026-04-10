#include <stdio.h>

int main() {
    int n1, n2, a, b, temp, scd = -1;
    printf("Number 1 and 2: ");
    scanf("%d %d", &n1, &n2);

    for(int i = 2; i <= (n1 < n2 ? n1 : n2); i++) {
        if(n1 % i == 0 && n2 % i == 0) { scd = i; break; }
    }
    if(scd != -1) printf("Smallest Common Divisor: %d\n", scd);

    a = n1; b = n2;
    while(b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    printf("GCD: %d\n", a);
    return 0;
}
