#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef INTERACTIVE
#define PROMPT(...) printf(__VA_ARGS__)
#else
#define PROMPT(...)
#endif

typedef struct Node {
    int regNo;
    char name[50];
    struct Node* next;
} Node;

Node* createHead(void);
Node* createNode(int regNo, const char* name);
void addStudent(Node* head);
void displayList(Node* head);
void countParticipants(Node* head);
void sortList(Node* head);
void reverseList(Node* head);
void addAtPosition(Node* head);
void deleteAtPosition(Node* head);
void freeList(Node* head);

int main() {
    Node* head = createHead();
    int choice, r, c;

    while (1) {
        PROMPT("\n============================================\n");
        PROMPT("   WORKSHOP ENROLLMENT MANAGEMENT SYSTEM   \n");
        PROMPT("============================================\n");
        PROMPT("1. Add Students\n");
        PROMPT("2. Display Registered Students\n");
        PROMPT("3. Count Total Participants\n");
        PROMPT("4. Sort Student List (By Reg No)\n");
        PROMPT("5. Reverse Student List\n");
        PROMPT("6. Add a Student at Position\n");
        PROMPT("7. Delete a Student at Position\n");
        PROMPT("8. Delete All Students & Exit\n");
        PROMPT("--------------------------------------------\n");
        PROMPT("Enter your choice (1-8): ");
        r = scanf("%d", &choice);
        if (r == EOF) {
            freeList(head);
            return 0;
        }
        if (r != 1) {
            printf("Invalid input! Please enter a number.\n");
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(head);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                countParticipants(head);
                break;
            case 4:
                sortList(head);
                break;
            case 5:
                reverseList(head);
                break;
            case 6:
                addAtPosition(head);
                break;
            case 7:
                deleteAtPosition(head);
                break;
            case 8:
                freeList(head);
                printf("All student records deleted. Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 1 and 8.\n");
        }
    }

    return 0;
}

Node* createHead(void) {
    Node* head = (Node*)malloc(sizeof(Node));
    if (head == NULL) {
        return NULL;
    }
    head->regNo = 0;
    head->name[0] = '\0';
    head->next = NULL;
    return head;
}

Node* createNode(int regNo, const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->regNo = regNo;
    strncpy(newNode->name, name, 49);
    newNode->name[49] = '\0';
    newNode->next = NULL;
    return newNode;
}

void addStudent(Node* head) {
    int regNo;
    char name[50];
    int ch = 1;

    Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }

    while (ch == 1) {
        PROMPT("Enter Registration Number: ");
        if (scanf("%d", &regNo) != 1) break;
        PROMPT("Enter Student Name: ");
        scanf(" %49[^\n]", name);

        Node* newNode = createNode(regNo, name);
        if (newNode != NULL) {
            last->next = newNode;
            last = newNode;
            printf("Student added successfully.\n");
        }

        PROMPT("\n Enter 1 if you wish to add new node ");
        if (scanf("%d", &ch) != 1) ch = 0;
    }
}

void displayList(Node* head) {
    if (head == NULL || head->next == NULL) {
        printf("No students registered.\n");
        return;
    }

    printf("\n--- Registered Students ---\n");
    printf("%-15s %-30s\n", "Reg No", "Name");
    printf("--------------------------------------------\n");

    Node* curr = head->next;
    while (curr != NULL) {
        printf("%-15d %-30s\n", curr->regNo, curr->name);
        curr = curr->next;
    }
}

void countParticipants(Node* head) {
    int count = 0;
    Node* curr = (head != NULL) ? head->next : NULL;

    while (curr != NULL) {
        count++;
        curr = curr->next;
    }

    printf("Total registered students: %d\n", count);
}

void sortList(Node* head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        printf("List sorted successfully (or already contains 0 or 1 item).\n");
        return;
    }

    int swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head->next;

        while (ptr1->next != lptr) {
            if (ptr1->regNo > ptr1->next->regNo) {
                int tempReg = ptr1->regNo;
                char tempName[50];
                strcpy(tempName, ptr1->name);

                ptr1->regNo = ptr1->next->regNo;
                strcpy(ptr1->name, ptr1->next->name);

                ptr1->next->regNo = tempReg;
                strcpy(ptr1->next->name, tempName);

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    printf("Students are sorted in ascending order of Registration Number.\n");
}

void reverseList(Node* head) {
    if (head == NULL || head->next == NULL) {
        printf("No students registered to reverse.\n");
        return;
    }

    Node* prev = NULL;
    Node* curr = head->next;
    Node* nextNode = NULL;

    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    head->next = prev;
    printf("Student records reversed successfully.\n");
}

void addAtPosition(Node* head) {
    int pos, regNo;
    char name[50];

    PROMPT("Enter Position: ");
    scanf("%d", &pos);
    PROMPT("Enter Registration Number: ");
    scanf("%d", &regNo);
    PROMPT("Enter Student Name: ");
    scanf(" %49[^\n]", name);

    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    Node* prev = head;
    for (int i = 1; i < pos; i++) {
        if (prev->next == NULL) {
            printf("Invalid position!\n");
            return;
        }
        prev = prev->next;
    }

    Node* newNode = createNode(regNo, name);
    if (newNode == NULL) return;

    newNode->next = prev->next;
    prev->next = newNode;

    printf("Student added successfully.\n");
}

void deleteAtPosition(Node* head) {
    if (head == NULL || head->next == NULL) {
        printf("List is empty. No students to remove.\n");
        return;
    }

    int pos;
    PROMPT("Enter Position to delete: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    Node* prev = head;
    for (int i = 1; i < pos; i++) {
        if (prev->next == NULL) {
            printf("Invalid position!\n");
            return;
        }
        prev = prev->next;
    }

    if (prev->next == NULL) {
        printf("Invalid position!\n");
        return;
    }

    Node* toDelete = prev->next;
    prev->next = toDelete->next;
    free(toDelete);

    printf("Student record deleted successfully.\n");
}

void freeList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        Node* nextNode = curr->next;
        free(curr);
        curr = nextNode;
    }
}
