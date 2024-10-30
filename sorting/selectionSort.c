#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("a[%d]: %d \n", i, arr[i]);
    }
}

void selectionSort(int *A, int size)
{
    int temp, indexOfMin;
    for (int i = 1; i < size - 1; i++)
    { // no. of passes
        printf("No of Passes : %d \n", i);
        indexOfMin = i;
        for (int j = i + 1; j <=size - 1; j++) //comaparison are also four but done till last.
        {                   // or write here j<size; 
            printf("No of comparisons : %d \n", j-1); 
            if (A[j] < A[indexOfMin]) // here we are comparing values and replacing index.
            {
                indexOfMin = j;
            }
        }

        // swaping the minimum value with first value before Horizontal line.
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

void main()
{
    int arr[] = {1, 3, 2, 4, 6, 5};
    int size = sizeof(arr) / sizeof(int);
    printArray(arr, size);
    selectionSort(arr, size);
    printArray(arr, size);
}