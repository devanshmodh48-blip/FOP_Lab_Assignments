#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *s, *d;
    char c;
    s = fopen("source.txt", "r");
    d = fopen("dest.txt", "w");
    if (s == NULL || d == NULL) exit(1);

    while ((c = fgetc(s)) != EOF) {
        fputc(c, d);
    }
    printf("File copied successfully.\n");
    fclose(s); fclose(d);
    return 0;
}
