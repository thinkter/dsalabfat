# Data Structures and Algorithms Laboratory (FAT)

This repository contains C implementations of various data structures and algorithms with detailed comments and pseudocode. Each program is designed to be educational and demonstrates the core concepts of the algorithm/data structure.

## Programs Included

### 1. Single Source Shortest Path - Dijkstra's Algorithm
**File:** `1_dijkstra.c`

Implements Dijkstra's algorithm to find the shortest path from a source vertex to all other vertices in a weighted graph.

**Compile and Run:**
```bash
gcc -o 1_dijkstra 1_dijkstra.c
./1_dijkstra
```

**Key Concepts:**
- Greedy algorithm
- Graph traversal
- Shortest path finding
- Time Complexity: O(V²) where V is the number of vertices

---

### 2. Minimum Spanning Tree - Prim's Algorithm
**File:** `2_prims.c`

Implements Prim's algorithm (greedy method) to find the minimum spanning tree of a weighted graph.

**Compile and Run:**
```bash
gcc -o 2_prims 2_prims.c
./2_prims
```

**Key Concepts:**
- Greedy algorithm
- Minimum spanning tree
- Graph connectivity
- Time Complexity: O(V²)

---

### 3. Minimum Spanning Tree - Kruskal's Algorithm
**File:** `3_kruskal.c`

Implements Kruskal's algorithm (greedy method) to find the minimum spanning tree using Union-Find data structure.

**Compile and Run:**
```bash
gcc -o 3_kruskal 3_kruskal.c
./3_kruskal
```

**Key Concepts:**
- Greedy algorithm
- Union-Find (Disjoint Set)
- Cycle detection
- Edge sorting
- Time Complexity: O(E log E) where E is the number of edges

---

### 4. Breadth First Search (BFS)
**File:** `4_bfs.c`

Implements BFS graph traversal using a queue data structure.

**Compile and Run:**
```bash
gcc -o 4_bfs 4_bfs.c
./4_bfs
```

**Key Concepts:**
- Level-order traversal
- Queue data structure
- Graph exploration
- Time Complexity: O(V + E)

---

### 5. Depth First Search (DFS)
**File:** `5_dfs.c`

Implements DFS graph traversal in both recursive and iterative (using stack) approaches.

**Compile and Run:**
```bash
gcc -o 5_dfs 5_dfs.c
./5_dfs
```

**Key Concepts:**
- Recursive and iterative approaches
- Stack data structure
- Backtracking
- Time Complexity: O(V + E)

---

### 6. Binary Search Tree (BST) Implementation
**File:** `6_bst.c`

Complete implementation of a Binary Search Tree with insert, search, delete, and traversal operations.

**Compile and Run:**
```bash
gcc -o 6_bst 6_bst.c
./6_bst
```

**Key Concepts:**
- Binary tree properties
- Insert, search, delete operations
- Inorder, preorder, postorder traversals
- Time Complexity: O(h) where h is height (O(log n) average, O(n) worst case)

---

### 7. Binary Tree Traversal
**File:** `7_binary_tree_traversal.c`

Demonstrates all four binary tree traversal methods: inorder, preorder, postorder, and level-order.

**Compile and Run:**
```bash
gcc -o 7_binary_tree_traversal 7_binary_tree_traversal.c
./7_binary_tree_traversal
```

**Key Concepts:**
- Inorder (Left-Root-Right)
- Preorder (Root-Left-Right)
- Postorder (Left-Right-Root)
- Level-order (BFS)
- Time Complexity: O(n) for all traversals

---

### 8. Binary Search
**File:** `8_binary_search.c`

Implements binary search algorithm in both iterative and recursive approaches.

**Compile and Run:**
```bash
gcc -o 8_binary_search 8_binary_search.c
./8_binary_search
```

**Key Concepts:**
- Divide and conquer
- Requires sorted array
- Iterative and recursive implementations
- Time Complexity: O(log n)
- Space Complexity: O(1) iterative, O(log n) recursive

---

### 9. Linear Search
**File:** `9_linear_search.c`

Implements linear search algorithm with examples of finding single and multiple occurrences.

**Compile and Run:**
```bash
gcc -o 9_linear_search 9_linear_search.c
./9_linear_search
```

**Key Concepts:**
- Sequential search
- Works on unsorted arrays
- Simple but less efficient for large datasets
- Time Complexity: O(n)
- Space Complexity: O(1)

---

## How to Use

