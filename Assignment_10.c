#include <stdio.h>

int main() {
    int choice, i, n1_int;
    float num1, num2;
    long long fact = 1;

    printf("1.Add 2.Sub 3.Mul 4.Div 5.Power 6.Factorial\nChoice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 5:
            printf("Base and Exponent: ");
            scanf("%f %f", &num1, &num2);
            float p = 1;
            for(i = 0; i < (int)num2; i++) p *= num1;
            printf("Result = %.2f\n", p);
            break;
        case 6:
            printf("Number: ");
            scanf("%d", &n1_int);
            for(i = 1; i <= n1_int; i++) fact *= i;
            printf("Result = %lld\n", fact);
            break;
        default:
            printf("Numbers: ");
            scanf("%f %f", &num1, &num2);
            if (choice == 1) printf("Result = %.2f\n", num1 + num2);
            else if (choice == 2) printf("Result = %.2f\n", num1 - num2);
            else if (choice == 3) printf("Result = %.2f\n", num1 * num2);
            else if (choice == 4 && num2 != 0) printf("Result = %.2f\n", num1 / num2);
    }
    return 0;
}
