/*
 * Doubly Linked List Implementation
 * 
 * Pseudocode for Creation:
 * 1. Define a structure Node with:
 *    - data field to store value
 *    - next pointer to point to next node
 *    - prev pointer to point to previous node
 * 2. Initialize head pointer to NULL
 * 
 * Pseudocode for Insertion at Beginning:
 * 1. Create a new node
 * 2. Assign data to the new node
 * 3. Set new node's prev to NULL
 * 4. Set new node's next to current head
 * 5. If head is not NULL, set head's prev to new node
 * 6. Update head to point to new node
 * 
 * Pseudocode for Insertion at End:
 * 1. Create a new node
 * 2. Assign data to the new node
 * 3. Set new node's next to NULL
 * 4. If list is empty, set prev to NULL and head to new node
 * 5. Else, traverse to last node
 * 6. Set last node's next to new node
 * 7. Set new node's prev to last node
 * 
 * Pseudocode for Insertion at Position:
 * 1. Create a new node
 * 2. If position is 1, insert at beginning
 * 3. Else, traverse to position-1
 * 4. Set new node's next to current node's next
 * 5. Set new node's prev to current node
 * 6. If current node's next is not NULL, set its prev to new node
 * 7. Set current node's next to new node
 * 
 * Pseudocode for Deletion at Beginning:
 * 1. If list is empty, return
 * 2. Store head in temp
 * 3. Move head to next node
 * 4. If head is not NULL, set head's prev to NULL
 * 5. Free temp
 * 
 * Pseudocode for Deletion at End:
 * 1. If list is empty, return
 * 2. If only one node, free it and set head to NULL
 * 3. Else, traverse to last node
 * 4. Set second-last node's next to NULL
 * 5. Free last node
 * 
 * Pseudocode for Deletion by Value:
 * 1. If list is empty, return
 * 2. Traverse to find node with value
 * 3. If node is head, update head to next node
 * 4. If node is not head, set previous node's next to current node's next
 * 5. If node is not last, set next node's prev to current node's prev
 * 6. Free the node
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

// Define the structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
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
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
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
    newNode->prev = temp;
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
    newNode->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    
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
    
    if (head != NULL) {
        head->prev = NULL;
    }
    
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
    
    // Traverse to last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->prev->next = NULL;
    printf("Deleted %d from end\n", temp->data);
    free(temp);
    return head;
}

// Function to delete node by value
struct Node* deleteByValue(struct Node* head, int value) {
    if (head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return NULL;
    }
    
    struct Node* temp = head;
    
    // Search for the node to be deleted
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Value %d not found in list!\n", value);
        return head;
    }
    
    // If node to be deleted is head
    if (temp == head) {
        head = head->next;
    }
    
    // Update next node's prev pointer
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    // Update previous node's next pointer
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    
    printf("Deleted node with value %d\n", value);
    free(temp);
    return head;
}

// Function to display the linked list (forward)
void displayForward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Forward: NULL <- ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

// Function to display the linked list (backward)
void displayBackward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    // Traverse to the last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    printf("Backward: NULL <- ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->prev != NULL) {
            printf(" <-> ");
        }
        temp = temp->prev;
    }
    printf(" -> NULL\n");
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

// Main function to demonstrate doubly linked list operations
int main() {
    struct Node* head = NULL;
    
    printf("=== Doubly Linked List Operations ===\n\n");
    
    // Insert operations
    printf("--- Insertion Operations ---\n");
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    displayForward(head);
    displayBackward(head);
    
    head = insertAtBeginning(head, 5);
    displayForward(head);
    
    head = insertAtPosition(head, 15, 3);
    displayForward(head);
    
    head = insertAtPosition(head, 25, 5);
    displayForward(head);
    displayBackward(head);
    
    printf("\n--- Deletion Operations ---\n");
    head = deleteAtBeginning(head);
    displayForward(head);
    
    head = deleteAtEnd(head);
    displayForward(head);
    
    head = deleteByValue(head, 15);
    displayForward(head);
    displayBackward(head);
    
    head = deleteByValue(head, 100);  // Try to delete non-existent value
    displayForward(head);
    
    // Free the list
    printf("\n--- Cleaning Up ---\n");
    freeList(head);
    printf("List freed successfully!\n");
    
    return 0;
}