### Quick Start - Compile All Programs
The easiest way to compile all programs is using the provided script:
```bash
chmod +x compile_all.sh
./compile_all.sh
```

### Manual Compilation
Alternatively, you can compile programs individually:

**Graph Algorithms:**
```bash
gcc -o 1_dijkstra 1_dijkstra.c
gcc -o 2_prims 2_prims.c
gcc -o 3_kruskal 3_kruskal.c
gcc -o 4_bfs 4_bfs.c
gcc -o 5_dfs 5_dfs.c
```

**Tree Algorithms:**
```bash
gcc -o 6_bst 6_bst.c
gcc -o 7_binary_tree_traversal 7_binary_tree_traversal.c
```

**Search Algorithms:**
```bash
gcc -o 8_binary_search 8_binary_search.c
gcc -o 9_linear_search 9_linear_search.c
```

**Data Structures:**
```bash
gcc -o singly_linked_list singly_linked_list.c
gcc -o doubly_linked_list doubly_linked_list.c
gcc -o circular_linked_list circular_linked_list.c
gcc -o stack_array stack_array.c
gcc -o queue_array queue_array.c
```

**Sorting Algorithms:**
```bash
gcc -o bubble_sort bubble_sort.c
gcc -o selection_sort selection_sort.c
gcc -o insertion_sort insertion_sort.c
gcc -o merge_sort merge_sort.c
gcc -o counting_sort counting_sort.c
gcc -o quicksort quicksort.c
```

### Run Individual Programs
After compilation, run any program:
```bash
./<program_name>
```

## Features

- **Detailed Comments:** Each program includes comprehensive comments explaining the logic
- **Pseudocode:** Algorithm pseudocode is provided at the beginning of each file
- **Example Usage:** All programs include working examples in the main function
- **Educational Focus:** Code is written for clarity and learning, not just efficiency

## Requirements

- GCC compiler (or any standard C compiler)
- Basic understanding of C programming
- Terminal/Command prompt to compile and run programs

## Learning Outcomes

By studying these programs, you will learn:
- **Graph algorithms:** Dijkstra, Prim's, Kruskal's, BFS, DFS
- **Tree data structures:** BST, Binary Tree
- **Tree traversal techniques:** Inorder, Preorder, Postorder, Level-order
- **Search algorithms:** Binary Search, Linear Search
- **Linear data structures:** Singly Linked List, Doubly Linked List, Circular Linked List, Stack, Queue
- **Sorting algorithms:** Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, Counting Sort, Quicksort
- **Time and space complexity analysis**
- **Greedy algorithms**
- **Divide and conquer approach**
- **Array and pointer manipulation in C**

## Notes

- All programs are self-contained with no external dependencies
- Input examples are hardcoded for simplicity
- You can modify the input data in the main function to test with different cases
- The .gitignore file excludes compiled binaries from version control

---

## Data Structures

### Singly Linked List
**File:** `singly_linked_list.c`

A linear data structure where each element points to the next element in the sequence.

**Compile and Run:**
```bash
gcc -o singly_linked_list singly_linked_list.c
./singly_linked_list
```

**Operations Implemented:**
- Creation of nodes
- Insertion at beginning, end, and specific position
- Deletion from beginning, end, and by value
- Display list

**Pseudocode:**

*Creation:*
```
1. Define a structure Node with:
   - data field to store value
   - next pointer to point to next node
2. Initialize head pointer to NULL
```

*Insertion at Beginning:*
```
1. Create a new node
2. Assign data to the new node
3. Set new node's next to current head
4. Update head to point to new node
```

*Deletion at Beginning:*
```
1. If list is empty, return
2. Store head in temp
3. Move head to next node
4. Free temp
```

**Time Complexity:**
- Insertion at beginning: O(1)
- Insertion at end: O(n)
- Deletion: O(1) for beginning, O(n) for end

---

### Doubly Linked List
**File:** `doubly_linked_list.c`

A linear data structure where each element has pointers to both the next and previous elements.

**Compile and Run:**
```bash
gcc -o doubly_linked_list doubly_linked_list.c
./doubly_linked_list
```

**Operations Implemented:**
- Creation of nodes with prev and next pointers
- Insertion at beginning, end, and specific position
- Deletion from beginning, end, and by value
- Forward and backward traversal

**Pseudocode:**

*Creation:*
```
1. Define a structure Node with:
   - data field to store value
   - next pointer to point to next node
   - prev pointer to point to previous node
2. Initialize head pointer to NULL
```

