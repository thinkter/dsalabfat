/*
 * Binary Search Tree (BST) Implementation
 * 
 * Pseudocode for Insert:
 * 1. If tree is empty, create new node as root
 * 2. If value is less than current node, go to left subtree
 * 3. If value is greater than current node, go to right subtree
 * 4. Repeat until we find an empty spot and insert the node
 * 
 * Pseudocode for Search:
 * 1. If root is NULL or root's data equals the key, return root
 * 2. If key is less than root's data, search in left subtree
 * 3. If key is greater than root's data, search in right subtree
 * 
 * Pseudocode for Delete:
 * 1. If node to be deleted is leaf node, simply remove it
 * 2. If node has one child, replace node with its child
 * 3. If node has two children, find inorder successor (smallest in right subtree)
 *    and replace node's data with it, then delete the inorder successor
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a node in BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new BST node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node with given data in BST
struct Node* insert(struct Node* root, int data) {
    // If tree is empty, create root node
    if (root == NULL) {
        return createNode(data);
    }
    
    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    // Return the unchanged node pointer
    return root;
}

// Function to search for a key in BST
struct Node* search(struct Node* root, int key) {
    // Base cases: root is null or key is present at root
    if (root == NULL || root->data == key) {
        return root;
    }
    
    // Key is greater than root's data, search in right subtree
    if (key > root->data) {
        return search(root->right, key);
    }
    
    // Key is smaller than root's data, search in left subtree
    return search(root->left, key);
}

// Function to find the minimum value node in a tree
struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    
    // Loop down to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }
    
    return current;
}

// Function to delete a node from BST
struct Node* deleteNode(struct Node* root, int key) {
    // Base case: empty tree
    if (root == NULL) {
        return root;
    }
    
    // Recur down the tree
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Node with two children: Get the inorder successor
        // (smallest in the right subtree)
        struct Node* temp = findMin(root->right);
        
        // Copy the inorder successor's content to this node
        root->data = temp->data;
        
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    
    return root;
}

// Function for inorder traversal of BST (gives sorted order)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function for preorder traversal of BST
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function for postorder traversal of BST
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Driver program to test BST operations
int main() {
    struct Node* root = NULL;
    
    printf("Binary Search Tree (BST) Implementation\n");
    printf("========================================\n\n");
    
    // Insert nodes
    printf("Inserting nodes: 50, 30, 20, 40, 70, 60, 80\n");
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    
    printf("\nInorder traversal (sorted): ");
    inorder(root);
    
    printf("\nPreorder traversal: ");
    preorder(root);
    
    printf("\nPostorder traversal: ");
    postorder(root);
    
    // Search for a key
    int key = 40;
    printf("\n\nSearching for %d: ", key);
    struct Node* found = search(root, key);
    if (found != NULL) {
        printf("Found!\n");
    } else {
        printf("Not found!\n");
    }
    
    // Delete a node
    printf("\nDeleting node 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal after deletion: ");
    inorder(root);
    
    printf("\n\nDeleting node 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal after deletion: ");
    inorder(root);
    
    printf("\n\nDeleting node 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal after deletion: ");
    inorder(root);
    
    printf("\n");
    
    return 0;
}
