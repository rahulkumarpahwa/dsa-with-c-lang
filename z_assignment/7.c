#include <stdio.h>
#include <stdlib.h>

void arrayTraversal(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int brr[high + 1];

    while (i <= mid && j <= high)
    {
        if (arr[i] > arr[j])
        {
            brr[k] = arr[j];
            k++;
            j++;
        }
        else
        {
            brr[k] = arr[i];
            k++;
            i++;
        }
    }

    while (i <= mid)
    {
        brr[k] = arr[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        brr[k] = arr[j];
        k++;
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = brr[i];
    }
}

void mergeSort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void insertionSort(int arr[], int size)
{
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int partition(int arr[], int low, int high)
{
    int key = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (arr[i] <= key)
        {
            i++;
        }

        while (arr[j] > key)
        {
            j--;
        }

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int arr[], int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

void main()
{
    int arr[] = {23, 4, 33, 11, 55, 3};
    int size = sizeof(arr) / sizeof(int);
    arrayTraversal(arr, size);

    bubbleSort(arr, size);
    arrayTraversal(arr, size);

    mergeSort(arr, 0, size - 1);
    arrayTraversal(arr, size);

    insertionSort(arr, size);
    arrayTraversal(arr, size);

    quickSort(arr, 0, size - 1);
    arrayTraversal(arr, size);
}