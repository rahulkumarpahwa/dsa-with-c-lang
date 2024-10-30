#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("a[%d]: %d \n", i, arr[i]);
    }
    printf("\n");
}

int maximum(int A[], int size)
{

    int max = INT_MIN;
    for (int i = 0; i <= size; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

void countSort(int A[], int size)
{
    int max = maximum(A, size);
    int *count = (int *)malloc(sizeof(int) * (max + 1)); // either use calloc where each element has already zero value.
    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    // increasing the value by one at the index corresponding to the value of given array.
    for (int i = 0; i <= size; i++)
    {
        count[A[i]] = count[A[i]] + 1;
    }

    int i, j; // i - counter for the Auxillary array and j - counter for given array.
    i = j = 0;
    while (i < max + 1) // putting back the indexes with values more then one in the given array.
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

void main()
{
    int arr[] = {1, 3, 2, 4, 88, 6, 5};
    int size = sizeof(arr) / sizeof(int);
    printArray(arr, size);
    countSort(arr, size-1); // array , size-1( as index starts from zero). // one of the fastest algo.
    printArray(arr, size);
}