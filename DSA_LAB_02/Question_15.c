/*
Question 15: Write a program to implement selection sort for sorting a list of N names
*/
#include <stdio.h>
#include <string.h>

// Function to perform selection sort on an array of strings
void selectionSort(char arr[][100], int n) {
    int i, j, minIndex;
    char temp[100];
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in the unsorted part of the array
        minIndex = i;
        for (j = i+1; j < n; j++) {
            if (strcmp(arr[j], arr[minIndex]) < 0) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        strcpy(temp, arr[minIndex]);
        strcpy(arr[minIndex], arr[i]);
        strcpy(arr[i], temp);
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

    selectionSort(arr, n);

    printf("Sorted list of names:\n");
    printArray(arr, n);

    return 0;
}