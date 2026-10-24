#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define SIZE 50

int stack[SIZE];
int top = -1;

/* Check if stack is empty */
int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

/* Check if stack is full */
int isFull() {
    if (top == SIZE - 1)
        return 1;
    else
        return 0;
}

/* Push value onto stack */
void pushval(int val) {
    if (isFull()) {
        printf("\nStack Overflow!");
    } else {
        top++;
        stack[top] = val;
    }
}

/* Pop value from stack */
int popval() {
    if (isEmpty()) {
        printf("\nStack Underflow!");
        return -1;
    } else {
        int val = stack[top];
        top--;
        return val;
    }
}

/* Function to perform basic operations */
int calc(int a, int b, char op) {
    int ans = 0;
    switch (op) {
        case '+':
            ans = a + b;
            break;
        case '-':
            ans = a - b;
            break;
        case '*':
            ans = a * b;
            break;
        case '/':
            ans = a / b;
            break;
        case '^':
            ans = (int)pow(a, b);
            break;
        default:
            break;
    }
    return ans;
}

/* Function to evaluate postfix expression */
void eval(char post[SIZE]) {
    int op1, op2, ans, z;

    for (int i = 0; post[i] != '\0'; i++) {
        /* If character is an alphabet, ask user for value */
        if (isalpha(post[i])) {
            printf("Enter value of %c: ", post[i]);
            scanf("%d", &z);
            pushval(z);
        }
        /* If character is a direct digit */
        else if (isdigit(post[i])) {
            pushval(post[i] - '0');
        }
        /* If character is an operator */
        else {
            op2 = popval();
            op1 = popval();
            ans = calc(op1, op2, post[i]);
            pushval(ans);
        }
    }

    printf("\nEvaluation is: %d\n", stack[top]);
}

int main() {
    char postfix[SIZE];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    eval(postfix);

    return 0;
}