*Insertion at Beginning:*
```
1. Create a new node
2. Set new node's prev to NULL
3. Set new node's next to current head
4. If head is not NULL, set head's prev to new node
5. Update head to point to new node
```

*Deletion by Value:*
```
1. If list is empty, return
2. Traverse to find node with value
3. If node is head, update head to next node
4. Update next node's prev pointer (if exists)
5. Update previous node's next pointer (if exists)
6. Free the node
```

**Time Complexity:**
- Insertion at beginning: O(1)
- Deletion: O(1) for beginning, O(n) for specific value

---

### Circular Linked List
**File:** `circular_linked_list.c`

A linked list where the last node points back to the first node, forming a circle.

**Compile and Run:**
```bash
gcc -o circular_linked_list circular_linked_list.c
./circular_linked_list
```

**Operations Implemented:**
- Creation with circular linking
- Insertion at beginning, end, and specific position
- Deletion from beginning, end, and by value
- Display showing circular nature

**Pseudocode:**

*Creation:*
```
1. Define a structure Node with data and next pointer
2. Initialize head pointer to NULL
3. In circular list, last node points back to head
```

*Insertion at End:*
```
1. Create a new node
2. If list is empty, set new node's next to itself
3. Else:
   a. Find last node (node whose next is head)
   b. Set new node's next to head
   c. Set last node's next to new node
```

*Deletion at Beginning:*
```
1. If list is empty, return
2. If only one node, free it and set head to NULL
3. Else:
   a. Find last node
   b. Set last node's next to head's next
   c. Update head to head's next
   d. Free old head
```

**Time Complexity:**
- Insertion: O(n) - need to find last node
- Deletion: O(n) - need to traverse

---

### Stack (Array Implementation)
**File:** `stack_array.c`

A Last-In-First-Out (LIFO) data structure implemented using an array.

**Compile and Run:**
```bash
gcc -o stack_array stack_array.c
./stack_array
```

**Operations Implemented:**
- Push (insert at top)
- Pop (remove from top)
- Peek (view top element)
- isEmpty and isFull checks

**Pseudocode:**

*Creation:*
```
1. Define maximum size MAX_SIZE for stack
2. Create an array of size MAX_SIZE
3. Initialize top = -1 (indicates empty stack)
```

*Push Operation:*
```
1. Check if stack is full (top == MAX_SIZE - 1)
2. If full, display overflow message
3. Else:
   a. Increment top
   b. Insert element at stack[top]
```

*Pop Operation:*
```
1. Check if stack is empty (top == -1)
2. If empty, display underflow message
3. Else:
   a. Get element from stack[top]
   b. Decrement top
   c. Return the element
```

**Time Complexity:**
- Push: O(1)
- Pop: O(1)
- Peek: O(1)

---

### Queue (Array Implementation)
**File:** `queue_array.c`

A First-In-First-Out (FIFO) data structure implemented using an array.

**Compile and Run:**
```bash
gcc -o queue_array queue_array.c
./queue_array
```

**Operations Implemented:**
- Enqueue (insert at rear)
- Dequeue (remove from front)
- Peek (view front element)
- isEmpty and isFull checks

**Pseudocode:**

*Creation:*
```
1. Define maximum size MAX_SIZE for queue
2. Create an array of size MAX_SIZE
3. Initialize front = -1 and rear = -1
```

*Enqueue Operation:*
```
1. Check if queue is full (rear == MAX_SIZE - 1)
2. If full, display overflow message
3. If queue is empty, set front = 0
4. Increment rear
5. Insert element at queue[rear]
```

*Dequeue Operation:*
```
1. Check if queue is empty (front == -1 or front > rear)
2. If empty, display underflow message
3. Get element from queue[front]
4. If front == rear, reset to -1
5. Else, increment front
6. Return the element
```

**Time Complexity:**
- Enqueue: O(1)
- Dequeue: O(1)
- Peek: O(1)

---

## Sorting Algorithms

### Bubble Sort
**File:** `bubble_sort.c`

A simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order.

**Compile and Run:**
```bash
gcc -o bubble_sort bubble_sort.c
./bubble_sort
```

**Pseudocode:**
```
1. For i from 0 to n-1:
   a. Set swapped = false
   b. For j from 0 to n-i-2:
      i.  If arr[j] > arr[j+1]:
          - Swap arr[j] and arr[j+1]
          - Set swapped = true
   c. If no swaps were made, break (array is sorted)
```

**Time Complexity:**
- Best Case: O(n) - already sorted
- Average Case: O(n²)
- Worst Case: O(n²)

