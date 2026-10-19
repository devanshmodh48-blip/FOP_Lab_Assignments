/*
 * Assignment: Polynomial Addition using a Circular Singly Linked List
 *
 * Complete every function marked TODO. Do NOT change main(), print_poly()
 * or the input/output format - your program is graded automatically.
 *
 * INPUT (no prompts are printed):
 *   n1                 number of terms in polynomial 1
 *   coef exp           n1 lines, terms in ANY order, exponents >= 0
 *   n2                 number of terms in polynomial 2
 *   coef exp           n2 lines
 *
 * OUTPUT (exactly three lines):
 *   P1 = <poly>
 *   P2 = <poly>
 *   SUM = <poly>
 *
 * <poly> lists terms in DESCENDING order of exponent as "%+dx^%d" separated
 * by one space, e.g. "+3x^2 -5x^0". A polynomial with no terms prints "0".
 *
 * Rules:
 *   - Terms with the same exponent (even inside one polynomial) are combined.
 *   - Terms whose coefficient becomes 0 must be removed.
 *   - The list is circular with a header node; head->next == head when empty.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coef;
    int exp;
    struct node *next;
} pnode;

/* Create an empty circular list (header node only) and return the header. */
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

/* Insert a term keeping the list in descending exponent order.
 * Combine with an existing term of the same exponent; remove it if the
 * resulting coefficient is 0. Ignore terms whose coefficient is 0. */
void insert_term(pnode *head, int coef, int exp)
{
    if (head == NULL || coef == 0) {
        return;
    }

    pnode *prev = head;
    pnode *curr = head->next;

    /* Traverse while current term exponent is greater than the new exponent */
    while (curr != head && curr->exp > exp) {
        prev = curr;
        curr = curr->next;
    }

    /* Combine terms if the exponent already exists */
    if (curr != head && curr->exp == exp) {
        curr->coef += coef;
        /* Remove node if resulting coefficient drops to 0 */
        if (curr->coef == 0) {
            prev->next = curr->next;
            free(curr);
        }
        return;
    }

    /* Insert new node between prev and curr to maintain descending order */
    pnode *new_node = (pnode *)malloc(sizeof(pnode));
    if (new_node == NULL) {
        return;
    }
    new_node->coef = coef;
    new_node->exp = exp;
    new_node->next = curr;
    prev->next = new_node;
}

/* Read one polynomial from stdin in the format described above. */
pnode *read_poly(void)
{
    pnode *head = new_poly();
    if (head == NULL) {
        return NULL;
    }

    int n;
    if (scanf("%d", &n) != 1) {
        return head;
    }

    for (int i = 0; i < n; i++) {
        int coef, exp;
        if (scanf("%d %d", &coef, &exp) == 2) {
            insert_term(head, coef, exp);
        }
    }

    return head;
}

/* Return a NEW polynomial equal to h1 + h2. Do not modify h1 or h2. */
pnode *poly_add(pnode *h1, pnode *h2)
{
    pnode *sum = new_poly();
    if (sum == NULL) {
        return NULL;
    }

    /* Insert all terms of h1 into sum */
    if (h1 != NULL) {
        pnode *p = h1->next;
        while (p != h1) {
            insert_term(sum, p->coef, p->exp);
            p = p->next;
        }
    }

    /* Insert and combine all terms of h2 into sum */
    if (h2 != NULL) {
        pnode *q = h2->next;
        while (q != h2) {
            insert_term(sum, q->coef, q->exp);
            q = q->next;
        }
