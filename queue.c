#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int isFull(int rear) {
    return rear == MAX - 1;
}
int isEmpty(int front) {
    return front == -1;
}
void insert(int queue[], int *front, int *rear, int value) {
    if (isFull(*rear)) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (*rear == -1) {
        *front = 0; 
    }
    queue[++(*rear)] = value;
    printf("Inserted %d into the queue\n", value);
}
int delete(int queue[], int front, int rear) {
    if (isEmpty(front)) {
        printf("Queue Underflow! Cannot delete from an empty queue\n");
        return -1;
    }
    int item = queue[front];
    if (front == rear) {
        front = -1; 
        rear = -1;
    } else {
        front++;
    }
    printf("Deleted %d from the queue\n", item);
    return item;
}
void display(int queue[], int front, int rear) {
    if (isEmpty(front)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int main() {
    int queue[MAX];
    int front = -1, rear = -1;
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &value);
                insert(queue, &front, &rear, value);
                break;
            case 2:
                delete(queue, front, rear);
                if (front > rear) { -
                    front = -1;
                    rear = -1;
                }
                break;
            case 3:
                display(queue, front, rear);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
