/*
Question 9: Write a program to implement circular linked list and implement all operations
of insertion and deletion.
*/
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a circular linked list node
struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL;

// Function to check if the list is empty
int isEmpty() {
    return last == NULL;
}

// Function to insert an element at the beginning of the list
void insertAtBeginning(int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot insert element.\n");
        return;
    }
    newNode->data = element;
    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
    printf("Inserted %d at the beginning of the list.\n", element);
}

// Function to insert an element at the end of the list
void insertAtEnd(int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot insert element.\n");
        return;
    }
    newNode->data = element;
    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    printf("Inserted %d at the end of the list.\n", element);
}

// Function to delete an element from the beginning of the list
void deleteFromBeginning() {
    if (isEmpty()) {
        printf("List is empty. Cannot delete element.\n");
        return;
    }
    struct Node* temp = last->next;
    if (last->next == last) {
        last = NULL;
    } else {
        last->next = temp->next;
    }
    printf("Deleted element %d from the beginning of the list.\n", temp->data);
    free(temp);
}

// Function to delete an element from the end of the list
void deleteFromEnd() {
    if (isEmpty()) {
        printf("List is empty. Cannot delete element.\n");
        return;
    }
    struct Node* temp = last->next;
    if (last->next == last) {
        printf("Deleted element %d from the end of the list.\n", last->data);
        free(last);
        last = NULL;
    } else {
        while (temp->next != last) {
            temp = temp->next;
        }
        temp->next = last->next;
        printf("Deleted element %d from the end of the list.\n", last->data);
        free(last);
        last = temp;
    }
}

// Function to display all elements in the list
void displayList() {
    if (isEmpty()) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = last->next;
    printf("List elements are:\n");
    do {
        printf("%d--->", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("NULL\n");
}

int main() {
    int choice, element;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element at the beginning\n");
        printf("2. Insert an element at the end\n");
        printf("3. Delete an element from the beginning\n");
        printf("4. Delete an element from the end\n");
        printf("5. Display all elements in the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert at the beginning: ");
                scanf("%d", &element);
                insertAtBeginning(element);
                break;
            case 2:
                printf("Enter the element to insert at the end: ");
                scanf("%d", &element);
                insertAtEnd(element);
                break;
            case 3:
                deleteFromBeginning();
                break;
            case 4:
                deleteFromEnd();
                break;
            case 5:
                displayList();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}