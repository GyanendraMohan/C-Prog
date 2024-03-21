
#include<stdio.h>
#include<stdlib.h>

/*
 * Function: moorsVoting
 * --------------------
 * This function implements Moore's Voting Algorithm to find the majority element
 * in an array. The time complexity of this algorithm is Theta(N).
 *
 * Parameters:
 * ----------
 * int arr[]: array of integers
 * int size: size of the array
 *
 * Returns:
 * -------
 * int: the majority element in the array means occurences or repeat of element > size/2 elements
 */
int moorsVoting(int arr[], int size) {
    int count = 1; // initialize the count of the candidate element
    int candidate = arr[0]; // initialize the candidate element
    printf("%d", arr[0]); // print the first element of the array

    for (int i = 1; i < size; i++) {
        if (arr[i] == candidate) {
            count++; // increment the count if the candidate element is found
        } else {
            count--; // decrement the count if the candidate element is not found
            if (count == 0) {
                candidate = arr[i]; // update the candidate element
                count = 1; // reset the count
            }
        }
    }

    return candidate; // return the majority element
}

/*
 * Function: main
 * --------------
 * This is the main function that calls the moorsVoting function to find the
 * majority element in an array. It also checks if the majority element is
 * actually the majority element by counting its occurrences in the array.
 *
 * Returns:
 * -------
 * int: 0 on successful execution
 */
int main() {
    int arr[] = {1, 2, 2, 7, 8, 8, 9, 8, 8, 10, 8, 8, 8, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int majorityElem = moorsVoting(arr, size);

    int x = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == majorityElem) {
            x = x + 1; // increment the count of the majority element
        }
        if (x > (size / 2)) {
            printf("Majority element is %d\n", majorityElem); // print the majority element
            break;
        }
    }

    if (x <= (size / 2)) {
        printf("No Majority Element found\n"); // print if no majority element is found
    }

    return 0;
}