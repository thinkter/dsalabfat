/*
 * Linear Search Algorithm
 * 
 * Pseudocode:
 * 1. Start from the leftmost element of array
 * 2. For each element in the array:
 *    a. Compare the current element with the target element
 *    b. If current element equals target, return its index
 * 3. If target element is not found after checking all elements, return -1
 * 
 * Time Complexity: O(n) - worst case when element is at the end or not present
 * Space Complexity: O(1)
 * 
 * Note: Linear search works on both sorted and unsorted arrays
 */

#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int target) {
    // Traverse through all array elements
    for (int i = 0; i < n; i++) {
        // If element is found, return its index
        if (arr[i] == target) {
            return i;
        }
    }
    
    // Element not found in array
    return -1;
}

// Function to search for all occurrences of an element
void linearSearchAll(int arr[], int n, int target) {
    int found = 0;
    
    printf("Searching for all occurrences of %d: ", target);
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            printf("Index %d ", i);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Not found");
    }
    printf("\n");
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver program to test linear search
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 22, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Linear Search Algorithm\n");
    printf("=======================\n\n");
    
    printf("Array: ");
    printArray(arr, n);
    
    // Test case 1: Element present in array
    printf("\nTest Case 1:\n");
    int target1 = 22;
    int result1 = linearSearch(arr, n, target1);
    if (result1 != -1) {
        printf("Element %d found at index %d\n", target1, result1);
    } else {
        printf("Element %d not found in array\n", target1);
    }
    
    // Test case 2: Element not present in array
    printf("\nTest Case 2:\n");
    int target2 = 100;
    int result2 = linearSearch(arr, n, target2);
    if (result2 != -1) {
        printf("Element %d found at index %d\n", target2, result2);
    } else {
        printf("Element %d not found in array\n", target2);
    }
    
    // Test case 3: First element
    printf("\nTest Case 3:\n");
    int target3 = 64;
    int result3 = linearSearch(arr, n, target3);
    if (result3 != -1) {
        printf("Element %d found at index %d\n", target3, result3);
    } else {
        printf("Element %d not found in array\n", target3);
    }
    
    // Test case 4: Last element
    printf("\nTest Case 4:\n");
    int target4 = 50;
    int result4 = linearSearch(arr, n, target4);
    if (result4 != -1) {
        printf("Element %d found at index %d\n", target4, result4);
    } else {
        printf("Element %d not found in array\n", target4);
    }
    
    // Test case 5: Find all occurrences
    printf("\nTest Case 5 (Multiple occurrences):\n");
    linearSearchAll(arr, n, 22);
    
    return 0;
}
