#include <stdio.h>
#include <stdlib.h>

// Utility function to swap two elements
void swap(int* a, int* b) {
    // Swap the values of 'a' and 'b'
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for QuickSelect
int partition(int arr[], int left, int right, int pivot) {
    // left and right pointers move towards each other while elements are misplaced
    while (left <= right) {
        // Move left pointer till the element is smaller than or equal to pivot
        while (arr[left] < pivot) left++;

        // Move right pointer till the element is greater than pivot
        while (arr[right] > pivot) right--;

        // Swap the misplaced elements
        if (left <= right) {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }

    // Returns the position of the pivot element
    return left;
}

// QuickSelect function
int quickSelect(int arr[], int left, int right, int k) {
    // left and right pointers move towards each other while elements are misplaced
    while (left < right) {
        int pivotIndex = left + (right - left) / 2;
        int pivot = arr[pivotIndex];

        // Partition the array around the pivot
        int partitionIndex = partition(arr, left, right, pivot);

        // Adjust the pointers based on the partition
        if (partitionIndex <= k)
            left = partitionIndex;
        else
            right = partitionIndex - 1;
    }

    // Returns the kth smallest element
    return arr[k];
}

// Function to find median of medians
int medianOfMedians(int arr[], int n) {
    if (n < 5) {
        // Just select median directly if size is less than 5
        return quickSelect(arr, 0, n - 1, n / 2);
    }

    // Store medians of sublists of size 5
    int *M = (int *)malloc((n / 5) * sizeof(int));

    // Find medians of sublists
    for (int i = 0; i < n / 5; i++) {
        M[i] = quickSelect(arr, i * 5, i * 5 + 4, 2); // 2 because we are finding median of 5 elements
    }

    // Find median of medians
    int medianOfMeds = medianOfMedians(M, n / 5);

    // Use median of medians as pivot for QuickSelect
    int pivotIndex = partition(arr, 0, n - 1, medianOfMeds);

    // Determine which partition to recurse into
    if (pivotIndex == n / 2) {
        return arr[pivotIndex];
    } else if (pivotIndex < n / 2) {
        return quickSelect(arr, pivotIndex + 1, n - 1, n / 2);
    } else {
        return quickSelect(arr, 0, pivotIndex - 1, n / 2);
    }
}

int main() {
    int arr[] = {10, 8, 2, 6, 15, 13, 12, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find the median of the array
    int median = medianOfMedians(arr, n - 1);

    // Print the median
    printf("Median: %d\n", median);

    return 0;
}