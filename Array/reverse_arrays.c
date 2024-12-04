#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int usedSize;
    int capacity;
    int *arr;
};

void arrayTraversal(struct myArray *a)
{
    for (int i = 0; i < a->usedSize; i++)
    {
        printf("%d ", a->arr[i]);
    }
    printf("\n");
}

void reverse(struct myArray *a)
{
    int i = 0;
    int j = a->usedSize - 1;
    int temp;
    while (i < j)
    {
        temp = a->arr[i];
        a->arr[i] = a->arr[j];
        a->arr[j] = temp;
        i++;
        j--;
    }
}

void main()
{
    struct myArray *a = (struct myArray *)malloc(sizeof(struct myArray));
    a->usedSize = 5;
    a->capacity = 100;
    a->arr = (int *)malloc(sizeof(int) * a->capacity);

    // insertion in array:

    int arr[6] = {12, 45, 66, 89, 99};

    for (int i = 0; i < 6; i++)
    {
        a->arr[i] = arr[i];
    }

    arrayTraversal(a);
    reverse(a);
    arrayTraversal(a);
}