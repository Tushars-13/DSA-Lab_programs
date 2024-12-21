/*
Question 21: Write a program to implement Binary search to search a name in a list of N names.
*/
#include <stdio.h>
#include <string.h>

// Function to perform binary search on a sorted array of strings
int binarySearch(char arr[][100], int left, int right, char* x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        int res = strcmp(arr[mid], x);

        // Check if x is present at mid
        if (res == 0) {
            return mid;
        }

        // If x is greater, ignore the left half
        if (res < 0) {
            left = mid + 1;
        }
        // If x is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    // Return -1 if the element is not found
    return -1;
}

// Function to print an array of strings
void printArray(char arr[][100], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\n", arr[i]);
    }
}

int main() {
    int n, i;
    char x[100];
    printf("Enter the number of names: ");
    scanf("%d", &n);
    char arr[n][100];
    printf("Enter the names (sorted in ascending order):\n");
    for (i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    printf("Enter the name to search: ");
    scanf("%s", x);

    int result = binarySearch(arr, 0, n - 1, x);
    if (result != -1) {
        printf("Name %s found at index %d\n", x, result);
    } else {
        printf("Name %s not found in the list\n", x);
    }

    return 0;
}