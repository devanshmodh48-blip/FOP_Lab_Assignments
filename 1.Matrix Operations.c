#include <stdio.h>
#define MAX 10
int main() {
int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX], AT[MAX][MAX];
int r1, c1, r2, c2, i, j, k;
printf("Enter rows and columns for Matrix A: ");
scanf("%d %d"
, &r1, &c1);
printf("Enter elements of Matrix A:\n");
for (i = 0; i < r1; i++) {
for (j = 0; j < c1; j++) {
scanf("%d"
, &A[i][j]);
}
}
printf("Enter rows and columns for Matrix B: ");
scanf("%d %d"
, &r2, &c2);
printf("Enter elements of Matrix B:\n");
for (i = 0; i < r2; i++) {
for (j = 0; j < c2; j++) {
scanf("%d"
, &B[i][j]);
}
}
printf("\n--- Matrix Operations ---\n");
if (r1 == r2 && c1 == c2) {
printf("\nMatrix Addition (A + B):\n");
for (i = 0; i < r1; i++) {
for (j = 0; j < c1; j++) {
C[i][j] = A[i][j] + B[i][j];
printf("%d\t"
, C[i][j]);
}
printf("\n");
}
} else {
printf("\nMatrix Addition not possible: Dimensions do not match.\n");
}
if (r1 == r2 && c1 == c2) {
printf("\nMatrix Subtraction (A - B):\n");
for (i = 0; i < r1; i++) {
for (j = 0; j < c1; j++) {
C[i][j] = A[i][j] - B[i][j];
printf("%d\t"
, C[i][j]);
}
printf("\n");
}
} else {
printf("\nMatrix Subtraction not possible: Dimensions do not match.\n");
}
if (c1 == r2) {
printf("\nMatrix Multiplication (A * B):\n");
for (i = 0; i < r1; i++) {
for (j = 0; j < c2; j++) {
C[i][j] = 0;
for (k = 0; k < c1; k++) {
C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
}
printf("%d\t"
, C[i][j]);
}
printf("\n");
}
} else {
printf("\nMatrix Multiplication not possible: Columns of A != Rows of B.\n");
}
printf("\nTranspose of Matrix A:\n");
for (i = 0; i < r1; i++) {
for (j = 0; j < c1; j++) {
AT[j][i] = A[i][j];
}
}
for (i = 0; i < c1; i++) {
for (j = 0; j < r1; j++) {
printf("%d\t"
, AT[i][j]);
}
printf("\n");
}
return 0;
}
