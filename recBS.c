#include<stdio.h> // Include the standard input/output library for C

/*
Function: recBS
Input parameters:
- arr[]: The sorted array in which to search for the element
- low: The starting index of the array
- high: The ending index of the array
- x: The element to search for in the array

Return value:
- The index of the element if found, otherwise -1

Description:
This function performs a recursive binary search on a sorted array to find the index of a given element.
It starts by checking if the low index is greater than or equal to the high index.
If so, it checks if the low index equals the high index and if the element at that index equals the searched element.
If both conditions are true, it returns the low index. If not, it returns -1.
If the low index is less than the high index, it calculates the middle index and checks the element at that index.
If the element is equal to the searched element, it returns the middle index.
If the searched element is less than the element at the middle index, it recursively calls the function with the left half of the array.
If the searched element is greater than the element at the middle index, it recursively calls the function with the right half of the array.
*/
int recBS(int arr[], int low, int high, int x)
{
    if(low >= high) // Check if the low index is greater than or equal to the high index ie. no or one element.
    {
        if (low == high) // Check if the low index equals the high index
        {
            if(x == arr[low]) // Check if the element at the low index equals the searched element
            {
                return low; // Return the low index
            }
            else
            {
                return -1; // Return -1 if the element is not found
            }
        }
    }
    else
    {
        int mid = low + (high-low)/2; // Calculate the middle index
        if(arr[mid] == x) // Check if the element at the middle index equals the searched element
        {
            return mid; // Return the middle index
        }
        else if(x < arr[mid]) // Check if the searched element is less than the element at the middle index
        {
            recBS(arr, low, mid-1, x); // Recursively call the function with the left half of the array
        }
        else
        {
            recBS(arr, mid+1, high, x); // Recursively call the function with the right half of the array
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 7, 8, 10, 21, 22, 45, 64, 87}; // Define the sorted array
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int x;

    // Request user input for the element to search for
    printf("Enter the Number to search: ");
    scanf("%d", &x);

    /*
    Call the recursive binary search function and store the result in the res variable.
    If the result is -1, print that the element is not present in the array.
    Otherwise, print that the element is found at the index stored in the res variable.
    */
    int res = recBS(arr, 0, size-1,x);

    if (res == -1)
    {
        printf("Element is not present in array\n");
    }
    else
    {
        printf("Element %d is found at index %d\n", x, res); // Print the index where the element is found
    }

    return 0;
}