#include <stdio.h>
#include <stdlib.h>

#ifdef INTERACTIVE
#define PROMPT(...) printf(__VA_ARGS__)
#else
#define PROMPT(...)
#endif

typedef struct node {
    int coef;
    int exp;
    struct node *next;
} pnode;

pnode *new_poly(void)
{
    pnode *head = (pnode *)malloc(sizeof(pnode));
    if (head == NULL) {
        return NULL;
    }
    head->coef = 0;
    head->exp = -1;
    head->next = head;
    return head;
}

void insert_term(pnode *head, int coef, int exp)
{
    if (head == NULL || coef == 0) {
        return;
    }

    pnode *prev = head;
    pnode *curr = head->next;

    while (curr != head && curr->exp > exp) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != head && curr->exp == exp) {
        curr->coef += coef;
        if (curr->coef == 0) {
            prev->next = curr->next;
            free(curr);
        }
        return;
    }

    pnode *new_node = (pnode *)malloc(sizeof(pnode));
    if (new_node == NULL) {
        return;
    }
    new_node->coef = coef;
    new_node->exp = exp;
    new_node->next = curr;
    prev->next = new_node;
}

pnode *read_poly(void)
{
    pnode *head = new_poly();
    if (head == NULL) {
        return NULL;
    }

    int ch, c, e;
    while (1) {
        PROMPT("Do you want to enter a term? (1 = yes, 0 = no): ");
        if (scanf("%d", &ch) != 1 || ch != 1)
            break;
        PROMPT("Enter coefficient and exponent: ");
        if (scanf("%d %d", &c, &e) != 2)
            break;

        insert_term(head, c, e);
    }
    return head;
}

pnode *poly_add(pnode *h1, pnode *h2)
{
    pnode *sum = new_poly();
    if (sum == NULL) {
        return NULL;
    }

    if (h1 != NULL) {
        pnode *p = h1->next;
        while (p != h1) {
            insert_term(sum, p->coef, p->exp);
            p = p->next;
        }
    }

    if (h2 != NULL) {
        pnode *q = h2->next;
        while (q != h2) {
            insert_term(sum, q->coef, q->exp);
            q = q->next;
        }
    }

    return sum;
}

void free_poly(pnode *head)
{
    if (head == NULL) {
        return;
    }

    pnode *curr = head->next;
    while (curr != head) {
        pnode *next_node = curr->next;
        free(curr);
        curr = next_node;
    }

    free(head);
}

void print_poly(pnode *head)
{
    pnode *p = head->next;

    if (p == head) {
        printf("0\n");
        return;
    }
    while (p != head) {
        printf("%+dx^%d", p->coef, p->exp);
        p = p->next;
        if (p != head)
            printf(" ");
    }
    printf("\n");
}

int main(void)
{
    PROMPT("Enter the first polynomial\n");
    pnode *p1 = read_poly();
    PROMPT("Enter the second polynomial\n");
    pnode *p2 = read_poly();
    pnode *sum = poly_add(p1, p2);

    printf("P1 = ");  print_poly(p1);
    printf("P2 = ");  print_poly(p2);
    printf("SUM = "); print_poly(sum);

    free_poly(p1);
    free_poly(p2);
    free_poly(sum);
    return 0;
}
