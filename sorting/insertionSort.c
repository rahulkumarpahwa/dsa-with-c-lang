#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("a[%d]: %d \n", i, arr[i]);
    }
}

void insertionSort(int *A, int size)
{
    int key; 
    for (int i = 1; i < size; i++)
    { // no. of passes
        printf("No of Passes : %d \n", i);
        key = A[i]; // key start from the 1st index and goes till end.
        int j = i-1; // while j start from the i-1th index and goes till it become -1.
        while (j >= 0 && A[j] > key) 
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

void main()
{
    int arr[] = {1, 3, 2, 4, 6, 5};
    int size = sizeof(arr) / sizeof(int);
    printArray(arr, size);
    insertionSort(arr, size);
    printArray(arr, size);
}