/*
Question 19: Write a program to implement Linear search to search a name in a list of N names.
*/
#include <stdio.h>
#include <string.h>

// Function to perform linear search on an array of strings
int linearSearch(char arr[][100], int n, char* x) {
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i], x) == 0) {
            return i; // Return the index of the element if found
        }
    }
    return -1; // Return -1 if the element is not found
}

int main() {
    int n, i;
    char x[100];
    printf("Enter the number of names: ");
    scanf("%d", &n);
    char arr[n][100];
    printf("Enter the names:\n");
    for (i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    printf("Enter the name to search: ");
    scanf("%s", x);

    int result = linearSearch(arr, n, x);
    if (result != -1) {
        printf("Name %s found at index %d\n", x, result);
    } else {
        printf("Name %s not found in the list\n", x);
    }

    return 0;
}