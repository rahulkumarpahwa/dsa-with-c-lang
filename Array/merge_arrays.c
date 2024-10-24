#include <stdio.h>
#include <stdlib.h> // malloc function in file.

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

void insert(struct myArray *a)
{
    printf("Enter the values in array\n");
    for (int i = 0; i < a->usedSize; i++)
    {
        scanf("%d", &a->arr[i]);
    }
}

// case1: unsorted array.
void mergeArrayUnSorted(struct myArray *a, struct myArray *b, struct myArray *c)
{
    int Index = 0;
    for (int i = 0; i < a->usedSize; i++)
    {
        c->arr[Index] = a->arr[i];
        Index++;
    }
    for (int j = 0; j < b->usedSize; j++)
    {
        c->arr[Index] = b->arr[j];
        Index++;
    }
}

// case2 : sorted array.
void mergeArraySorted(struct myArray *a, struct myArray *b, struct myArray *c)
{
    int Index = 0;
    if (a->arr[a->usedSize - 1] > b->arr[0])
    {
        for (int j = 0; j < b->usedSize; j++)
        {
            c->arr[Index] = b->arr[j];
            Index++;
        }
        for (int i = 0; i < a->usedSize; i++)
        {
            c->arr[Index] = a->arr[i];
            Index++;
        }
        
    }
    else
    {
        for (int i = 0; i < a->usedSize; i++)
        {
            c->arr[Index] = a->arr[i];
            Index++;
        }
        for (int j = 0; j < b->usedSize; j++)
        {
            c->arr[Index] = b->arr[j];
            Index++;
        }
        
    } 
    // note : create a case later that when the last element of 1st array is same as first element of second array.
}

void main()
{
    // Intialising first array.
    struct myArray *a = (struct myArray *)malloc(sizeof(struct myArray));
    a->usedSize = 10;
    a->capacity = 100;
    a->arr = (int *)malloc(sizeof(int) * a->capacity);

    // Intialising second array.
    struct myArray *b = (struct myArray *)malloc(sizeof(struct myArray));
    b->usedSize = 10;
    b->capacity = 100;
    b->arr = (int *)malloc(sizeof(int) * b->capacity);

    // Intialising third array.
    struct myArray *c = (struct myArray *)malloc(sizeof(struct myArray));
    c->usedSize = 20;
    c->capacity = 100;
    c->arr = (int *)malloc(sizeof(int) * c->capacity);

    insert(a);
    insert(b);

    arrayTraversal(a);
    arrayTraversal(b);
    mergeArrayUnSorted(a, b, c);
    arrayTraversal(c);

    mergeArraySorted(a, b, c);
    arrayTraversal(c);

    // note : remaining case : create a case later that when the last element of 1st array is same as first element of second array.
}