/*
 * Binary Tree Traversal Methods
 * 
 * Pseudocode for Inorder Traversal (Left-Root-Right):
 * 1. Traverse the left subtree recursively
 * 2. Visit the root node
 * 3. Traverse the right subtree recursively
 * 
 * Pseudocode for Preorder Traversal (Root-Left-Right):
 * 1. Visit the root node
 * 2. Traverse the left subtree recursively
 * 3. Traverse the right subtree recursively
 * 
 * Pseudocode for Postorder Traversal (Left-Right-Root):
 * 1. Traverse the left subtree recursively
 * 2. Traverse the right subtree recursively
 * 3. Visit the root node
 * 
 * Pseudocode for Level Order Traversal (BFS):
 * 1. Create a queue and enqueue root
 * 2. While queue is not empty:
 *    a. Dequeue a node and visit it
 *    b. Enqueue its left child (if exists)
 *    c. Enqueue its right child (if exists)
 */

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new tree node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Inorder traversal: Left -> Root -> Right
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);   // Visit left subtree
        printf("%d ", root->data);       // Visit root
        inorderTraversal(root->right);  // Visit right subtree
    }
}

// Preorder traversal: Root -> Left -> Right
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);       // Visit root
        preorderTraversal(root->left);   // Visit left subtree
        preorderTraversal(root->right);  // Visit right subtree
    }
}

// Postorder traversal: Left -> Right -> Root
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);   // Visit left subtree
        postorderTraversal(root->right);  // Visit right subtree
        printf("%d ", root->data);        // Visit root
    }
}

// Function to get height of the tree
int height(struct Node* node) {
    if (node == NULL)
        return 0;
    
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to print nodes at a given level
void printLevel(struct Node* root, int level) {
    if (root == NULL)
        return;
    
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

// Level order traversal (Breadth First Search)
void levelOrderTraversal(struct Node* root) {
    int h = height(root);
    
    for (int i = 1; i <= h; i++) {
        printLevel(root, i);
    }
}

// Driver program to test tree traversal methods
int main() {
    /* Create the following binary tree:
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
    */
    
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    printf("Binary Tree Traversal Methods\n");
    printf("==============================\n\n");
    
    printf("Tree structure:\n");
    printf("       1\n");
    printf("      / \\\n");
    printf("     2   3\n");
    printf("    / \\ / \\\n");
    printf("   4  5 6  7\n\n");
    
    printf("Inorder traversal (Left-Root-Right): ");
    inorderTraversal(root);
    printf("\n");
    
    printf("Preorder traversal (Root-Left-Right): ");
    preorderTraversal(root);
    printf("\n");
    
    printf("Postorder traversal (Left-Right-Root): ");
    postorderTraversal(root);
    printf("\n");
    
    printf("Level order traversal (BFS): ");
    levelOrderTraversal(root);
    printf("\n");
    
    return 0;
}
