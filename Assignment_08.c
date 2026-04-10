#include <stdio.h>

int main() {
    int marks[5], total = 0, pass = 1;
    float perc;

    printf("Enter marks of five courses: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &marks[i]);
        if (marks[i] < 40) pass = 0;
        total += marks[i];
    }

    perc = total / 5.0;
    printf("Total Marks = %d\nPercentage = %.2f%%\n", total, perc);

    if (pass == 0) {
        printf("Result: FAIL\n");
    } else {
        printf("Result: PASS\n");
        if (perc >= 75) printf("Grade: Distinction\n");
        else if (perc >= 60) printf("Grade: First Division\n");
        else if (perc >= 50) printf("Grade: Second Division\n");
        else if (perc >= 40) printf("Grade: Third Division\n");
    }
    return 0;
}
