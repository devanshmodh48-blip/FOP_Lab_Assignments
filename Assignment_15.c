#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    printf("Enter count: ");
    scanf("%d", &n);
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        printf("%d ", rand());
    }
    return 0;
}
