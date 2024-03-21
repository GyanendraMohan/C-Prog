#include<stdio.h>
#include<stdlib.h>

/*
Function: swap
Purpose: Swap the values of two integers using pointers.
Parameters: Two integer pointers.
Returns: Nothing.
*/
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/*
Function: partition
Purpose: Partition the array around a pivot element and return the index of the pivot element.
Parameters: An integer array, the starting and ending indices of the array partition.
Returns: The index of the pivot element.
*/
int partition(int arr[], int low, int high) {
    int i = low;
    int j = high + 1;
    int pivot = arr[low];  // assuming first element as the pivot

    do {
        do {
            i++;   // increment i until it is greater than the current value of j
        } while(arr[i] < pivot);

        do {
            j--;    // decrement j until it is less than the current value of i
        } while(arr[j] > pivot);

        if(i < j) {
            swap(&arr[i], &arr[j]); // swap the values of arr[i] and arr[j] if arr[i] is less than arr[j]
        }
    } while(i < j);

    swap(&arr[low], &arr[j]);  // swap the pivot element with the value at index j
    return j;  // return the index of the pivot element
}

/*
Function: quicksort
Purpose: Implement the quicksort algorithm to sort an array of integers.
Parameters: An integer array, the starting and ending indices of the array partition.
Returns: Nothing.
*/
void quicksort(int arr[], int low, int high) {
    // If the low index is less than the high index, continue
    if(low < high) {
        // Find the pivot position
        int pos = partition(arr, low, high);
        // Recursively sort elements before the pivot
        quicksort(arr, low, pos-1);
        // Recursively sort elements after the pivot
        quicksort(arr, pos+1, high);
    }
}

/*
Function: displayArray
Purpose: Display the contents of an integer array.
Parameters: An integer array and its length.
Returns: Nothing.
*/
void displayArray(int arr[], int length) {
    for(int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
Function: main
Purpose: Implement the main function to test the quicksort algorithm.
Parameters: None.
Returns: 0 on successful execution.
*/
int main() {
    int arr[] = {60,40,90,75,30,75,20,50,40};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Initial Array is \n");
    displayArray(arr, size); // print the initial array

    quicksort(arr, 0 , size-1);

    printf("\nThe sorted array is: \n");
    displayArray(arr, size); // print the sorted array

    return 0;
}