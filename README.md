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

### Compile All Programs
You can compile all programs at once using:
```bash
gcc -o 1_dijkstra 1_dijkstra.c
gcc -o 2_prims 2_prims.c
gcc -o 3_kruskal 3_kruskal.c
gcc -o 4_bfs 4_bfs.c
gcc -o 5_dfs 5_dfs.c
gcc -o 6_bst 6_bst.c
gcc -o 7_binary_tree_traversal 7_binary_tree_traversal.c
gcc -o 8_binary_search 8_binary_search.c
gcc -o 9_linear_search 9_linear_search.c
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
- Graph algorithms (Dijkstra, Prim's, Kruskal's, BFS, DFS)
- Tree data structures (BST, Binary Tree)
- Tree traversal techniques
- Searching algorithms (Binary Search, Linear Search)
- Time and space complexity analysis
- Greedy algorithms
- Divide and conquer approach

## Notes

- All programs are self-contained with no external dependencies
- Input examples are hardcoded for simplicity
- You can modify the input data in the main function to test with different cases
- The .gitignore file excludes compiled binaries from version control

## Author

Created for educational purposes to help students understand data structures and algorithms.

## License

Free to use for educational purposes.