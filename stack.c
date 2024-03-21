#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 4

int stack[MAX_SIZE]; // Global array to hold stack elements
int top = -1; // Global variable to keep track of the top element index

// Function to push an element onto the stack
void push(int element) {
    // Check if stack is full
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    // Increment top and add the element to the stack
    top++;
    stack[top] = element;
    printf("Element %d pushed onto the stack.\n", element);
}

// Function to pop an element from the stack
int pop() {
    // Check if stack is empty
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1); // Terminate program in case of underflow
    }
    // Retrieve the top element and decrement top
    int element = stack[top];
    top--;
    return element;
}

// Function to check if stack is empty
int isEmpty() {
    return top == -1;
}

// Function to return the top element of the stack without popping it
int peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack[top];
}

// Function to print all elements of the stack
void printStack() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, item;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Check if Empty\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                if (!isEmpty())
                    printf("Popped element: %d\n", pop());
                break;
            case 3:
                if (!isEmpty())
                    printf("Top element: %d\n", peek());
                break;
            case 4:
                printf("Is stack empty? %s\n", isEmpty() ? "Yes" : "No");
                break;
            case 5:
                printStack();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
