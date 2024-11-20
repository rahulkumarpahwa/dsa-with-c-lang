#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int usedSize;
    int capacity;
    int *arr;
};

// Function to traverse the array
void traversal(struct myArray *a)
{
    for (int i = 0; i < a->usedSize; i++)
    {
        printf("%d ", a->arr[i]);
    }
    printf("\n");
}

int binarySearch(struct myArray *a, int val)
{
    int low = 0, high = a->usedSize - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a->arr[mid] == val)
        {
            return mid;
        }
        else if (a->arr[mid] < val)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // Not found
}

void main()
{
    struct myArray *a = (struct myArray *)malloc(sizeof(struct myArray));
    a->capacity = 100;
    a->usedSize = 5;
    a->arr = (int *)malloc(sizeof(int) * a->capacity);

    // Insertion
    int Arr[] = {122, 122, 244, 344, 434};
    for (int i = 0; i < a->usedSize; i++)
    {
        a->arr[i] = Arr[i];
    }

    traversal(a);

    int val = 2144;
    int pos = binarySearch(a, val);

    if (pos == -1)
    {
        printf("The %d can't be found.\n", val);
    }
    else
    {
        printf("The %d has been found at postion: %d\n", val, pos+1);
    }

}