/*
 * Circular Linked List Implementation
 * 
 * Pseudocode for Creation:
 * 1. Define a structure Node with:
 *    - data field to store value
 *    - next pointer to point to next node
 * 2. Initialize head pointer to NULL
 * 3. In circular list, last node points back to head
 * 
 * Pseudocode for Insertion at Beginning:
 * 1. Create a new node
 * 2. Assign data to the new node
 * 3. If list is empty, set new node's next to itself and head to new node
 * 4. Else:
 *    a. Find last node (node whose next is head)
 *    b. Set new node's next to head
 *    c. Set last node's next to new node
 *    d. Update head to new node
 * 
 * Pseudocode for Insertion at End:
 * 1. Create a new node
 * 2. Assign data to the new node
 * 3. If list is empty, set new node's next to itself and head to new node
 * 4. Else:
 *    a. Find last node (node whose next is head)
 *    b. Set new node's next to head
 *    c. Set last node's next to new node
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
 * 2. If only one node, free it and set head to NULL
 * 3. Else:
 *    a. Find last node
 *    b. Set last node's next to head's next
 *    c. Store head in temp
 *    d. Update head to head's next
 *    e. Free temp
 * 
 * Pseudocode for Deletion at End:
 * 1. If list is empty, return
 * 2. If only one node, free it and set head to NULL
 * 3. Else:
 *    a. Traverse to second-last node
 *    b. Free last node
 *    c. Set second-last node's next to head
 * 
 * Pseudocode for Deletion by Value:
 * 1. If list is empty, return
 * 2. If head contains value:
 *    a. Delete at beginning
 * 3. Else:
 *    a. Traverse to find node with value
 *    b. Set previous node's next to current node's next
 *    c. Free the node
 * 
 * Time Complexity:
 * - Insertion at beginning: O(n) - need to find last node
 * - Insertion at end: O(n) - need to traverse to last node
 * - Deletion at beginning: O(n) - need to find last node
 * - Deletion at end: O(n) - need to traverse to last node
 * - Search: O(n)
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
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
    
    // If list is empty
    if (head == NULL) {
        newNode->next = newNode;  // Point to itself
        printf("Inserted %d at beginning (first node)\n", data);
        return newNode;
    }
    
    // Find the last node
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    
    newNode->next = head;
    temp->next = newNode;
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
        newNode->next = newNode;  // Point to itself
        printf("Inserted %d at end (first node)\n", data);
        return newNode;
    }
    
    // Find the last node
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->next = head;
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
    
    if (head == NULL) {
        printf("List is empty! Cannot insert at position %d\n", position);
        return head;
    }
    
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    // Traverse to position-1
    struct Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
        if (temp == head) {
            printf("Position out of range!\n");
            free(newNode);
            return head;
        }
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
    
    // If only one node
    if (head->next == head) {
        printf("Deleted %d from beginning\n", head->data);
        free(head);
        return NULL;
    }
    
    // Find the last node
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    
    struct Node* toDelete = head;
    temp->next = head->next;
    head = head->next;
    printf("Deleted %d from beginning\n", toDelete->data);
    free(toDelete);
    return head;
}

// Function to delete node at the end
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return NULL;
    }
    
    // If only one node
    if (head->next == head) {
        printf("Deleted %d from end\n", head->data);
        free(head);
        return NULL;
    }
    
    // Traverse to second-last node
    struct Node* temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }
    
    struct Node* toDelete = temp->next;
    temp->next = head;
    printf("Deleted %d from end\n", toDelete->data);
    free(toDelete);
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
        return deleteAtBeginning(head);
    }
    
    // Search for the node to be deleted
    struct Node* temp = head;
    while (temp->next != head && temp->next->data != value) {
        temp = temp->next;
    }
    
    if (temp->next == head) {
        printf("Value %d not found in list!\n", value);
        return head;
    }
    
    struct Node* toDelete = temp->next;
    temp->next = temp->next->next;
    printf("Deleted node with value %d\n", value);
    free(toDelete);
    return head;
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Circular Linked List: ");
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to %d)\n", head->data);
}

// Function to free the entire list
void freeList(struct Node* head) {
    if (head == NULL) return;
    
    struct Node* temp = head;
    struct Node* next;
    
    // Break the circular link
    do {
        next = temp->next;
        free(temp);
        temp = next;
    } while (temp != head);
}

// Main function to demonstrate circular linked list operations
int main() {
    struct Node* head = NULL;
    
    printf("=== Circular Linked List Operations ===\n\n");
    
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
