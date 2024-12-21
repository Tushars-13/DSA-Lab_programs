/*
Ques_3 .Write a program in C to implement stack using linked list. Perform all
operations mentioned in Question_2.
*/
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Function to check if the stack is full (always returns false for linked list implementation)
int isFull() {
    printf("\nA linked list stack is never full unless memory is exhausted\n");
}

// Function to check if the stack is empty
int isEmpty() {
    return top == NULL;
}

// Function to push an element onto the stack
void push(int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot push element.\n");
        return;
    }
    newNode->data = element;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d onto the stack.\n", element);
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot pop element.\n");
        return -1;
    } else {
        struct Node* temp = top;
        int poppedElement = temp->data;
        top = top->next;
        free(temp);
        return poppedElement;
    }
}

// Function to display the top element of the stack
void displayTop() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is %d\n", top->data);
    }
}

// Function to display all elements in the stack
void displayStack() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        struct Node* temp = top;
        printf("Stack elements are:\n");
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
        printf("1. Check if stack is full\n");
        printf("2. Check if stack is empty\n");
        printf("3. Display all elements in the stack\n");
        printf("4. Display the top element of the stack\n");
        printf("5. Push an element onto the stack\n");
        printf("6. Pop an element from the stack\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                isFull();
                break;
            case 2:
                if (isEmpty()) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
            case 3:
                displayStack();
                break;
            case 4:
                displayTop();
                break;
            case 5:
                printf("Enter the element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 6:
                element = pop();
                if (element != -1) {
                    printf("Popped element is %d\n", element);
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