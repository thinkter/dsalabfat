/*
 * Insertion Sort Algorithm
 * 
 * Pseudocode:
 * 1. For i from 1 to n-1:
 *    a. Set key = arr[i]
 *    b. Set j = i - 1
 *    c. While j >= 0 and arr[j] > key:
 *       i.  Move arr[j] to arr[j+1]
 *       ii. Decrement j
 *    d. Insert key at arr[j+1]
 * 2. Array is now sorted
 * 
 * Description:
 * Insertion sort builds the final sorted array one item at a time. It iterates
 * through the input array, and for each element, it finds the correct position
 * in the sorted portion and inserts it there. It is similar to how you might
 * sort playing cards in your hands.
 * 
 * Time Complexity:
 * - Best Case: O(n) - when array is already sorted
 * - Average Case: O(n²)
 * - Worst Case: O(n²) - when array is reverse sorted
 * 
 * Space Complexity: O(1) - sorts in place
 * 
 * Stability: Stable - maintains relative order of equal elements
 * 
 * Note: Insertion sort is efficient for small data sets and nearly sorted data.
 * It's often used as part of more sophisticated algorithms like Timsort.
 */

#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    int key, j;
    
    // Start from second element (index 1)
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to demonstrate step-by-step sorting
void insertionSortVerbose(int arr[], int n) {
    printf("Step-by-step insertion sort:\n");
    printf("Initial: ");
    printArray(arr, n);
    
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        
        printf("Step %d:  ", i);
        printArray(arr, n);
    }
}

// Main function to demonstrate insertion sort
int main() {
    printf("=== Insertion Sort Algorithm ===\n\n");
    
    // Test case 1: Random array with verbose output
    printf("Test Case 1: Random Array (Verbose)\n");
    int arr1[] = {12, 11, 13, 5, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    insertionSortVerbose(arr1, n1);
    
    // Test case 2: Random array
    printf("\nTest Case 2: Random Array\n");
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    printf("Original array: ");
    printArray(arr2, n2);
    
    insertionSort(arr2, n2);
    
    printf("Sorted array:   ");
    printArray(arr2, n2);
    
    // Test case 3: Already sorted array
    printf("\nTest Case 3: Already Sorted Array\n");
    int arr3[] = {1, 2, 3, 4, 5, 6, 7};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    
    printf("Original array: ");
    printArray(arr3, n3);
    
    insertionSort(arr3, n3);
    
    printf("Sorted array:   ");
    printArray(arr3, n3);
    
    // Test case 4: Reverse sorted array
    printf("\nTest Case 4: Reverse Sorted Array\n");
    int arr4[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    
    printf("Original array: ");
    printArray(arr4, n4);
    
    insertionSort(arr4, n4);
    
    printf("Sorted array:   ");
    printArray(arr4, n4);
    
    // Test case 5: Array with duplicates
    printf("\nTest Case 5: Array with Duplicates\n");
    int arr5[] = {5, 2, 8, 2, 9, 1, 5, 5};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    
    printf("Original array: ");
    printArray(arr5, n5);
    
    insertionSort(arr5, n5);
    
    printf("Sorted array:   ");
    printArray(arr5, n5);
    
    // Test case 6: Single element
    printf("\nTest Case 6: Single Element\n");
    int arr6[] = {42};
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    
    printf("Original array: ");
    printArray(arr6, n6);
    
    insertionSort(arr6, n6);
    
    printf("Sorted array:   ");
    printArray(arr6, n6);
    
    return 0;
}
