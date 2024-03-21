#include <stdio.h> /* Include the standard input/output library */
#include <stdlib.h> /* Include the standard library for memory allocation and other functions */

/*
Binary Search algorithm to find the element x
in a sorted array.

Parameters:
arr[]: The sorted array to search in.
low: The starting index of the array.
high: The ending index of the array.
x: The element to search for.

Returns:
The index where the element is found,
or -1 if the element is not present in the array.
*/

int straightBS(int arr[], int low, int high, int x) {
    while (low <= high) { /* Loop until the low index is greater than the high index */
        int mid = low + (high - low) / 2; /* Calculate the middle index of the current subarray */
        printf("%d\n", arr[mid]); // Debugging purposes
        if (x < arr[mid]) { /* If the element is less than the middle element */
            high = mid - 1; /* Set the high index to the middle index minus one */
        } else if (x > arr[mid]) { /* If the element is greater than the middle element */
            low = mid + 1; /* Set the low index to the middle index plus one */
        } else {
            return mid; /* If the element is equal to the middle element, return the middle index */
        }
    }
    return -1; /* If the element is not found, return -1 */
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 7, 8, 10, 21, 22, 45, 64, 87}; /* Define the sorted array */
    int size = sizeof(arr) / sizeof(arr[0]); /* Calculate the size of the array */
    int x;

    // Request user input for the element to search for
    printf("Enter the Number to search: ");
    scanf("%d", &x);

    // Call the straight binary search algorithm
    int res = straightBS(arr, 0, size - 1, x);

    if (res == -1) {
        printf("Element is not present in array\n");
    } else {
        printf("Element %d is found at index %d\n", x, res); // Print the index where the element is found
    }

    return 0;
}