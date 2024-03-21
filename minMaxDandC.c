#include <stdio.h>

/*
Function: findMinMax
Purpose: Find the minimum and maximum values in an array of integers.
Parameters:
    arr[] - The array of integers to search for the minimum and maximum values.
    low - The starting index of the array to search.
    high - The ending index of the array to search.
    min - A pointer to an integer that will store the minimum value found.
    max - A pointer to an integer that will store the maximum value found.
Notes:
    - The function uses recursion to divide the array into two halves and find the minimum and maximum values in each half.
    - If the array has only one element, the minimum and maximum values are set to that element.
    - If the array has two elements, the minimum and maximum values are set based on the comparison of the two elements.
*/
void findMinMax(int arr[], int low, int high, int *min, int *max) {
    int mid, min1, min2, max1, max2;

    // If there is only one element
    if (low == high) {
        *min = arr[low];
        *max = arr[low];
        return;
    }

    // If there are two elements
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            *max = arr[low];
            *min = arr[high];
        } else {
            *max = arr[high];
            *min = arr[low];
        }
        return;
    }

    // If there are more than two elements
    mid = (low + high) / 2;
    findMinMax(arr, low, mid, &min1, &max1);
    findMinMax(arr, mid + 1, high, &min2, &max2);

    // Compare minimums of two parts
    if (min1 < min2)
        *min = min1;
    else
        *min = min2;

    // Compare maximums of two parts
    if (max1 > max2)
        *max = max1;
    else
        *max = max2;
}

int main() {
    int arr[] = {4,15,10,8,7,8,1,2};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    // Call the findMinMax function to find the minimum and maximum values in the array
    findMinMax(arr, 0, arr_size - 1, &min, &max);

    // Print the minimum and maximum values found
    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}