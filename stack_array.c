/*
 * Stack Implementation Using Array
 * 
 * Pseudocode for Creation:
 * 1. Define maximum size MAX_SIZE for stack
 * 2. Create an array of size MAX_SIZE
 * 3. Initialize top = -1 (indicates empty stack)
 * 
 * Pseudocode for Push (Insertion):
 * 1. Check if stack is full (top == MAX_SIZE - 1)
 * 2. If full, display overflow message and return
 * 3. Else:
 *    a. Increment top
 *    b. Insert element at stack[top]
 * 
 * Pseudocode for Pop (Deletion):
 * 1. Check if stack is empty (top == -1)
 * 2. If empty, display underflow message and return
 * 3. Else:
 *    a. Get element from stack[top]
 *    b. Decrement top
 *    c. Return the element
 * 
 * Pseudocode for Peek (Top element):
 * 1. Check if stack is empty (top == -1)
 * 2. If empty, display message and return
 * 3. Else, return stack[top]
 * 
 * Pseudocode for isEmpty:
 * 1. If top == -1, return true
 * 2. Else, return false
 * 
 * Pseudocode for isFull:
 * 1. If top == MAX_SIZE - 1, return true
 * 2. Else, return false
 * 
 * Time Complexity:
 * - Push: O(1)
 * - Pop: O(1)
 * - Peek: O(1)
 * - isEmpty: O(1)
 * - isFull: O(1)
 * 
 * Space Complexity: O(n) where n is MAX_SIZE
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Stack structure
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if stack is empty
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if stack is full
bool isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", data);
        return;
    }
    
    stack->top++;
    stack->arr[stack->top] = data;
    printf("Pushed %d onto stack\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from empty stack\n");
        return -1;
    }
    
    int data = stack->arr[stack->top];
    stack->top--;
    printf("Popped %d from stack\n", data);
    return data;
}

// Function to peek at the top element without removing it
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! No top element\n");
        return -1;
    }
    
    return stack->arr[stack->top];
}

// Function to get the current size of the stack
int size(struct Stack* stack) {
    return stack->top + 1;
}

// Function to display all elements in the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    
    printf("Stack (top to bottom): ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// Main function to demonstrate stack operations
int main() {
    struct Stack stack;
    initStack(&stack);
    
    printf("=== Stack Operations Using Array ===\n\n");
    
    // Push operations
    printf("--- Push Operations ---\n");
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    display(&stack);
    
    printf("\nStack size: %d\n", size(&stack));
    printf("Top element: %d\n", peek(&stack));
    
    // Pop operations
    printf("\n--- Pop Operations ---\n");
    pop(&stack);
    pop(&stack);
    display(&stack);
    
    printf("\nStack size: %d\n", size(&stack));
    printf("Top element: %d\n", peek(&stack));
    
    // More push operations
    printf("\n--- More Push Operations ---\n");
    push(&stack, 60);
    push(&stack, 70);
    display(&stack);
    
    // Check if empty or full
    printf("\n--- Stack Status ---\n");
    printf("Is stack empty? %s\n", isEmpty(&stack) ? "Yes" : "No");
    printf("Is stack full? %s\n", isFull(&stack) ? "Yes" : "No");
    
    // Pop all elements
    printf("\n--- Popping All Elements ---\n");
    while (!isEmpty(&stack)) {
        pop(&stack);
    }
    display(&stack);
    
    // Try to pop from empty stack
    printf("\n--- Testing Underflow ---\n");
    pop(&stack);
    
    printf("\nIs stack empty? %s\n", isEmpty(&stack) ? "Yes" : "No");
    
    return 0;
}
