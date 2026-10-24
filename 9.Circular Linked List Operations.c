#include <stdio.h>
#include <stdlib.h>

/* Node structure of polynomial */
struct polyNode {
    int coef;
    int exp;
    struct polyNode *next;
};

/* Allocation of memory for head node */
struct polyNode* initNode() {
    struct polyNode *head = (struct polyNode *)malloc(sizeof(struct polyNode));
    head->exp = -1;
    head->coef = 0;
    head->next = head;
    return head;
}

/* Creation of Link List */
void create(struct polyNode *H) {
    struct polyNode *temp = H;
    struct polyNode *curr;
    char choice;

    do {
        curr = (struct polyNode *)malloc(sizeof(struct polyNode));
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &curr->coef, &curr->exp);
        curr->next = H;
        temp->next = curr;
        temp = curr;

        printf("Do you want to add more terms (y/n)? ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
}

/* Display Link List */
void display(struct polyNode *H) {
    if (H->next == H) {
        printf("List is empty\n");
        return;
    }
    struct polyNode *curr = H->next;
    while (curr != H) {
        printf("%dx^%d ", curr->coef, curr->exp);
        if (curr->next != H) {
            printf("+ ");
        }
        curr = curr->next;
    }
    printf("\n");
}

/* Addition of Polynomial */
struct polyNode* add(struct polyNode *H1, struct polyNode *H2) {
    struct polyNode *H3 = (struct polyNode *)malloc(sizeof(struct polyNode));
    H3->exp = -1;
    H3->coef = 0;
    H3->next = H3;

    struct polyNode *t3 = H3;
    struct polyNode *t1 = H1->next;
    struct polyNode *t2 = H2->next;
    struct polyNode *temp;

    while (t1->exp != -1 || t2->exp != -1) {
        /* Case 3: exponent of p1 == exponent of p2 */
        if (t1->exp == t2->exp) {
            temp = (struct polyNode *)malloc(sizeof(struct polyNode));
            temp->coef = t1->coef + t2->coef;
            temp->exp = t1->exp;
            temp->next = H3;
            t3->next = temp;
            t3 = temp;
            t1 = t1->next;
            t2 = t2->next;
        }
        /* Case 1: exponent of p1 > exponent of p2 */
        else if (t1->exp > t2->exp) {
            temp = (struct polyNode *)malloc(sizeof(struct polyNode));
            temp->coef = t1->coef;
            temp->exp = t1->exp;
            temp->next = H3;
            t3->next = temp;
            t3 = temp;
            t1 = t1->next;
        }
        /* Case 2: exponent of p1 < exponent of p2 */
        else {
            temp = (struct polyNode *)malloc(sizeof(struct polyNode));
            temp->coef = t2->coef;
            temp->exp = t2->exp;
            temp->next = H3;
            t3->next = temp;
            t3 = temp;
            t2 = t2->next;
        }
    }
    return H3;
}

int main() {
    struct polyNode *H1 = initNode();
    struct polyNode *H2 = initNode();
    struct polyNode *H3;

    printf("--- Polynomial 1 ---\n");
    create(H1);

    printf("\n--- Polynomial 2 ---\n");
    create(H2);

    printf("\nPolynomial 1: ");
    display(H1);

    printf("Polynomial 2: ");
    display(H2);

    /* Addition of two polynomials */
    H3 = add(H1, H2);

    printf("Resultant Polynomial: ");
    display(H3);

    return 0;
}
