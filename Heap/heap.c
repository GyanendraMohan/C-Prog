#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

/*
 * Insert a new element into the heap
 *
 * Parameters:
 * - arr: array of heap elements
 * - size: pointer to the current size of the heap
 * - x: the new element to insert
 *
 * Return: nothing
 */
void insert(int arr[], int *size, int x) {
    if (*size >= MAX_HEAP_SIZE) {
        // Check if the heap is full
        printf("Heap overflow!\n");
        return;
    }

    int item = x;
    int i = *size++;
    // Bubble up the new element to the correct position in the heap
    while (i > 0 && item > arr[(i - 1) / 2]) {
        arr[i] = arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    arr[i] = item;
}

/*
 * Delete and return the maximum element from the heap
 *
 * Parameters:
 * - arr: array of heap elements
 * - size: pointer to the current size of the heap
 *
 * Return: the maximum element
 */
int deleteMax(int arr[], int *size) {
    if (*size <= 0) {
        // Check if the heap is empty
        printf("Heap underflow!\n");
        return -1;
    }

    int max = arr[0];
    int lastItem = arr[--(*size)];
    int i = 0;
    int child;
    // Bubble down the last element to the correct position in the heap
    while ((2 * i) + 1 < *size) {
        child = (2 * i) + 1;
        if (child + 1 < *size && arr[child + 1] > arr[child]) {
            child++;
        }
        if (lastItem < arr[child]) {
            arr[i] = arr[child];
        } else {
            break;
        }
        i = child;
    }
    arr[i] = lastItem;
    return max;
}

/*
 * Print the current state of the heap
 *
 * Parameters:
 * - arr: array of heap elements
 * - size: current size of the heap
 *
 * Return: nothing
 */
void print_heap(int arr[], int size) {
    printf("Heap items are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Initialize the heap array and its size
    int arr[MAX_HEAP_SIZE];
    int size = 0;

    // Insert new elements into the heap
    char choice;
    int x;
    do {
        printf("Enter the element to insert in Heap: ");
        scanf("%d", &x);
        insert(arr, &size, x);
        print_heap(arr, size);

        printf("Do you want to insert another element? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // Delete and print the maximum element from the heap
    printf("\nDeleting max elements:\n");
    while (size > 0) {
        int max = deleteMax(arr, &size);
        printf("Deleted max element: %d\n", max);
        print_heap(arr, size);
    }

    // Exit the main function
    return 0;
}