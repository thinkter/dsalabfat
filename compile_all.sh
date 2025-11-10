#!/bin/bash
# Script to compile all C programs

echo "Compiling all programs..."
echo ""

# Compile graph algorithms
gcc -o 1_dijkstra 1_dijkstra.c && echo "✓ Compiled 1_dijkstra"
gcc -o 2_prims 2_prims.c && echo "✓ Compiled 2_prims"
gcc -o 3_kruskal 3_kruskal.c && echo "✓ Compiled 3_kruskal"
gcc -o 4_bfs 4_bfs.c && echo "✓ Compiled 4_bfs"
gcc -o 5_dfs 5_dfs.c && echo "✓ Compiled 5_dfs"

# Compile tree algorithms
gcc -o 6_bst 6_bst.c && echo "✓ Compiled 6_bst"
gcc -o 7_binary_tree_traversal 7_binary_tree_traversal.c && echo "✓ Compiled 7_binary_tree_traversal"

# Compile search algorithms
gcc -o 8_binary_search 8_binary_search.c && echo "✓ Compiled 8_binary_search"
gcc -o 9_linear_search 9_linear_search.c && echo "✓ Compiled 9_linear_search"

# Compile data structures
gcc -o singly_linked_list singly_linked_list.c && echo "✓ Compiled singly_linked_list"
gcc -o doubly_linked_list doubly_linked_list.c && echo "✓ Compiled doubly_linked_list"
gcc -o circular_linked_list circular_linked_list.c && echo "✓ Compiled circular_linked_list"
gcc -o stack_array stack_array.c && echo "✓ Compiled stack_array"
gcc -o queue_array queue_array.c && echo "✓ Compiled queue_array"

# Compile sorting algorithms
gcc -o bubble_sort bubble_sort.c && echo "✓ Compiled bubble_sort"
gcc -o selection_sort selection_sort.c && echo "✓ Compiled selection_sort"
gcc -o insertion_sort insertion_sort.c && echo "✓ Compiled insertion_sort"
gcc -o merge_sort merge_sort.c && echo "✓ Compiled merge_sort"
gcc -o counting_sort counting_sort.c && echo "✓ Compiled counting_sort"
gcc -o quicksort quicksort.c && echo "✓ Compiled quicksort"

echo ""
echo "All programs compiled successfully!"
echo ""
echo "Run any program using: ./<program_name>"
echo "Example: ./1_dijkstra"
