#include <stdio.h>

struct student {
    int rollno;
    char name[20];
    float perc;
    int div;
};

void display(struct student s[20], int size);
void input(struct student s[20], int size);
void insertionSort(struct student s[20], int size);
void selectionSort(struct student s[20], int size);
int linear(struct student s[20], int size, int key);
int binary(struct student s[20], int size, int key);

int main() {
    struct student s[20];
    int c, key, loc;
    int size;
    
    printf("Enter the number of students: ");
    scanf("%d", &size);

    input(s, size);

    do {
        printf("\n--- MENU ---\n");
        printf("1. Display Students\n");
        printf("2. Insertion Sort by Roll Number\n");
        printf("3. Selection Sort by Roll Number\n");
        printf("4. Linear Search by Roll Number\n");
        printf("5. Binary Search by Roll Number\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                display(s, size);
                break;
            case 2:
                insertionSort(s, size);
                printf("Students sorted using Insertion Sort.\n");
                display(s, size);
                break;
            case 3:
                selectionSort(s, size);
                printf("Students sorted using Selection Sort.\n");
                display(s, size);
                break;
            case 4:
                printf("Enter roll number to search (Linear Search): ");
                scanf("%d", &key);
                loc = linear(s, size, key);
                if (loc != -1)
                    printf("Student found at index %d (Roll No: %d, Name: %s)\n", loc, s[loc].rollno, s[loc].name);
                else
                    printf("Student not found.\n");
                break;
            case 5:
                printf("Enter roll number to search (Binary Search - ensure list is sorted first): ");
                scanf("%d", &key);
                loc = binary(s, size, key);
                if (loc != -1)
                    printf("Student found at index %d (Roll No: %d, Name: %s)\n", loc, s[loc].rollno, s[loc].name);
                else
                    printf("Student not found.\n");
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (c != 6);

    return 0;
}

void input(struct student s[20], int size) {
    for (int i = 0; i < size; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &s[i].rollno);
        
        printf("Name: ");
        scanf(" %[^\n]", s[i].name);
        
        printf("Percentage: ");
        scanf("%f", &s[i].perc);
        printf("Division: ");
        scanf("%d", &s[i].div);
    }
}

void display(struct student s[20], int size) {
    printf("\n--- Student Records ---\n");
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d | Name: %s | Percentage: %.2f%% | Division: %d\n", 
               s[i].rollno, s[i].name, s[i].perc, s[i].div);
    }
}

void insertionSort(struct student s[20], int size) {
    for (int i = 1; i < size; i++) {
        struct student key = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].rollno > key.rollno) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}

void selectionSort(struct student s[20], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (s[j].rollno < s[minIdx].rollno) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            struct student temp = s[i];
            s[i] = s[minIdx];
            s[minIdx] = temp;
        }
    }
}

int linear(struct student s[20], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (s[i].rollno == key) {
            return i;
        }
    }
    return -1;
}

int binary(struct student s[20], int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2; 
        if (s[mid].rollno == key)
            return mid;
        if (s[mid].rollno < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

  
