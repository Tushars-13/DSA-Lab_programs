/*
Question_5. Write a program to evaluate a postfix expression using stack.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // For isdigit function

#define MAX 100

int stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(int element) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = element;
    }
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* postfix) {
    int i = 0;
    char symbol;
    int operand1, operand2, result;

    while (postfix[i] != '\0') {
        symbol = postfix[i];

        if (isdigit(symbol)) {
            // Convert character to integer and push onto stack
            push(symbol - '0');
        } else {
            // Pop two operands from stack
            operand2 = pop();
            operand1 = pop();

            // Perform the operation and push the result back onto the stack
            switch (symbol) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator encountered: %c\n", symbol);
                    exit(1);
            }
            push(result);
        }
        i++;
    }

    // The final result will be the only element left in the stack
    return pop();
}

int main() {
    char postfix[MAX];
    printf("\n=========================================\n");
    printf("\nEvaluate a postfix expression using stack\n");
    printf("\n=========================================\n");
    printf("Enter a postfix expression: ");
    gets(postfix);

    int result = evaluatePostfix(postfix);

    printf("\nThe result of the postfix expression is: %d\n", result);
    printf("\n=========================================\n");
    return 0;
}