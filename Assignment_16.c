#include <stdio.h>

int main() {
    int n, arr[100], e[100], o[100], ec=0, oc=0;
    printf("Enter count: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0) e[ec++] = arr[i];
        else o[oc++] = arr[i];
    }

    printf("Even numbers are: ");
    for (int i = 0; i < ec; i++) printf("%d ", e[i]);
    printf("\nOdd numbers are: ");
    for (int i = 0; i < oc; i++) printf("%d ", o[i]);
    return 0;
}
