/*
 * Binary Search Algorithm
 * 
 * Pseudocode (Iterative):
 * 1. Set low = 0 and high = n-1 (where n is array size)
 * 2. While low <= high:
 *    a. Calculate mid = low + (high - low) / 2
 *    b. If arr[mid] equals target, return mid
 *    c. If target is less than arr[mid], set high = mid - 1
 *    d. If target is greater than arr[mid], set low = mid + 1
 * 3. If element not found, return -1
 * 
 * Pseudocode (Recursive):
 * 1. If low > high, return -1 (element not found)
 * 2. Calculate mid = low + (high - low) / 2
 * 3. If arr[mid] equals target, return mid
 * 4. If target is less than arr[mid], recursively search left half
 * 5. If target is greater than arr[mid], recursively search right half
 * 
 * Note: Binary search requires the array to be sorted
 * Time Complexity: O(log n)
 * Space Complexity: O(1) for iterative, O(log n) for recursive
 */

#include <stdio.h>

// Iterative implementation of Binary Search
int binarySearchIterative(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    
    while (low <= high) {
        // Calculate mid to avoid overflow
        int mid = low + (high - low) / 2;
        
        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;
        }
        
        // If target is greater, ignore left half
        if (arr[mid] < target) {
            low = mid + 1;
        }
        // If target is smaller, ignore right half
        else {
            high = mid - 1;
        }
    }
    
    // Element not found
    return -1;
}

// Recursive implementation of Binary Search
int binarySearchRecursive(int arr[], int low, int high, int target) {
    // Base case: element not found
    if (low > high) {
        return -1;
    }
    
    // Calculate mid
    int mid = low + (high - low) / 2;
    
    // Check if target is present at mid
    if (arr[mid] == target) {
        return mid;
    }
    
    // If target is smaller than mid, search in left half
    if (arr[mid] > target) {
        return binarySearchRecursive(arr, low, mid - 1, target);
    }
    
    // If target is greater than mid, search in right half
    return binarySearchRecursive(arr, mid + 1, high, target);
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver program to test binary search
int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Binary Search Algorithm\n");
    printf("=======================\n\n");
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    // Test iterative binary search
    printf("\nIterative Binary Search:\n");
    int target1 = 23;
    int result1 = binarySearchIterative(arr, n, target1);
    if (result1 != -1) {
        printf("Element %d found at index %d\n", target1, result1);
    } else {
        printf("Element %d not found in array\n", target1);
    }
    
    int target2 = 50;
    int result2 = binarySearchIterative(arr, n, target2);
    if (result2 != -1) {
        printf("Element %d found at index %d\n", target2, result2);
    } else {
        printf("Element %d not found in array\n", target2);
    }
    
    // Test recursive binary search
    printf("\nRecursive Binary Search:\n");
    int target3 = 45;
    int result3 = binarySearchRecursive(arr, 0, n - 1, target3);
    if (result3 != -1) {
        printf("Element %d found at index %d\n", target3, result3);
    } else {
        printf("Element %d not found in array\n", target3);
    }
    
    int target4 = 100;
    int result4 = binarySearchRecursive(arr, 0, n - 1, target4);
    if (result4 != -1) {
        printf("Element %d found at index %d\n", target4, result4);
    } else {
        printf("Element %d not found in array\n", target4);
    }
    
    return 0;
}
