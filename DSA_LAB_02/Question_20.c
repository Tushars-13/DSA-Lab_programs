/*
Question 20: Write a program to implement Binary search to search a number in a list of N numbers
*/
#include <stdio.h>

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if x is present at mid
        if (arr[mid] == x) {
            return mid;
        }

        // If x is greater, ignore the left half
        if (arr[mid] < x) {
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

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, x, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array (sorted in ascending order):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &x);

    int result = binarySearch(arr, 0, n - 1, x);
    if (result != -1) {
        printf("Element %d found at index %d\n", x, result);
    } else {
        printf("Element %d not found in the array\n", x);
    }

    return 0;
}