**Space Complexity:** O(1)

**Stability:** Stable

---

### Selection Sort
**File:** `selection_sort.c`

A sorting algorithm that divides the input into sorted and unsorted regions, repeatedly selecting the smallest element from the unsorted region.

**Compile and Run:**
```bash
gcc -o selection_sort selection_sort.c
./selection_sort
```

**Pseudocode:**
```
1. For i from 0 to n-2:
   a. Set min_index = i
   b. For j from i+1 to n-1:
      i.  If arr[j] < arr[min_index]:
          - Set min_index = j
   c. If min_index != i:
      i.  Swap arr[i] and arr[min_index]
```

**Time Complexity:**
- Best Case: O(n²)
- Average Case: O(n²)
- Worst Case: O(n²)

**Space Complexity:** O(1)

**Stability:** Unstable

---

### Insertion Sort
**File:** `insertion_sort.c`

A sorting algorithm that builds the final sorted array one item at a time by inserting each element into its proper position.

**Compile and Run:**
```bash
gcc -o insertion_sort insertion_sort.c
./insertion_sort
```

**Pseudocode:**
```
1. For i from 1 to n-1:
   a. Set key = arr[i]
   b. Set j = i - 1
   c. While j >= 0 and arr[j] > key:
      i.  Move arr[j] to arr[j+1]
      ii. Decrement j
   d. Insert key at arr[j+1]
```

**Time Complexity:**
- Best Case: O(n) - already sorted
- Average Case: O(n²)
- Worst Case: O(n²)

**Space Complexity:** O(1)

**Stability:** Stable

---

### Merge Sort
**File:** `merge_sort.c`

A divide-and-conquer algorithm that divides the array into two halves, recursively sorts them, and then merges the sorted halves.

**Compile and Run:**
```bash
gcc -o merge_sort merge_sort.c
./merge_sort
```

**Pseudocode:**

*Merge Sort:*
```
1. If array has only one element, return
2. Find the middle point to divide array
3. Recursively sort the first half
4. Recursively sort the second half
5. Merge the two sorted halves
```

*Merge Function:*
```
1. Create temporary arrays for left and right halves
2. Copy data to temporary arrays
3. Merge by comparing elements from both arrays
4. Copy remaining elements (if any)
```

**Time Complexity:**
- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n log n)

**Space Complexity:** O(n)

**Stability:** Stable

---

### Counting Sort
**File:** `counting_sort.c`

A non-comparison based sorting algorithm that counts the number of occurrences of each unique element.

**Compile and Run:**
```bash
gcc -o counting_sort counting_sort.c
./counting_sort
```

**Pseudocode:**
```
1. Find the maximum element in the array
2. Create a count array of size (max + 1) initialized to 0
3. Store the count of each element:
   For each element x: count[x]++
4. Modify count array to store cumulative counts
5. Build the output array:
   For each element x (from right to left):
      a. Place x at position count[x] - 1
      b. Decrement count[x]
6. Copy output array to original array
```

**Time Complexity:**
- Best Case: O(n + k) where k is range
- Average Case: O(n + k)
- Worst Case: O(n + k)

**Space Complexity:** O(n + k)

**Stability:** Stable

**Note:** Efficient when range of input (k) is not significantly greater than number of elements (n).

---

### Quicksort
**File:** `quicksort.c`

A divide-and-conquer algorithm that selects a pivot element and partitions the array around it.

**Compile and Run:**
```bash
gcc -o quicksort quicksort.c
./quicksort
```

**Pseudocode:**

*Quicksort:*
```
1. If left < right:
   a. Choose a pivot element
   b. Partition array around pivot
   c. Recursively sort left partition
   d. Recursively sort right partition
```

*Partition Function:*
```
1. Choose pivot = arr[right]
2. Set i = left - 1
3. For j from left to right-1:
   a. If arr[j] < pivot:
      i.  Increment i
      ii. Swap arr[i] and arr[j]
4. Swap arr[i+1] and arr[right]
5. Return i+1
```

**Time Complexity:**
- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n²)

**Space Complexity:** O(log n) to O(n)

**Stability:** Unstable

---

## Notes

- All programs are self-contained with no external dependencies
- Input examples are hardcoded for simplicity
- You can modify the input data in the main function to test with different cases
- The .gitignore file excludes compiled binaries from version control

## Author

Created for educational purposes to help students understand data structures and algorithms.

## License

Free to use for educational purposes.