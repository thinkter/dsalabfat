/*
 * Singly Linked List Implementation
 * 
 * Pseudocode for Creation:
 * 1. Define a structure Node with:
 *    - data field to store value
 *    - next pointer to point to next node
 * 2. Initialize head pointer to NULL
 * 
 * Pseudocode for Insertion at Beginning:
 * 1. Create a new node
 * 2. Assign data to the new node
 * 3. Set new node's next to current head
 * 4. Update head to point to new node
 * 
 * Pseudocode for Insertion at End:
 * 1. Create a new node
 * 2. Assign data to the new node
 * 3. Set new node's next to NULL
 * 4. If list is empty, set head to new node
 * 5. Else, traverse to last node and set its next to new node
 * 
 * Pseudocode for Insertion at Position:
 * 1. Create a new node
 * 2. If position is 1, insert at beginning
 * 3. Else, traverse to position-1
 * 4. Set new node's next to current node's next
 * 5. Set current node's next to new node
 * 
 * Pseudocode for Deletion at Beginning:
 * 1. If list is empty, return
 * 2. Store head in temp
 * 3. Move head to next node
 * 4. Free temp
 * 
 * Pseudocode for Deletion at End:
 * 1. If list is empty, return
 * 2. If only one node, free it and set head to NULL
 * 3. Else, traverse to second-last node
 * 4. Free last node
 * 5. Set second-last node's next to NULL
 * 
 * Pseudocode for Deletion by Value:
 * 1. If list is empty, return
 * 2. If head contains value, delete head
 * 3. Else, traverse to find node with value
 * 4. Update previous node's next to skip the node to be deleted
 * 5. Free the node
 * 
 * Time Complexity:
 * - Insertion at beginning: O(1)
 * - Insertion at end: O(n)
 * - Deletion at beginning: O(1)
 * - Deletion at end: O(n)
 * - Search: O(n)
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at beginning\n", data);
    return head;
}

// Function to insert a node at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    // If list is empty
    if (head == NULL) {
        printf("Inserted %d at end (first node)\n", data);
        return newNode;
    }
    
    // Traverse to the last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    printf("Inserted %d at end\n", data);
    return head;
}

// Function to insert a node at a specific position (1-indexed)
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return head;
    }
    
    // If inserting at beginning
    if (position == 1) {
        return insertAtBeginning(head, data);
    }
    
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    // Traverse to position-1
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return head;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d\n", data, position);
    return head;
}

// Function to delete node at the beginning
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return NULL;
    }
    
    struct Node* temp = head;
    head = head->next;
    printf("Deleted %d from beginning\n", temp->data);
    free(temp);
    return head;
}

// Function to delete node at the end
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return NULL;
    }
    
    // If only one node
    if (head->next == NULL) {
        printf("Deleted %d from end\n", head->data);
        free(head);
        return NULL;
    }
    
    // Traverse to second-last node
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    printf("Deleted %d from end\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Function to delete node by value
struct Node* deleteByValue(struct Node* head, int value) {
    if (head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return NULL;
    }
    
    // If head node contains the value
    if (head->data == value) {
        struct Node* temp = head;
        head = head->next;
        printf("Deleted node with value %d\n", value);
        free(temp);
        return head;
    }
    
    // Search for the node to be deleted
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }
    
    if (temp->next == NULL) {
        printf("Value %d not found in list!\n", value);
        return head;
    }
    
    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    printf("Deleted node with value %d\n", value);
    free(nodeToDelete);
    return head;
}

// Function to display the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Linked List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the entire list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function to demonstrate singly linked list operations
int main() {
    struct Node* head = NULL;
    
    printf("=== Singly Linked List Operations ===\n\n");
    
    // Insert operations
    printf("--- Insertion Operations ---\n");
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    display(head);
    
    head = insertAtBeginning(head, 5);
    display(head);
    
    head = insertAtPosition(head, 15, 3);
    display(head);
    
    head = insertAtPosition(head, 25, 5);
    display(head);
    
    printf("\n--- Deletion Operations ---\n");
    head = deleteAtBeginning(head);
    display(head);
    
    head = deleteAtEnd(head);
    display(head);
    
    head = deleteByValue(head, 15);
    display(head);
    
    head = deleteByValue(head, 100);  // Try to delete non-existent value
    display(head);
    
    // Free the list
    printf("\n--- Cleaning Up ---\n");
    freeList(head);
    printf("List freed successfully!\n");
    
    return 0;
}
