/*
Question_7. Write a program to implement simple queue using arrays. Use menu (i) to
check whether queue is full (ii) to check whether queue is empty (iii) display
all elements present in the queue (iv) to display the element present at last in
the queue (v). insert an element (vi) delete an element (vii) exit
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

// Function to check if the queue is full
int isFull() {
    return rear == MAX - 1;
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Function to insert an element into the queue
void insert(int element) {
    if (isFull()) {
        printf("Queue is full. Cannot insert element.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = element;
        printf("Inserted %d into the queue.\n", element);
    }
}

// Function to delete an element from the queue
int delete() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot delete element.\n");
        return -1;
    } else {
        return queue[front++];
    }
}

// Function to display the element at the last in the queue
void displayLast() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Last element in the queue is %d\n", queue[rear]);
    }
}

// Function to display all elements in the queue
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}

int main() {
    int choice, element;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Check if queue is full\n");
        printf("2. Check if queue is empty\n");
        printf("3. Display all elements in the queue\n");
        printf("4. Display the element at the last in the queue\n");
        printf("5. Insert an element into the queue\n");
        printf("6. Delete an element from the queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull()) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 2:
                if (isEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                displayLast();
                break;
            case 5:
                while (1) {
                    printf("Enter the element to insert: ");
                    scanf("%d", &element);
                    insert(element);
                    printf("\nDo you want to insert another element? (1/0): ");
                    scanf("%d", &choice);
                    if (choice == 0) {
                        break;
                    }
                }
                printf("\nInserted all elements into the queue.\n");
                break;
            case 6:
                element = delete();
                if (element != -1) {
                    printf("Deleted element is %d\n", element);
                }
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}