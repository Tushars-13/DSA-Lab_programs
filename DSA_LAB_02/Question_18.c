/*
Question 18: Write a program to implement Linear search to search a number in a list of N numbers.
*/
#include <stdio.h>

// Function to perform linear search on an array
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Return the index of the element if found
        }
    }
    return -1; // Return -1 if the element is not found
}

int main() {
    int n, x, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &x);

    int result = linearSearch(arr, n, x);
    if (result != -1) {
        printf("Element %d found at index %d\n", x, result);
    } else {
        printf("Element %d not found in the array\n", x);
    }

    return 0;
}