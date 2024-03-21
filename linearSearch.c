#include<stdio.h>
#include<stdlib.h>

/* 
    Function: linearSearch
    Parameters:
        arr[] - array of integers
        size - size of the array
        x - integer to search for in the array
    Returns:
        index of the element if found, -1 otherwise

        Best case time complexity : theta(1)
        Worst Case time complexity : theta(n)
        Average case = (1+2+3+4+5 ........... + n) / n ==> n(n+1) / 2n ==> (n+1)/2 ==> theta(n)
*/
int linearSearch(int arr[], int size, int x)
{
    for (int i = 0; i <= size; i++) // iterate through the array
    {
        if(x == arr[i]) // check if the current element is the one we're looking for
            return i; // return the index if found
    }
    return -1; // return -1 if the element is not found
}

int main()
{
    int arr[] = {1,8,6,9,4,7,99,77,45,21,12}; // initialize the array
    int x; // declare variable to store the element to search for
    printf("\nEnter the element to Search: ");
    scanf("%d", &x); // get the element to search for from the user
    int size = sizeof(arr)/sizeof(arr[0]); // calculate the size of the array
    int res = linearSearch(arr, size-1, x); // call the linear search function
    if(res == -1) // check if the element was not found
    {
        printf("Not found");
    }
    else // print the index of the element if it was found
    {
        printf("Element %d is Found at index %d: ", x, res);
    }
    return 0;
}