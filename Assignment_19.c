#include <stdio.h>
#include <string.h>

struct EMPLOYEE {
    char name[50], desig[50], gen[10], doj[15];
    float sal;
};

int main() {
    int n, m=0, f=0;
    struct EMPLOYEE e[100];
    printf("Enter count: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %s %s %s %f", e[i].name, e[i].desig, e[i].gen, e[i].doj, &e[i].sal);
        if (strcmp(e[i].gen, "Male") == 0) m++;
        else f++;
        if (e[i].sal > 10000) printf("High salary: %s\n", e[i].name);
    }
    printf("Total: %d, Male: %d, Female: %d\n", n, m, f);
    return 0;
}
