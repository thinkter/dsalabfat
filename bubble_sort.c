/*
 * Bubble Sort Algorithm
 * 
 * Pseudocode:
 * 1. For i from 0 to n-1:
 *    a. Set swapped = false
 *    b. For j from 0 to n-i-2:
 *       i.  If arr[j] > arr[j+1]:
 *           - Swap arr[j] and arr[j+1]
 *           - Set swapped = true
 *    c. If no swaps were made (swapped == false), array is sorted, break
 * 2. Array is now sorted
 * 
 * Description:
 * Bubble sort repeatedly steps through the list, compares adjacent elements
 * and swaps them if they are in the wrong order. The pass through the list
 * is repeated until the list is sorted. The algorithm gets its name because
 * smaller elements "bubble" to the top of the list.
 * 
 * Time Complexity:
 * - Best Case: O(n) - when array is already sorted
 * - Average Case: O(n²)
 * - Worst Case: O(n²) - when array is reverse sorted
 * 
 * Space Complexity: O(1) - sorts in place
 * 
 * Stability: Stable - maintains relative order of equal elements
 */

#include <stdio.h>
#include <stdbool.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    bool swapped;
    
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++) {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        
        // If no swapping happened, array is already sorted
        if (!swapped) {
            printf("Array sorted after %d passes\n", i + 1);
            break;
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

// Main function to demonstrate bubble sort
int main() {
    printf("=== Bubble Sort Algorithm ===\n\n");
    
    // Test case 1: Random array
    printf("Test Case 1: Random Array\n");
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("Original array: ");
    printArray(arr1, n1);
    
    bubbleSort(arr1, n1);
    
    printf("Sorted array:   ");
    printArray(arr1, n1);
    
    // Test case 2: Already sorted array
    printf("\nTest Case 2: Already Sorted Array\n");
    int arr2[] = {1, 2, 3, 4, 5, 6, 7};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    printf("Original array: ");
    printArray(arr2, n2);
    
    bubbleSort(arr2, n2);
    
    printf("Sorted array:   ");
    printArray(arr2, n2);
    
    // Test case 3: Reverse sorted array
    printf("\nTest Case 3: Reverse Sorted Array\n");
    int arr3[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    
    printf("Original array: ");
    printArray(arr3, n3);
    
    bubbleSort(arr3, n3);
    
    printf("Sorted array:   ");
    printArray(arr3, n3);
    
    // Test case 4: Array with duplicates
    printf("\nTest Case 4: Array with Duplicates\n");
    int arr4[] = {5, 2, 8, 2, 9, 1, 5, 5};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    
    printf("Original array: ");
    printArray(arr4, n4);
    
    bubbleSort(arr4, n4);
    
    printf("Sorted array:   ");
    printArray(arr4, n4);
    
    return 0;
}
