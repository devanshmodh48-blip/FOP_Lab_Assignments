#include <stdio.h>
#include <math.h>

int main() {
    int i, n, sign = 1;
    float x, term, sum;
    long long fact;

    printf("Enter value of x (in radians): ");
    scanf("%f", &x);
    printf("Enter number of terms: ");
    scanf("%d", &n);

    sum = 0;
    for (i = 0; i < n; i++) {
        fact = 1;
        for (int j = 1; j <= (2 * i + 1); j++) {
            fact *= j;
        }
        term = pow(x, 2 * i + 1) / fact;
        sum += sign * term;
        sign *= -1;
    }

    printf("Sum of sine series = %f\n", sum);
    return 0;
}
