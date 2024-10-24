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
        printf("%d\n", a->arr[i]);
    }
    printf("\n");
}

void insertAtEnd(struct myArray *a, int val)
{
    a->usedSize++;
    a->arr[a->usedSize - 1] = val;
}

int deleteAtEnd(struct myArray *a)
{
    int val = -1;
    val = a->arr[a->usedSize - 1];
    a->usedSize--;
    return val;
}

void insertAtPosition(struct myArray *a, int pos, int val)
{
    for (int i = a->usedSize - 1; i >= pos - 1; i--)
    {
        a->arr[i + 1] = a->arr[i];
    }
    a->usedSize++;
    a->arr[pos - 1] = val;
}

int deletionAtPosition(struct myArray *a, int pos)
{
    int val = a->arr[pos - 1];
    for (int i = pos - 1; i < a->usedSize; i++)
    {
        a->arr[i] = a->arr[i + 1];
    }
    a->usedSize--;
    return val;
}

void main()
{
    struct myArray *a = (struct myArray *)malloc(sizeof(struct myArray));
    a->usedSize = 10;
    a->capacity = 100;
    a->arr = (int *)malloc(sizeof(int) * a->capacity);

    printf("Enter the values in array\n");
    for (int i = 0; i < a->usedSize; i++)
    {
        scanf("%d", &a->arr[i]);
    }

    arrayTraversal(a);
    insertAtEnd(a, 44);

    arrayTraversal(a);
    insertAtPosition(a, 5, 56); // array, position (starting from the one), value to be inserted.
    arrayTraversal(a);

    deleteAtEnd(a);
    arrayTraversal(a);

    deletionAtPosition(a, 5); // array, position (starting from the one).
    arrayTraversal(a);
}