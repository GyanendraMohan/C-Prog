#include <stdio.h>  // Include the standard input/output library for C
#include <stdlib.h>  // Include the standard library for C

/**
 * straightBS() function is a recursive binary search algorithm that finds the first occurrence of a given element in a sorted array and counts its occurrences.
 * 
 * @param arr[]: The sorted array to search in.
 * @param low: The starting index of the array.
 * @param high: The ending index of the array.
 * @param x: The element to search for.
 * @param count: A pointer to an integer variable that will store the number of occurrences of the element.
 * 
 * @return mid: The index of the found element, or -1 if the element is not found.
 */
int straightBS(int arr[], int low, int high, int x, int *count) {
    while (low <= high) {  // Continue searching until the low index is greater than the high index
        int mid = low + (high - low) / 2;  // Calculate the middle index of the current search range
        if (x < arr[mid]) {  // If the element is less than the middle element, search the left half
            high = mid - 1;  // Update the high index to search the left half
        } else if (x > arr[mid]) {  // If the element is greater than the middle element, search the right half
            low = mid + 1;  // Update the low index to search the right half
        } else {
            // Found the element, now count its occurrences
            int temp_count = 1;  // Initialize a temporary count variable
            int left = mid - 1;  // Initialize the left index to search for previous occurrences
            while (left >= low && arr[left] == x) {  // Search for previous occurrences
                temp_count++;  // Increment the temporary count
                left--;  // Move to the previous index
            }
            int right = mid + 1;  // Initialize the right index to search for subsequent occurrences
            while (right <= high && arr[right] == x) {  // Search for subsequent occurrences
                temp_count++;  // Increment the temporary count
                right++;  // Move to the next index
            }
            *count = temp_count;  // Store the total count in the count parameter

            // Find the first occurrence
            while (mid > low && arr[mid - 1] == x) {
                mid--;
            }

            return mid;  // Return the index of the found element
        }
    }
    *count = 0; // Element not found, set the count to 0
    return -1;  // Return -1 to indicate that the element was not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 4, 8, 21, 21, 21, 64, 87};  // Define the sorted array
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array
    int x;
    int occurrences;  // Declare a variable to store the number of occurrences

    // Request user input for the element to search for
    printf("Enter the Number to search: ");
    scanf("%d", &x);

    // Call the straightBS() function and store the result
    int res = straightBS(arr, 0, size - 1, x, &occurrences);

    if (res == -1) {  // If the element was not found
        printf("Element is not present in array\n");  // Print an error message
    } else {
        printf("Element %d is found at index %d and appears %d times in the array\n", x, res, occurrences);  // Print the result
    }

    return 0;  // Return 0 to indicate successful execution
}