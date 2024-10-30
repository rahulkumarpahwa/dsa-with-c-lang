#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("a[%d]: %d \n", i, arr[i]);
    }
}

void bubbleSortAdaptive(int *arr, int size)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < size - 1; i++) // no. of passes
    {
        isSorted = 1;
        printf("No. of passes : %d", i + 1);
        for (int j = 0; j < size - 1 - i; j++) // no. of comparisons
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                isSorted = 0;
            }
        }
        printf("\n");
        if (isSorted)
        {
            return; // move out of the method.
        }
    }
}

void bubbleSort(int *arr, int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++) // no. of passes
    {
        printf("No. of passes : %d", i + 1);
        for (int j = 0; j < size - 1 - i; j++) // no. of comparisons
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
        printf("\n");
    }
}

// make sure to run the command of bubble sort adaptive before normal bubble sort.
void main()
{
    int arr[] = {1, 3, 2, 4, 6, 5, 7, 8};
    int size = sizeof(arr) / sizeof(int);
    printArray(arr, size);
    bubbleSortAdaptive(arr, size);
    printArray(arr, size);
    bubbleSort(arr, size);
    printArray(arr, size);
}