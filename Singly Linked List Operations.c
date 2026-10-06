#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Node structure for student registration */
struct node {
    int regNo;
    char name[50];
    struct node *next;
};

/* Global head pointer */
struct node *head = NULL;

/* Function to add a student at the end (Slide 26 style) */
void addStudent() {
    struct node *curr, *temp;

    curr = (struct node *)malloc(sizeof(struct node));
    if (curr == NULL) {
        printf("\nMemory allocation failed!\n");
        return;
    }

    printf("Enter Registration Number: ");
    scanf("%d", &curr->regNo);
    printf("Enter Student Name: ");
    scanf("%s", curr->name);
    curr->next = NULL;

    /* If list is empty */
    if (head == NULL) {
        head = curr;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = curr;
    }
    printf("Student registered successfully.\n");
}

/* Function to display the list (Slide 27 style) */
void display() {
    struct node *curr;

    if (head == NULL) {
        printf("\nNo students registered.\n");
        return;
    }

    curr = head;
    printf("\n--- Registered Students ---\n");
    printf("%-15s %-20s\n", "Reg No", "Name");
    printf("-------------------------------\n");

    while (curr != NULL) {
        printf("%-15d %-20s\n", curr->regNo, curr->name);
        curr = curr->next;
    }
    printf("-------------------------------\n");
}

/* Function to count total registered participants (Slide 27 len algorithm) */
int countParticipants() {
    int count = 0;
    struct node *curr = head;

    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

/* Function to remove a student by RegNo (Slide 31 del algorithm) */
void removeStudent() {
    int reg;
    struct node *curr, *prev;

    if (head == NULL) {
        printf("\nNo students registered.\n");
        return;
    }

    printf("Enter Registration Number to remove: ");
    scanf("%d", &reg);

    /* Case 1: First node needs to be deleted */
    if (head->regNo == reg) {
        curr = head;
        head = head->next;
        free(curr);
        printf("Student record deleted successfully.\n");
        return;
    }

    /* Case 2: Node is in between or at the end */
    prev = head;
    curr = head->next;

    while (curr != NULL && curr->regNo != reg) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Student not found.\n");
    } else {
        prev->next = curr->next;
        free(curr);
        printf("Student record deleted successfully.\n");
    }
}

/* Function to reverse the list using 3 pointers (Slide 32 reverse algorithm) */
void reverseList() {
    struct node *prev = NULL;
    struct node *curr = head;
    struct node *future = NULL;

    if (head == NULL) {
        printf("\nNo students registered.\n");
        return;
    }

    while (curr != NULL) {
        future = curr->next;
        curr->next = prev;
        prev = curr;
        curr = future;
    }
    head = prev;
    printf("Linked list reversed successfully.\n");
}

/* Function to sort list in ascending order of RegNo (Bubble sort on data) */
void sortList() {
    struct node *i, *j;
    int tempReg;
    char tempName[50];

    if (head == NULL) {
        printf("\nNo students registered.\n");
        return;
    }

    for (i = head; i->next != NULL; i = i->next) {
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

int main() {
    int choice;

    while (1) {
        printf("\n=== WORKSHOP ENROLLMENT SYSTEM ===");
        printf("\n1. Add Student");
        printf("\n2. Remove Student");
        printf("\n3. Display List");
        printf("\n4. Count Total Participants");
        printf("\n5. Sort List");
        printf("\n6. Reverse List");
        printf("\n0. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                removeStudent();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nTotal Participants: %d\n", countParticipants());
                break;
            case 5:
                sortList();
                display();
                break;
            case 6:
                reverseList();
                display();
                break;
            case 0:
                printf("\nExiting program...\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
