#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    int marks[3];
    int total;
    float perc;
};

int main() {
    int n, i, j;
    struct Student s[100];

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Roll Number: ");
        scanf("%d", &s[i].roll);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Marks in 3 subjects: ");
        s[i].total = 0;
        for (j = 0; j < 3; j++) {
            scanf("%d", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }
        s[i].perc = s[i].total / 3.0;
    }

    for (i = 0; i < n; i++) {
        printf("\nRoll No: %d\nName: %s\nTotal: %d\nPercentage: %.2f%%\n", 
               s[i].roll, s[i].name, s[i].total, s[i].perc);
    }
    return 0;
}
