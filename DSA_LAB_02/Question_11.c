/*
Question 11: Write a program to implement priority queue.
*/
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a priority queue node
struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* front = NULL;

// Function to check if the priority queue is empty
int isEmpty() {
    return front == NULL;
}

// Function to insert an element into the priority queue
void insert(int element, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot insert element.\n");
        return;
    }
    newNode->data = element;
    newNode->priority = priority;
    newNode->next = NULL;

    if (isEmpty() || front->priority > priority) {
        newNode->next = front;
        front = newNode;
    } else {
        struct Node* temp = front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d with priority %d into the priority queue.\n", element, priority);
}

// Function to delete the highest priority element from the priority queue
int delete() {
    if (isEmpty()) {
        printf("Priority queue is empty. Cannot delete element.\n");
        return -1;
    } else {
        struct Node* temp = front;
        int deletedElement = temp->data;
        front = front->next;
        free(temp);
        return deletedElement;
    }
}

// Function to display all elements in the priority queue
void displayQueue() {
    if (isEmpty()) {
        printf("Priority queue is empty.\n");
    } else {
        struct Node* temp = front;
        printf("Priority queue elements are:\n");
        while (temp != NULL) {
            printf("Element: %d, Priority: %d\n", temp->data, temp->priority);
            temp = temp->next;
        }
    }
}

int main() {
    int choice, element, priority;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element into the priority queue\n");
        printf("2. Delete the highest priority element from the priority queue\n");
        printf("3. Display all elements in the priority queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the priority of the element: ");
                scanf("%d", &priority);
                insert(element, priority);
                break;
            case 2:
                element = delete();
                if (element != -1) {
                    printf("Deleted element is %d\n", element);
                }
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}