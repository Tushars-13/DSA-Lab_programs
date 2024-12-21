/*
Question 13: Write a program to implement bubble sort for sorting a list of N names.
*/
#include <stdio.h>
#include <string.h>

// Function to perform bubble sort on an array of strings
void bubbleSort(char arr[][100], int n) {
    int i, j;
    char temp[100];
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (strcmp(arr[j], arr[j+1]) > 0) {
                // Swap arr[j] and arr[j+1]
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
            }
        }
    }
}

// Function to print an array of strings
void printArray(char arr[][100], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%s\n", arr[i]);
    }
}

int main() {
    int n, i;
    printf("Enter the number of names: ");
    scanf("%d", &n);
    char arr[n][100];
    printf("Enter the names:\n");
    for (i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    printf("Unsorted list of names:\n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted list of names:\n");
    printArray(arr, n);

    return 0;
}