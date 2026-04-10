#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];
    int ch;
    printf("Enter two strings: ");
    scanf("%s %s", s1, s2);
    printf("1.Len 2.Cpy 3.Cat 4.Comp\nChoice: ");
    scanf("%d", &ch);

    switch(ch) {
        case 1: printf("Len: %lu\n", strlen(s1)); break;
        case 2: strcpy(s2, s1); printf("Copied: %s\n", s2); break;
        case 3: strcat(s1, s2); printf("Concat: %s\n", s1); break;
        case 4: printf("Comp: %d\n", strcmp(s1, s2)); break;
    }
    return 0;
}
