/* Ques_2. Write a program in C to implement stack using arrays. Use menu to call all its
functions: (i) to check whether stack is full (ii) to check whether stack is empty
(iii) display all elements present on the stack (iv) to display the element
present on the top of stack (v). push an element (vi) pop an element (vii) exit */

#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

// Function to check if the stack is full
int isFull() {
    return top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Function to push an element onto the stack
void push(int element) {
    if (isFull()) {
        printf("Stack is full. Cannot push element.\n");
    } else {
        stack[++top] = element;
        printf("Pushed %d onto the stack.\n", element);
    }
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot pop element.\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Function to display the top element of the stack
void displayTop() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is %d\n", stack[top]);
    }
}

// Function to display all elements in the stack
void displayStack() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
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
                if (isFull()) {
                    printf("Stack is full.\n");
                } else {
                    printf("Stack is not full.\n");
                }
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
                while(1){
                printf("Enter the element to push: ");
                scanf("%d", &element);
                push(element);
                printf("Do you want to push more elements? (1/0): ");
                scanf("%d", &choice);
                if(choice==0){
                    break;
                }
                }
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