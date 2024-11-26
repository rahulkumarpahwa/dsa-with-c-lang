#include <stdio.h>
#include <stdlib.h>

//for search refer to program : 12.c

struct myArray
{
    int usedSize;
    int capacity;
    int *arr;
};

void arrayTraversal(struct myArray *top)
{
    for (int i = 0; i < top->usedSize; i++)
    {
        printf("%d ", top->arr[i]);
    }
    printf("\n");
}

void insertAtEnd(struct myArray *top, int val)
{
    top->usedSize++;
    top->arr[top->usedSize - 1] = val;
}

void insertAtPosition(struct myArray *top, int val, int pos)
{
    for (int i = top->usedSize - 1; i >= pos - 1; i--)
    {
        top->arr[i + 1] = top->arr[i];
    }

    top->usedSize++;
    top->arr[pos - 1] = val;
}

int deleteAtEnd(struct myArray *top)
{
    int a = top->arr[top->usedSize - 1];
    top->usedSize--;

    return a;
}

int deleteAtPostion(struct myArray *top, int pos)
{
    int a = top->arr[pos - 1];
    for (int i = pos - 1; i <= top->usedSize - 1; i++)
    {
        top->arr[i] = top->arr[i + 1];
    }
    top->usedSize--;
    return a;
}

void main()
{

    struct myArray *top = (struct myArray *)malloc(sizeof(struct myArray));

    top->usedSize = 5;
    top->capacity = 100;
    top->arr = (int *)malloc(sizeof(int) * top->capacity);

    int arr[5] = {1, 2, 3, 4, 5};

    // insertion :
    for (int i = 0; i < top->usedSize; i++)
    {
        top->arr[i] = arr[i];
    }

    arrayTraversal(top);
    insertAtEnd(top, 23);

    arrayTraversal(top);
    insertAtPosition(top, 31, 3);
    arrayTraversal(top);

    deleteAtEnd(top);
    arrayTraversal(top);
    deleteAtPostion(top, 3);
    arrayTraversal(top);
}