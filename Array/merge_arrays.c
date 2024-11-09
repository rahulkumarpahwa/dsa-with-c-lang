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

    int i = 0;
    int j = 0;
    int k = a->usedSize - 1;
    int l = b->usedSize - 1;
    int r = 0; // for the array in which we put. here it is C array.

    while (i <= k && j <= l)
    {
        if (a->arr[i] < b->arr[j])
        {
            c->arr[r] = a->arr[i];
            r++;
            i++;
        }
        else
        {
            c->arr[r] = b->arr[j];
            r++;
            j++;
        }
    }

    // when one of the array gets completed before the other one. running individually when one of them is left.
    while (i <= k)
    {
        c->arr[r] = a->arr[i];
        r++;
        i++;
    }
    while (j <= l)
    {
        c->arr[r] = b->arr[j];
        r++;
        j++;
    }
}

void main()
{
    // Initialising first array.
    struct myArray *a = (struct myArray *)malloc(sizeof(struct myArray));
    a->usedSize = 10;
    a->capacity = 100;
    a->arr = (int *)malloc(sizeof(int) * a->capacity);

    // Initialising second array.
    struct myArray *b = (struct myArray *)malloc(sizeof(struct myArray));
    b->usedSize = 10;
    b->capacity = 100;
    b->arr = (int *)malloc(sizeof(int) * b->capacity);

    // Initialising third array.
    struct myArray *c = (struct myArray *)malloc(sizeof(struct myArray));
    c->usedSize = 20;
    c->capacity = 100;
    c->arr = (int *)malloc(sizeof(int) * c->capacity);

    insert(a);
    insert(b);

    arrayTraversal(a);
    arrayTraversal(b);

    printf("\n");
    mergeArrayUnSorted(a, b, c);
    arrayTraversal(c);

    printf("\n");

    mergeArraySorted(a, b, c);
    arrayTraversal(c);
}