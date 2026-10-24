#include <stdio.h>

#define MAX 5


struct queue {
    int jobid;
    char title[10];
};

int front = -1, rear = -1;


int isempty(){
    if(front == rear){
        printf("\n There is no job in the queue to print.");
        return 1;
    }
    else
        return 0;
}


int isfull(){
    if(rear == MAX - 1){
        printf("\n The queue is full.");
        return 1;
    }
    else
        return 0;
}


void enqueue(struct queue q[5]){
    if(!isfull()){
        rear++;
        printf("\n Enter the job id and job title ");
        scanf("%d%s", &q[rear].jobid, q[rear].title);
    }
}


int dequeue(struct queue q[MAX]){
    if(!isempty()){
        front++;
        return q[front].jobid;
    }
    return -1;
}


void display(struct queue q[MAX]){
    if(front == rear){
        printf("\n Queue is empty. No jobs to display.");
        return;
    }
    
    printf("\n Current Jobs in Queue ");
    printf("\n%-10s %-10s", "Job ID", "Title");
    for(int i = front + 1; i <= rear; i++){
        printf("\n%-10d %-10s", q[i].jobid, q[i].title);
    }
}

int main(){
    struct queue q[MAX];
    int choice;
    int j_id;

    while(1){
        printf("\n\n--- Job Queue Menu ---");
        printf("\n1. Enqueue (Add Job)");
        printf("\n2. Dequeue (Process Job)");
        printf("\n3. Display Queue");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                enqueue(q);
                break;
            case 2:
                j_id = dequeue(q);
                if(j_id != -1){
                    printf("\n The job id %d is processed.", j_id);
                }
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("\nExiting program.\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.");
        }
    }
    return 0;
}
