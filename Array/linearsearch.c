#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int usedSize;
    int capacity;
    int *arr;
};

void traversal(struct myArray *a)
{
    for (int i = 0; i < a->usedSize; i++)
    {
        printf("%d ", a->arr[i]);
    }
}

void linearSearch(struct myArray *a, int val)
{
    int pos = -1;
    for (int i = 0; i < a->usedSize; i++)
    {
        if (val == a->arr[i])
        {
            pos = i;
        }
    }
    if (pos == -1)
    {
        printf("The %d can't be found.", val);
    }
    else
    {
        printf("The %d has been found at : %d", val, pos + 1);
    }
}

void main()
{
    struct myArray *a = (struct myArray *)malloc(sizeof(struct myArray));
    a->capacity = 100;
    a->usedSize = 5;
    a->arr = (int *)malloc(sizeof(int) * a->capacity);

    // insertion:
    int Arr[] = {122, 122, 244, 344, 34};
    for (int i = 0; i < a->usedSize; i++)
    {
        a->arr[i] = Arr[i];
    }

    traversal(a);
    printf("\n \n");

    int val = 34;
    linearSearch(a, val);
}