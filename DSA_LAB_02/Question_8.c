/*
Question 8: Write a program to implement simple queue using linked list. Use menu to
implement all the operations given in above list.
*/
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a queue node
struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Function to check if the queue is empty
int isEmpty() {
    return front == NULL;
}

// Function to insert an element into the queue
void insert(int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot insert element.\n");
        return;
    }
    newNode->data = element;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Inserted %d into the queue.\n", element);
}

// Function to delete an element from the queue
int delete() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot delete element.\n");
        return -1;
    } else {
        struct Node* temp = front;
        int deletedElement = temp->data;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        free(temp);
        return deletedElement;
    }
}

// Function to display the element at the last in the queue
void displayLast() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Last element in the queue is %d\n", rear->data);
    }
}

// Function to display all elements in the queue
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        struct Node* temp = front;
        printf("Queue elements are:\n");
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int choice, element;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Check if queue is empty\n");
        printf("2. Display all elements in the queue\n");
        printf("3. Display the element at the last in the queue\n");
        printf("4. Insert an element into the queue\n");
        printf("5. Delete an element from the queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 2:
                displayQueue();
                break;
            case 3:
                displayLast();
                break;
            case 4:
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
            case 5:
                element = delete();
                if (element != -1) {
                    printf("Deleted element is %d\n", element);
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}