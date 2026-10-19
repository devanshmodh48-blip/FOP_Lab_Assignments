#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Node structure for student registration */
struct node {
    int regNo;
    char name[50];
    struct node *next;
};

/* Global head pointer (points to dummy header node) */
struct node *head = NULL;

/* Function to create the dummy header node */
void createHead() {
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL) {
        printf("\nMemory allocation failed for header node!\n");
        exit(1);
    }
    head->regNo = -1;
    strcpy(head->name, "HEADER");
    head->next = NULL;
}

/* Function to count total registered participants */
int countParticipants() {
    int count = 0;
    struct node *curr = head->next;

    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

/* Helper to allocate and populate a new student node */
struct node *createStudentNode() {
    struct node *curr = (struct node *)malloc(sizeof(struct node));
    if (curr == NULL) {
        printf("\nMemory allocation failed!\n");
        return NULL;
    }

    printf("Enter Registration Number: ");
    scanf("%d", &curr->regNo);
    printf("Enter Student Name: ");
    scanf("%s", curr->name);
    curr->next = NULL;

    return curr;
}

/* Function 1: Add a student at the end */
void addStudentEnd() {
    struct node *curr = createStudentNode();
    if (curr == NULL) return;

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = curr;

    printf("Student registered successfully at the end.\n");
}

/* Function 2: Add a student at a specific position (1-based index) */
void addStudentAtPosition() {
    int pos, k;
    int total = countParticipants();

    printf("Enter position to insert (1 to %d): ", total + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > total + 1) {
        printf("Invalid position! Current total participants: %d\n", total);
        return;
    }

    struct node *curr = createStudentNode();
    if (curr == NULL) return;

    struct node *temp = head;
    for (k = 1; k < pos; k++) {
        temp = temp->next;
    }

    curr->next = temp->next;
    temp->next = curr;

    printf("Student registered successfully at position %d.\n", pos);
}

/* Function 3: Delete a student at a specific position (1-based index) */
void deleteStudentAtPosition() {
    int pos, k;
    int total = countParticipants();

    if (head->next == NULL) {
        printf("\nNo students registered.\n");
        return;
    }

    printf("Enter position to delete (1 to %d): ", total);
    scanf("%d", &pos);

    if (pos < 1 || pos > total) {
        printf("Invalid position! Current total participants: %d\n", total);
        return;
    }

    struct node *prev = head;
    for (k = 1; k < pos; k++) {
        prev = prev->next;
    }

    struct node *curr = prev->next;
    prev->next = curr->next;
    free(curr);

    printf("Student record at position %d deleted successfully.\n", pos);
}

/* Function 4: Display the list */
void display() {
    struct node *curr;

    if (head->next == NULL) {
        printf("\nNo students registered.\n");
        return;
    }

    curr = head->next;
    printf("\n--- Registered Students ---\n");
    printf("%-15s %-20s\n", "Reg No", "Name");
    printf("-------------------------------\n");

    while (curr != NULL) {
        printf("%-15d %-20s\n", curr->regNo, curr->name);
        curr = curr->next;
    }
    printf("-------------------------------\n");
}

/* Function 6: Sort list in ascending order of RegNo */
void sortList() {
    struct node *i, *j;
    int tempReg;
    char tempName[50];

    if (head->next == NULL || head->next->next == NULL) {
        printf("\nList has fewer than 2 students; already sorted.\n");
        return;
    }

    for (i = head->next; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->regNo > j->regNo) {
                /* Swap RegNo */
                tempReg = i->regNo;
                i->regNo = j->regNo;
                j->regNo = tempReg;

                /* Swap Name */
                strcpy(tempName, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, tempName);
            }
        }
    }
    printf("List sorted by Registration Number successfully.\n");
}

/* Function 7: Reverse the list using 3 pointers */
void reverseList() {
    struct node *prev = NULL;
    struct node *curr = head->next;
    struct node *future = NULL;

    if (head->next == NULL || head->next->next == NULL) {
        printf("\nList has fewer than 2 students; nothing to reverse.\n");
        return;
    }

    while (curr != NULL) {
        future = curr->next;
        curr->next = prev;
        prev = curr;
        curr = future;
    }
    head->next = prev;
    printf("Linked list reversed successfully.\n");
}

int main() {
    int choice;

    createHead();

    while (1) {
        printf("\n=== WORKSHOP ENROLLMENT MANAGEMENT SYSTEM ===");
        printf("\n1. Add Student at End");
        printf("\n2. Add Student at Position");
        printf("\n3. Delete Student at Position");
        printf("\n4. Display List");
        printf("\n5. Count Total Participants");
        printf("\n6. Sort List by RegNo");
        printf("\n7. Reverse List");
        printf("\n8. Exit");
        printf("\nEnter choice (1-8): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudentEnd();
                break;
            case 2:
                addStudentAtPosition();
                break;
            case 3:
                deleteStudentAtPosition();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nTotal Participants: %d\n", countParticipants());
                break;
            case 6:
                sortList();
                display();
                break;
            case 7:
                reverseList();
                display();
                break;
            case 8:
                printf("\nExiting program...\n");
                return 0;
            default:
                printf("\nInvalid choice! Please choose between 1 and 8.\n");
        }
    }

    return 0;
}
