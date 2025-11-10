/*
 * Queue Implementation Using Array
 * 
 * Pseudocode for Creation:
 * 1. Define maximum size MAX_SIZE for queue
 * 2. Create an array of size MAX_SIZE
 * 3. Initialize front = -1 and rear = -1 (indicates empty queue)
 * 
 * Pseudocode for Enqueue (Insertion):
 * 1. Check if queue is full (rear == MAX_SIZE - 1)
 * 2. If full, display overflow message and return
 * 3. If queue is empty (front == -1), set front = 0
 * 4. Increment rear
 * 5. Insert element at queue[rear]
 * 
 * Pseudocode for Dequeue (Deletion):
 * 1. Check if queue is empty (front == -1 or front > rear)
 * 2. If empty, display underflow message and return
 * 3. Get element from queue[front]
 * 4. If front == rear (only one element), reset front = -1 and rear = -1
 * 5. Else, increment front
 * 6. Return the element
 * 
 * Pseudocode for Peek (Front element):
 * 1. Check if queue is empty (front == -1 or front > rear)
 * 2. If empty, display message and return
 * 3. Else, return queue[front]
 * 
 * Pseudocode for isEmpty:
 * 1. If front == -1 or front > rear, return true
 * 2. Else, return false
 * 
 * Pseudocode for isFull:
 * 1. If rear == MAX_SIZE - 1, return true
 * 2. Else, return false
 * 
 * Time Complexity:
 * - Enqueue: O(1)
 * - Dequeue: O(1)
 * - Peek: O(1)
 * - isEmpty: O(1)
 * - isFull: O(1)
 * 
 * Space Complexity: O(n) where n is MAX_SIZE
 * 
 * Note: This is a simple linear queue. Once rear reaches MAX_SIZE-1,
 * no more elements can be added even if there's space at the beginning.
 * For better space utilization, use a circular queue.
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Queue structure
struct Queue {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

// Function to initialize the queue
void initQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if queue is empty
bool isEmpty(struct Queue* queue) {
    return queue->front == -1 || queue->front > queue->rear;
}

// Function to check if queue is full
bool isFull(struct Queue* queue) {
    return queue->rear == MAX_SIZE - 1;
}

// Function to enqueue (add) an element to the queue
void enqueue(struct Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue Overflow! Cannot enqueue %d\n", data);
        return;
    }
    
    // If queue is empty, set front to 0
    if (queue->front == -1) {
        queue->front = 0;
    }
    
    queue->rear++;
    queue->arr[queue->rear] = data;
    printf("Enqueued %d to queue\n", data);
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow! Cannot dequeue from empty queue\n");
        return -1;
    }
    
    int data = queue->arr[queue->front];
    
    // If this was the last element, reset the queue
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    
    printf("Dequeued %d from queue\n", data);
    return data;
}

// Function to peek at the front element without removing it
int peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! No front element\n");
        return -1;
    }
    
    return queue->arr[queue->front];
}

// Function to get the current size of the queue
int size(struct Queue* queue) {
    if (isEmpty(queue)) {
        return 0;
    }
    return queue->rear - queue->front + 1;
}

// Function to display all elements in the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Queue (front to rear): ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

// Main function to demonstrate queue operations
int main() {
    struct Queue queue;
    initQueue(&queue);
    
    printf("=== Queue Operations Using Array ===\n\n");
    
    // Enqueue operations
    printf("--- Enqueue Operations ---\n");
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);
    display(&queue);
    
    printf("\nQueue size: %d\n", size(&queue));
    printf("Front element: %d\n", peek(&queue));
    
    // Dequeue operations
    printf("\n--- Dequeue Operations ---\n");
    dequeue(&queue);
    dequeue(&queue);
    display(&queue);
    
    printf("\nQueue size: %d\n", size(&queue));
    printf("Front element: %d\n", peek(&queue));
    
    // More enqueue operations
    printf("\n--- More Enqueue Operations ---\n");
    enqueue(&queue, 60);
    enqueue(&queue, 70);
    display(&queue);
    
    // Check if empty or full
    printf("\n--- Queue Status ---\n");
    printf("Is queue empty? %s\n", isEmpty(&queue) ? "Yes" : "No");
    printf("Is queue full? %s\n", isFull(&queue) ? "Yes" : "No");
    
    // Dequeue all elements
    printf("\n--- Dequeuing All Elements ---\n");
    while (!isEmpty(&queue)) {
        dequeue(&queue);
    }
    display(&queue);
    
    // Try to dequeue from empty queue
    printf("\n--- Testing Underflow ---\n");
    dequeue(&queue);
    
    printf("\nIs queue empty? %s\n", isEmpty(&queue) ? "Yes" : "No");
    
    // Add elements again to show queue resets properly
    printf("\n--- Adding Elements Again ---\n");
    enqueue(&queue, 100);
    enqueue(&queue, 200);
    display(&queue);
    
    return 0;
}
