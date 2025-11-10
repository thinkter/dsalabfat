#!/bin/bash
# Script to compile all C programs

echo "Compiling all programs..."
echo ""

# Compile each program
gcc -o 1_dijkstra 1_dijkstra.c && echo "✓ Compiled 1_dijkstra"
gcc -o 2_prims 2_prims.c && echo "✓ Compiled 2_prims"
gcc -o 3_kruskal 3_kruskal.c && echo "✓ Compiled 3_kruskal"
gcc -o 4_bfs 4_bfs.c && echo "✓ Compiled 4_bfs"
gcc -o 5_dfs 5_dfs.c && echo "✓ Compiled 5_dfs"
gcc -o 6_bst 6_bst.c && echo "✓ Compiled 6_bst"
gcc -o 7_binary_tree_traversal 7_binary_tree_traversal.c && echo "✓ Compiled 7_binary_tree_traversal"
gcc -o 8_binary_search 8_binary_search.c && echo "✓ Compiled 8_binary_search"
gcc -o 9_linear_search 9_linear_search.c && echo "✓ Compiled 9_linear_search"

echo ""
echo "All programs compiled successfully!"
echo ""
echo "Run any program using: ./<program_name>"
echo "Example: ./1_dijkstra"
