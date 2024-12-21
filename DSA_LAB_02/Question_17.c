/*
Question 17: Write a program to implement insertion sort for sorting a list of N names
*/
#include <stdio.h>
#include <string.h>

// Function to perform insertion sort on an array of strings
void insertionSort(char arr[][100], int n) {
    int i, j;
    char key[100];
    for (i = 1; i < n; i++) {
        strcpy(key, arr[i]);
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && strcmp(arr[j], key) > 0) {
            strcpy(arr[j + 1], arr[j]);
            j = j - 1;
        }
        strcpy(arr[j + 1], key);
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

    insertionSort(arr, n);

    printf("Sorted list of names:\n");
    printArray(arr, n);

    return 0;
}