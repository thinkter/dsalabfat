/*
 * Quicksort Algorithm
 * 
 * Pseudocode for Quicksort:
 * 1. If left < right:
 *    a. Choose a pivot element (commonly the last element)
 *    b. Partition the array around pivot:
 *       - Elements smaller than pivot go to left
 *       - Elements greater than pivot go to right
 *    c. Recursively sort the left partition
 *    d. Recursively sort the right partition
 * 
 * Pseudocode for Partition Function:
 * 1. Choose pivot = arr[right]
 * 2. Set i = left - 1 (index of smaller element)
 * 3. For j from left to right-1:
 *    a. If arr[j] < pivot:
 *       i.  Increment i
 *       ii. Swap arr[i] and arr[j]
 * 4. Swap arr[i+1] and arr[right] (place pivot in correct position)
 * 5. Return i+1 (partition index)
 * 
 * Description:
 * Quicksort is a divide-and-conquer algorithm that works by selecting a
 * 'pivot' element from the array and partitioning the other elements into
 * two sub-arrays according to whether they are less than or greater than
 * the pivot. The sub-arrays are then sorted recursively.
 * 
 * Time Complexity:
 * - Best Case: O(n log n) - when pivot divides array into equal halves
 * - Average Case: O(n log n)
 * - Worst Case: O(n²) - when pivot is always smallest or largest element
 * 
 * Space Complexity: 
 * - O(log n) - for recursive call stack in average case
 * - O(n) - in worst case (unbalanced partitions)
 * 
 * Stability: Unstable - may change relative order of equal elements
 * 
 * Note: Quicksort is often the fastest sorting algorithm in practice.
 * It can be optimized using techniques like median-of-three pivot selection,
 * randomized pivot selection, and switching to insertion sort for small arrays.
 */

#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function that places pivot element at correct position
// and places all smaller elements to left and all greater to right
int partition(int arr[], int left, int right) {
    // Choose the rightmost element as pivot
    int pivot = arr[right];
    
    // Index of smaller element
    int i = left - 1;
    
    for (int j = left; j < right; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    // Place pivot in correct position
    swap(&arr[i + 1], &arr[right]);
    
    return i + 1;
}

// Main quicksort function
void quicksort(int arr[], int left, int right) {
    if (left < right) {
        // Partition the array and get the partition index
        int pi = partition(arr, left, right);
        
        // Recursively sort elements before and after partition
        quicksort(arr, left, pi - 1);
        quicksort(arr, pi + 1, right);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to demonstrate quicksort
int main() {
    printf("=== Quicksort Algorithm ===\n\n");
    
    // Test case 1: Random array
    printf("Test Case 1: Random Array\n");
    int arr1[] = {10, 7, 8, 9, 1, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("Original array: ");
    printArray(arr1, n1);
    
    quicksort(arr1, 0, n1 - 1);
    
    printf("Sorted array:   ");
    printArray(arr1, n1);
    
    // Test case 2: Larger random array
    printf("\nTest Case 2: Larger Random Array\n");
    int arr2[] = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    printf("Original array: ");
    printArray(arr2, n2);
    
    quicksort(arr2, 0, n2 - 1);
    
    printf("Sorted array:   ");
    printArray(arr2, n2);
    
    // Test case 3: Already sorted array
    printf("\nTest Case 3: Already Sorted Array\n");
    int arr3[] = {1, 2, 3, 4, 5, 6, 7};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    
    printf("Original array: ");
    printArray(arr3, n3);
    
    quicksort(arr3, 0, n3 - 1);
    
    printf("Sorted array:   ");
    printArray(arr3, n3);
    
    // Test case 4: Reverse sorted array
    printf("\nTest Case 4: Reverse Sorted Array\n");
    int arr4[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    
    printf("Original array: ");
    printArray(arr4, n4);
    
    quicksort(arr4, 0, n4 - 1);
    
    printf("Sorted array:   ");
    printArray(arr4, n4);
    
    // Test case 5: Array with duplicates
    printf("\nTest Case 5: Array with Duplicates\n");
    int arr5[] = {5, 2, 8, 2, 9, 1, 5, 5};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    
    printf("Original array: ");
    printArray(arr5, n5);
    
    quicksort(arr5, 0, n5 - 1);
    
    printf("Sorted array:   ");
    printArray(arr5, n5);
    
    // Test case 6: Single element
    printf("\nTest Case 6: Single Element\n");
    int arr6[] = {42};
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    
    printf("Original array: ");
    printArray(arr6, n6);
    
    quicksort(arr6, 0, n6 - 1);
    
    printf("Sorted array:   ");
    printArray(arr6, n6);
    
    // Test case 7: Two elements
    printf("\nTest Case 7: Two Elements\n");
    int arr7[] = {5, 3};
    int n7 = sizeof(arr7) / sizeof(arr7[0]);
    
    printf("Original array: ");
    printArray(arr7, n7);
    
    quicksort(arr7, 0, n7 - 1);
    
    printf("Sorted array:   ");
    printArray(arr7, n7);
    
    return 0;
}
