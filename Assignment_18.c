#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100], rev[100];
    printf("Enter string: ");
    scanf("%s", s1);

    int len = strlen(s1);
    printf("Length = %d\n", len);

    for (int i = 0; i < len; i++) rev[i] = s1[len - i - 1];
    rev[len] = '\0';
    printf("Reversed = %s\n", rev);

    if (strcmp(s1, rev) == 0) printf("The string is a Palindrome\n");
    
    printf("Enter another string for equality: ");
    scanf("%s", s2);
    if (strcmp(s1, s2) == 0) printf("Strings are equal\n");
    else printf("Strings are not equal\n");
    
    return 0;
}
