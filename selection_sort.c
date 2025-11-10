/*
 * Selection Sort Algorithm
 * 
 * Pseudocode:
 * 1. For i from 0 to n-2:
 *    a. Set min_index = i
 *    b. For j from i+1 to n-1:
 *       i.  If arr[j] < arr[min_index]:
 *           - Set min_index = j
 *    c. If min_index != i:
 *       i.  Swap arr[i] and arr[min_index]
 * 2. Array is now sorted
 * 
 * Description:
 * Selection sort divides the input list into two parts: a sorted portion
 * at the left end and an unsorted portion at the right end. Initially,
 * the sorted portion is empty and the unsorted portion is the entire list.
 * The algorithm proceeds by finding the smallest element in the unsorted
 * portion, swapping it with the leftmost unsorted element, and moving the
 * sorted/unsorted boundary one element to the right.
 * 
 * Time Complexity:
 * - Best Case: O(n²)
 * - Average Case: O(n²)
 * - Worst Case: O(n²)
 * 
 * Space Complexity: O(1) - sorts in place
 * 
 * Stability: Unstable - may change relative order of equal elements
 * 
 * Note: Selection sort performs well on small lists and requires minimum
 * number of swaps (at most n-1 swaps).
 */

#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    int min_index;
    
    // Move boundary of unsorted subarray one by one
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        
        // Swap the found minimum element with the first element
        if (min_index != i) {
            swap(&arr[i], &arr[min_index]);
        }
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to demonstrate selection sort
int main() {
    printf("=== Selection Sort Algorithm ===\n\n");
    
    // Test case 1: Random array
    printf("Test Case 1: Random Array\n");
    int arr1[] = {64, 25, 12, 22, 11};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("Original array: ");
    printArray(arr1, n1);
    
    selectionSort(arr1, n1);
    
    printf("Sorted array:   ");
    printArray(arr1, n1);
    
    // Test case 2: Already sorted array
    printf("\nTest Case 2: Already Sorted Array\n");
    int arr2[] = {1, 2, 3, 4, 5, 6, 7};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    printf("Original array: ");
    printArray(arr2, n2);
    
    selectionSort(arr2, n2);
    
    printf("Sorted array:   ");
    printArray(arr2, n2);
    
    // Test case 3: Reverse sorted array
    printf("\nTest Case 3: Reverse Sorted Array\n");
    int arr3[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    
    printf("Original array: ");
    printArray(arr3, n3);
    
    selectionSort(arr3, n3);
    
    printf("Sorted array:   ");
    printArray(arr3, n3);
    
    // Test case 4: Array with duplicates
    printf("\nTest Case 4: Array with Duplicates\n");
    int arr4[] = {5, 2, 8, 2, 9, 1, 5, 5};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    
    printf("Original array: ");
    printArray(arr4, n4);
    
    selectionSort(arr4, n4);
    
    printf("Sorted array:   ");
    printArray(arr4, n4);
    
    // Test case 5: Single element
    printf("\nTest Case 5: Single Element\n");
    int arr5[] = {42};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    
    printf("Original array: ");
    printArray(arr5, n5);
    
    selectionSort(arr5, n5);
    
    printf("Sorted array:   ");
    printArray(arr5, n5);
    
    return 0;
}
