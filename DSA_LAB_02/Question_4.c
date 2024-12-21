/*
Ques_4. Write a program to convert an infix expression to postfix using stack.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // For isalnum function

#define MAX 100

char stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(char element) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = element;
    }
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Function to return the precedence of operators
int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to check if the character is an operator
int isOperator(char symbol) {
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^';
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char symbol, temp;

    while (infix[i] != '\0') {
        symbol = infix[i];

        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        } else if (symbol == '(') {
            push(symbol);
        } else if (symbol == ')') {
            while ((temp = pop()) != '(') {
                postfix[j++] = temp;
            }
        } else if (isOperator(symbol)) {
            while (top != -1 && precedence(stack[top]) >= precedence(symbol)) {
                postfix[j++] = pop();
            }
            push(symbol);
        }
        i++;
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("----------------------------\n");
    printf("Infix to Postfix Conversion\n");
    printf("\nEnter an infix expression: ");
    gets(infix);

    infixToPostfix(infix, postfix);

    printf("\nPostfix expression: %s\n", postfix);
    printf("----------------------------\n");

    return 0;
}