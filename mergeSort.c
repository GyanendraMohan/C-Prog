#include<stdio.h>
#include<stdlib.h> 

// merge function takes an array arr and three indices low, mid, and high as input
// it divides the array into two halves, sorts them, and then merges them back together in sorted order
void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1; // calculate the size of the first half
    int n2 = high - mid; // calculate the size of the second half

    int leftArr[n1], rightArr[n2]; // create two temporary arrays to store the two halves

    // copy the elements of the first half into the leftArr
    for(int i = 0; i < n1 ; i++) {
        leftArr[i] = arr[low+i];
    }
    // copy the elements of the second half into the rightArr
    for (int j = 0; j < n2 ; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0, j= 0, k = low; // initialize three indices i, j, and k
    while(i < n1 && j < n2) { // while both halves have elements left
        if(leftArr[i] <= rightArr[j]) { // if the current element in leftArr is smaller
            arr[k] = leftArr[i]; // copy it to the current position in arr
            i++; // move to the next element in leftArr
        }
        else { // otherwise
            arr[k] = rightArr[j]; // copy the current element in rightArr to arr
            j++; // move to the next element in rightArr
        }
        k++; // move to the next position in arr
    }

    // copy any remaining elements from leftArr to arr
    while(i<n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // copy any remaining elements from rightArr to arr
    while(j<n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// mergeSort function takes an array arr and two indices low and high as input
// it recursively divides the array into smaller subarrays and sorts them using the merge function
void mergeSort(int arr[], int low, int high) {
    printf("%d", low); // print the current index being processed
    if(low<high) { // if the array has more than one element
        int mid = low + (high - low) / 2; // calculate the middle index
        mergeSort(arr, low, mid); // recursively sort the first half
        mergeSort(arr, mid+1, high); // recursively sort the second half
        merge(arr, low, mid, high); // merge the two halves
    }
}

// displayArray function takes an array arr and an integer length as input
// it prints the elements of the array on a single line
void displayArray(int arr[], int length) {
    for(int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// main function initializes an array arr with some values, calculates its length, and then calls the mergeSort function to sort the array
// finally, it prints the sorted array
int main() {
    int arr[] = {4,15,10,8,7,8,1,2}; // initialize the array
    int length = sizeof(arr) / sizeof(arr[0]); // calculate the length of the array
    printf("Intitial Array is \n");
    displayArray(arr, length); // print the initial array
    mergeSort(arr, 0, length-1); // sort the array
    printf("\nThe sorted array is: \n");
    displayArray(arr, length); // print the sorted array

    return 0;
}