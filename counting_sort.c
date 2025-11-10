/*
 * Counting Sort Algorithm
 * 
 * Pseudocode:
 * 1. Find the maximum element in the array
 * 2. Create a count array of size (max + 1) initialized to 0
 * 3. Store the count of each element:
 *    For each element x in arr:
 *       Increment count[x]
 * 4. Modify count array to store cumulative counts:
 *    For i from 1 to max:
 *       count[i] = count[i] + count[i-1]
 * 5. Build the output array:
 *    For each element x in arr (traversing from right to left):
 *       a. Place x at position count[x] - 1 in output
 *       b. Decrement count[x]
 * 6. Copy output array to original array
 * 
 * Description:
 * Counting sort is an integer sorting algorithm that operates by counting
 * the number of objects that have each distinct key value, and using
 * arithmetic to determine the positions of each key value in the output
 * sequence. It is not a comparison-based sorting algorithm.
 * 
 * Time Complexity:
 * - Best Case: O(n + k) where k is the range of input
 * - Average Case: O(n + k)
 * - Worst Case: O(n + k)
 * 
 * Space Complexity: O(n + k) - requires extra space for count and output arrays
 * 
 * Stability: Stable - maintains relative order of equal elements
 * 
 * Note: Counting sort is efficient when the range of input values (k) is
 * not significantly greater than the number of elements (n). It's often used
 * as a subroutine in radix sort. Works only with non-negative integers or
 * can be adapted for negative integers.
 */

#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum element in an array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform counting sort
void countingSort(int arr[], int n) {
    // Find the maximum element to determine range
    int max = findMax(arr, n);
    
    // Create count array and initialize to 0
    int* count = (int*)calloc(max + 1, sizeof(int));
    
    // Create output array
    int* output = (int*)malloc(n * sizeof(int));
    
    // Store count of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    // Modify count array to store cumulative counts
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    
    // Build the output array
    // Traverse from right to left to maintain stability
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    // Copy the output array to arr
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    
    // Free allocated memory
    free(count);
    free(output);
}

// Simplified counting sort (for demonstration)
void countingSortSimple(int arr[], int n) {
    int max = findMax(arr, n);
    int* count = (int*)calloc(max + 1, sizeof(int));
    
    // Count occurrences
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    // Reconstruct array
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
    
    free(count);
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to demonstrate counting sort
int main() {
    printf("=== Counting Sort Algorithm ===\n\n");
    
    // Test case 1: Random array
    printf("Test Case 1: Random Array\n");
    int arr1[] = {4, 2, 2, 8, 3, 3, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("Original array: ");
    printArray(arr1, n1);
    
    countingSort(arr1, n1);
    
    printf("Sorted array:   ");
    printArray(arr1, n1);
    
    // Test case 2: Array with larger range
    printf("\nTest Case 2: Array with Larger Range\n");
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    printf("Original array: ");
    printArray(arr2, n2);
    
    countingSort(arr2, n2);
    
    printf("Sorted array:   ");
    printArray(arr2, n2);
    
    // Test case 3: Already sorted array
    printf("\nTest Case 3: Already Sorted Array\n");
    int arr3[] = {1, 2, 3, 4, 5, 6, 7};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    
    printf("Original array: ");
    printArray(arr3, n3);
    
    countingSort(arr3, n3);
    
    printf("Sorted array:   ");
    printArray(arr3, n3);
    
    // Test case 4: Reverse sorted array
    printf("\nTest Case 4: Reverse Sorted Array\n");
    int arr4[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    
    printf("Original array: ");
    printArray(arr4, n4);
    
    countingSort(arr4, n4);
    
    printf("Sorted array:   ");
    printArray(arr4, n4);
    
    // Test case 5: Array with many duplicates
    printf("\nTest Case 5: Array with Many Duplicates\n");
    int arr5[] = {5, 2, 8, 2, 9, 1, 5, 5, 2, 2, 1};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    
    printf("Original array: ");
    printArray(arr5, n5);
    
    countingSort(arr5, n5);
    
    printf("Sorted array:   ");
    printArray(arr5, n5);
    
    // Test case 6: Single element
    printf("\nTest Case 6: Single Element\n");
    int arr6[] = {42};
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    
    printf("Original array: ");
    printArray(arr6, n6);
    
    countingSort(arr6, n6);
    
    printf("Sorted array:   ");
    printArray(arr6, n6);
    
    // Test case 7: Array with zeros
    printf("\nTest Case 7: Array with Zeros\n");
    int arr7[] = {0, 5, 0, 3, 0, 2, 0, 1};
    int n7 = sizeof(arr7) / sizeof(arr7[0]);
    
    printf("Original array: ");
    printArray(arr7, n7);
    
    countingSort(arr7, n7);
    
    printf("Sorted array:   ");
    printArray(arr7, n7);
    
    return 0;
}
