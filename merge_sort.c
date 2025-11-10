/*
 * Merge Sort Algorithm
 * 
 * Pseudocode for Merge Sort:
 * 1. If array has only one element, return (base case)
 * 2. Find the middle point to divide array into two halves
 * 3. Recursively sort the first half
 * 4. Recursively sort the second half
 * 5. Merge the two sorted halves
 * 
 * Pseudocode for Merge Function:
 * 1. Create temporary arrays for left and right halves
 * 2. Copy data to temporary arrays
 * 3. Initialize indices: i=0 (left), j=0 (right), k=left (merged)
 * 4. While both arrays have elements:
 *    a. If left[i] <= right[j]:
 *       - Copy left[i] to arr[k]
 *       - Increment i
 *    b. Else:
 *       - Copy right[j] to arr[k]
 *       - Increment j
 *    c. Increment k
 * 5. Copy remaining elements from left array (if any)
 * 6. Copy remaining elements from right array (if any)
 * 
 * Description:
 * Merge sort is a divide-and-conquer algorithm that divides the input array
 * into two halves, recursively sorts them, and then merges the two sorted
 * halves. The merge operation is the key process that combines two sorted
 * arrays into a single sorted array.
 * 
 * Time Complexity:
 * - Best Case: O(n log n)
 * - Average Case: O(n log n)
 * - Worst Case: O(n log n)
 * 
 * Space Complexity: O(n) - requires additional space for temporary arrays
 * 
 * Stability: Stable - maintains relative order of equal elements
 * 
 * Note: Merge sort is preferred for sorting linked lists and when stable
 * sorting is required. It guarantees O(n log n) time in all cases.
 */

#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // Size of left subarray
    int n2 = right - mid;      // Size of right subarray
    
    // Create temporary arrays
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));
    
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    
    // Merge the temporary arrays back into arr[left..right]
    int i = 0;    // Initial index of left subarray
    int j = 0;    // Initial index of right subarray
    int k = left; // Initial index of merged subarray
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements of L[] if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copy remaining elements of R[] if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    // Free temporary arrays
    free(L);
    free(R);
}

// Function to perform merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;
        
        // Sort first half
        mergeSort(arr, left, mid);
        
        // Sort second half
        mergeSort(arr, mid + 1, right);
        
        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to demonstrate merge sort
int main() {
    printf("=== Merge Sort Algorithm ===\n\n");
    
    // Test case 1: Random array
    printf("Test Case 1: Random Array\n");
    int arr1[] = {12, 11, 13, 5, 6, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("Original array: ");
    printArray(arr1, n1);
    
    mergeSort(arr1, 0, n1 - 1);
    
    printf("Sorted array:   ");
    printArray(arr1, n1);
    
    // Test case 2: Larger random array
    printf("\nTest Case 2: Larger Random Array\n");
    int arr2[] = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50, 22, 9, 33};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    printf("Original array: ");
    printArray(arr2, n2);
    
    mergeSort(arr2, 0, n2 - 1);
    
    printf("Sorted array:   ");
    printArray(arr2, n2);
    
    // Test case 3: Already sorted array
    printf("\nTest Case 3: Already Sorted Array\n");
    int arr3[] = {1, 2, 3, 4, 5, 6, 7};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    
    printf("Original array: ");
    printArray(arr3, n3);
    
    mergeSort(arr3, 0, n3 - 1);
    
    printf("Sorted array:   ");
    printArray(arr3, n3);
    
    // Test case 4: Reverse sorted array
    printf("\nTest Case 4: Reverse Sorted Array\n");
    int arr4[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    
    printf("Original array: ");
    printArray(arr4, n4);
    
    mergeSort(arr4, 0, n4 - 1);
    
    printf("Sorted array:   ");
    printArray(arr4, n4);
    
    // Test case 5: Array with duplicates
    printf("\nTest Case 5: Array with Duplicates\n");
    int arr5[] = {5, 2, 8, 2, 9, 1, 5, 5};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    
    printf("Original array: ");
    printArray(arr5, n5);
    
    mergeSort(arr5, 0, n5 - 1);
    
    printf("Sorted array:   ");
    printArray(arr5, n5);
    
    // Test case 6: Single element
    printf("\nTest Case 6: Single Element\n");
    int arr6[] = {42};
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    
    printf("Original array: ");
    printArray(arr6, n6);
    
    mergeSort(arr6, 0, n6 - 1);
    
    printf("Sorted array:   ");
    printArray(arr6, n6);
    
    return 0;
}
