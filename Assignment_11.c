#include <stdio.h>
#include <math.h>

int main() {
    int num, choice, i, isPrime = 1;
    printf("Number: ");
    scanf("%d", &num);
    printf("1.Sqrt 2.Square 3.Cube 4.Prime 5.Factorial 6.Prime Factors\nChoice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: printf("%.2f\n", sqrt(num)); break;
        case 2: printf("Square = %d\n", num * num); break;
        case 3: printf("Cube = %d\n", num * num * num); break;
        case 4:
            if(num < 2) isPrime = 0;
            for(i = 2; i <= num/2; i++) if(num % i == 0) isPrime = 0;
            if(isPrime) printf("Prime\n"); else printf("Not Prime\n");
            break;
        case 5:
            {
                long long f = 1;
                for(i = 1; i <= num; i++) f *= i;
                printf("Factorial = %lld\n", f);
            }
            break;
        case 6:
            for(i = 2; i <= num; i++) {
                while(num % i == 0) { printf("%d ", i); num /= i; }
            }
            printf("\n");
            break;
    }
    return 0;
}
