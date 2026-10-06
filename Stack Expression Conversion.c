#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 256
#define DATA_SIZE 256

char stk[SIZE][DATA_SIZE];
int top = -1;

void resetStack(void) {
    top = -1;
}

void push(const char *c) {
    if (top >= SIZE - 1) {
        printf("\nStack overflow!\n");
    } else {
        strncpy(stk[++top], c, DATA_SIZE - 1);
        stk[top][DATA_SIZE - 1] = '\0';
    }
}

void pushChar(char c) {
    char buf[2] = {c, '\0'};
    push(buf);
}

char* pop(void) {
    if (top == -1) {
        printf("\nStack underflow!\n");
        return "";
    }
    return stk[top--];
}

char* peek(void) {
    if (top == -1) return "";
    return stk[top];
}

/* Stack precedence */
int spCheck(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': case '%': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

/* Coming precedence */
int cpCheck(char op) {
    switch (op) {
        case '^': return 4; /* Right-associative exponentiation */
        case '*': case '/': case '%': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

void strRev(char in[]) {
    int len = strlen(in);
    for (int i = 0; i < len / 2; i++) {
        char temp = in[i];
        in[i] = in[len - i - 1];
        in[len - i - 1] = temp;
    }
}

/* Infix to Postfix */
void in2pos(char in[], char pos[]) {
    resetStack();
    int posIndex = 0;

    for (int i = 0; in[i] != '\0'; i++) {
        char ch = in[i];
        if (isalnum(ch)) {
            pos[posIndex++] = ch;
        } else if (ch == '(') {
            pushChar(ch);
        } else if (ch == ')') {
            while (top != -1 && peek()[0] != '(') {
                pos[posIndex++] = pop()[0];
            }
            if (top != -1) pop(); /* Discard '(' */
        } else {
            while (top != -1 && peek()[0] != '(' && spCheck(peek()[0]) >= cpCheck(ch)) {
                pos[posIndex++] = pop()[0];
            }
            pushChar(ch);
        }
    }
    while (top != -1) {
        char *temp = pop();
        if (temp[0] != '(') pos[posIndex++] = temp[0];
    }
    pos[posIndex] = '\0';
}

/* Infix to Prefix */
void in2pre(char in[], char pre[]) {
    resetStack();
    char tempIn[DATA_SIZE];
    strncpy(tempIn, in, DATA_SIZE - 1);
    tempIn[DATA_SIZE - 1] = '\0';

    strRev(tempIn);
    for (int i = 0; tempIn[i] != '\0'; i++) {
        if (tempIn[i] == '(') tempIn[i] = ')';
        else if (tempIn[i] == ')') tempIn[i] = '(';
    }

    int preIndex = 0;
    for (int i = 0; tempIn[i] != '\0'; i++) {
        char ch = tempIn[i];
        if (isalnum(ch)) {
            pre[preIndex++] = ch;
        } else if (ch == '(') {
            pushChar(ch);
        } else if (ch == ')') {
            while (top != -1 && peek()[0] != '(') {
                pre[preIndex++] = pop()[0];
            }
            if (top != -1) pop(); /* Discard '(' */
        } else {
            /* Strictly greater handles right-to-left scan correctly */
            while (top != -1 && peek()[0] != '(' && spCheck(peek()[0]) > cpCheck(ch)) {
                pre[preIndex++] = pop()[0];
            }
            pushChar(ch);
        }
    }
    while (top != -1) {
        char *temp = pop();
        if (temp[0] != '(') pre[preIndex++] = temp[0];
    }
    pre[preIndex] = '\0';
    strRev(pre);
}

/* Postfix to Infix */
void pos2in(char pos[], char in[]) {
    resetStack();
    char op1[DATA_SIZE], op2[DATA_SIZE], eq[DATA_SIZE];

    for (int i = 0; pos[i] != '\0'; i++) {
        char ch = pos[i];
        if (isalnum(ch)) {
            pushChar(ch);
        } else {
            strcpy(op2, pop());
            strcpy(op1, pop());
            snprintf(eq, sizeof(eq), "(%s%c%s)", op1, ch, op2);
            push(eq);
        }
    }
    strcpy(in, pop());
}

/* Postfix to Prefix */
void pos2pre(char pos[], char pre[]) {
    resetStack();
    char op1[DATA_SIZE], op2[DATA_SIZE], eq[DATA_SIZE];

    for (int i = 0; pos[i] != '\0'; i++) {
        char ch = pos[i];
        if (isalnum(ch)) {
            pushChar(ch);
        } else {
            strcpy(op2, pop());
            strcpy(op1, pop());
            snprintf(eq, sizeof(eq), "%c%s%s", ch, op1, op2);
            push(eq);
        }
    }
    strcpy(pre, pop());
}

/* Prefix to Infix */
void pre2in(char pre[], char in[]) {
    resetStack();
    char op1[DATA_SIZE], op2[DATA_SIZE], eq[DATA_SIZE];
    int len = strlen(pre);

    /* Read from right to left */
    for (int i = len - 1; i >= 0; i--) {
        char ch = pre[i];
        if (isalnum(ch)) {
            pushChar(ch);
        } else {
            strcpy(op1, pop());
            strcpy(op2, pop());
            snprintf(eq, sizeof(eq), "(%s%c%s)", op1, ch, op2);
            push(eq);
        }
    }
    strcpy(in, pop());
}

/* Prefix to Postfix */
void pre2pos(char pre[], char pos[]) {
    resetStack();
    char op1[DATA_SIZE], op2[DATA_SIZE], eq[DATA_SIZE];
    int len = strlen(pre);

    /* Read from right to left */
    for (int i = len - 1; i >= 0; i--) {
        char ch = pre[i];
        if (isalnum(ch)) {
            pushChar(ch);
        } else {
            strcpy(op1, pop());
            strcpy(op2, pop());
            snprintf(eq, sizeof(eq), "%s%s%c", op1, op2, ch);
            push(eq);
        }
    }
    strcpy(pos, pop());
}

int main(void) {
    int inOP, outOP;
    char in[DATA_SIZE], out[DATA_SIZE * 2];

    while (1) {
        printf("Enter 0 to exit\n");
        printf("What are you inputting?\n1. Infix\n2. Postfix\n3. Prefix\nChoice: ");
        if (scanf("%d", &inOP) != 1 || inOP == 0) return 0;

        printf("What do you want for the output?\n1. Infix\n2. Postfix\n3. Prefix\nChoice: ");
        if (scanf("%d", &outOP) != 1) return 0;

        printf("Enter input string: ");
        scanf("%s", in);

        int choice = 10 * inOP + outOP;
        switch (choice) {
            case 11: case 22: case 33: strcpy(out, in); break;
            case 12: in2pos(in, out); break;
            case 13: in2pre(in, out); break;
            case 21: pos2in(in, out); break;
            case 23: pos2pre(in, out); break;
            case 31: pre2in(in, out); break;
            case 32: pre2pos(in, out); break;
            default:
                printf("Invalid selection!\n\n");
                continue;
        }
        printf("In:  %s\nOut: %s\n\n", in, out);
    }
    return 0;
}
