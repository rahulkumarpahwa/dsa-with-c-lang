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

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

    } while (i < j);
    temp = A[low]; // A[low] is key but we are sorting so we use A[low] not key as key is copy of it.
    A[low] = A[j];
    A[j] = temp;
    return j; // returning the partitionIndex.
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex;
    if (low < high) // means atleast one value.
    {
        partitionIndex = partition(A, low, high);
        // printArray(A, high); // print after every partition.
        quickSort(A, low, partitionIndex - 1);
        quickSort(A, partitionIndex + 1, high);
    }
}

void main()
{
    int arr[] = {1, 3, 2, 4, 6, 5};
    int size = sizeof(arr) / sizeof(int);
    printArray(arr, size);
    quickSort(arr, 0, size - 1); // array , low and high.
    printArray(arr, size);
}