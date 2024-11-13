#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

int deleteStack(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    struct Node* temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

int peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    return top->data;
}

int isStackEmpty(struct Node* top) {
    return top == NULL;
}

void displayStack(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = createNode(data);
    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}

int deleteQueue(struct Node** front) {
    if (*front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    struct Node* temp = *front;
    int data = temp->data;
    *front = (*front)->next;
    free(temp);
    return data;
}

int front(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    return front->data;
}

int isQueueEmpty(struct Node* front) {
    return front == NULL;
}

void displayQueue(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* stackTop = NULL;
    struct Node* queueFront = NULL;
    struct Node* queueRear = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Stack Operations\n");
        printf("2. Queue Operations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                while (1) {
                    printf("\nStack Operations:\n");
                    printf("1. Push\n2. Delete (Pop)\n3. Peek\n4. Display Stack\n5. Check if Stack is Empty\n6. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Enter value to push: ");
                            scanf("%d", &value);
                            push(&stackTop, value);
                            break;
                        case 2:
                            value = deleteStack(&stackTop);
                            if (value != -1) {
                                printf("Deleted (popped) value: %d\n", value);
                            }
                            break;
                        case 3:
                            value = peek(stackTop);
                            if (value != -1) {
                                printf("Top value: %d\n", value);
                            }
                            break;
                        case 4:
                            printf("Stack: ");
                            displayStack(stackTop);
                            break;
                        case 5:
                            if (isStackEmpty(stackTop)) {
                                printf("Stack is empty.\n");
                            } else {
                                printf("Stack is not empty.\n");
                            }
                            break;
                        case 6:
                            break;
                        default:
                            printf("Invalid choice. Try again.\n");
                    }
                    if (choice == 6) break;
                }
                break;

            case 2:
                while (1) {
                    printf("\nQueue Operations:\n");
                    printf("1. Enqueue\n2. Delete (Dequeue)\n3. Front\n4. Display Queue\n5. Check if Queue is Empty\n6. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Enter value to enqueue: ");
                            scanf("%d", &value);
                            enqueue(&queueFront, &queueRear, value);
                            break;
                        case 2:
                            value = deleteQueue(&queueFront);
                            if (value != -1) {
                                printf("Deleted (dequeued) value: %d\n", value);
                            }
                            break;
                        case 3:
                            value = front(queueFront);
                            if (value != -1) {
                                printf("Front value: %d\n", value);
                            }
                            break;
                        case 4:
                            printf("Queue: ");
                            displayQueue(queueFront);
                            break;
                        case 5:
                            if (isQueueEmpty(queueFront)) {
                                printf("Queue is empty.\n");
                            } else {
                                printf("Queue is not empty.\n");
                            }
                            break;
                        case 6:
                            break;
                        default:
                            printf("Invalid choice. Try again.\n");
                    }
                    if (choice == 6) break; 
                }
                break;

            case 3:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
