/*
Question 10: Write a program to implement double ended queue.
*/
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a deque node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Function to check if the deque is empty
int isEmpty() {
    return front == NULL;
}

// Function to insert an element at the front of the deque
void insertFront(int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot insert element.\n");
        return;
    }
    newNode->data = element;
    newNode->prev = NULL;
    newNode->next = front;
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        front->prev = newNode;
        front = newNode;
    }
    printf("Inserted %d at the front of the deque.\n", element);
}

// Function to insert an element at the rear of the deque
void insertRear(int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot insert element.\n");
        return;
    }
    newNode->data = element;
    newNode->next = NULL;
    newNode->prev = rear;
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Inserted %d at the rear of the deque.\n", element);
}

// Function to delete an element from the front of the deque
void deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete element.\n");
        return;
    }
    struct Node* temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    } else {
        front->prev = NULL;
    }
    printf("Deleted element %d from the front of the deque.\n", temp->data);
    free(temp);
}

// Function to delete an element from the rear of the deque
void deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete element.\n");
        return;
    }
    struct Node* temp = rear;
    rear = rear->prev;
    if (rear == NULL) {
        front = NULL;
    } else {
        rear->next = NULL;
    }
    printf("Deleted element %d from the rear of the deque.\n", temp->data);
    free(temp);
}

// Function to display all elements in the deque
void displayDeque() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("Deque elements are:\n");
    while (temp != NULL) {
        printf("%d--->", temp->data);
        temp = temp->next;
    }printf("NULL\n");
}

int main() {
    int choice, element;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element at the front\n");
        printf("2. Insert an element at the rear\n");
        printf("3. Delete an element from the front\n");
        printf("4. Delete an element from the rear\n");
        printf("5. Display all elements in the deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert at the front: ");
                scanf("%d", &element);
                insertFront(element);
                break;
            case 2:
                printf("Enter the element to insert at the rear: ");
                scanf("%d", &element);
                insertRear(element);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                displayDeque();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}