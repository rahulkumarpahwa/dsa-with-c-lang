#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("a[%d]: %d \n", i, arr[i]);
    }
    printf("\n");
}

int merge(int A[], int low, int mid, int high)
{

    int i = low;
    int j = mid + 1;
    int k = low;
    int B[high + 1]; // high is Size -1. so to make the same size we write high+1.

    // creating the condition of comparisng each one of the values of both the arrays.
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            k++;
            i++;
        }
        else
        {
            B[k] = A[j];
            k++;
            j++;
        }
    }

    // when one of the array gets completed before the other one.
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }

    // copy back the B array to A array
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int low, int high)
{
    int mid = (low + high) / 2;
    if (low < high)
    {
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

void main()
{
    int arr[] = {1, 3, 2, 4, 6, 5};
    int size = sizeof(arr) / sizeof(int);
    printArray(arr, size);
    mergeSort(arr, 0, size - 1); // array , low and high.
    printArray(arr, size);
}