#include <stdio.h>
#include <stdlib.h>

struct DEQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct DEQueue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

int isFull(struct DEQueue *q)
{
    if (q->r == q->size - 1) // size-1 because array start from the zero.
    {
        return 1;
    }
    return 0;
}

void equeueF(struct DEQueue *q, int val)
{
    if (isFull(q))
    {
        printf("DEQueue overflow, can't put! \n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int DeDEQueue(struct DEQueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("DEQueue underflow, can't remove! \n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

void main()
{
    struct DEQueue *q = (struct DEQueue *)malloc(sizeof(struct DEQueue));

    q->size = 100;
    q->f = q->r = -1;
    q->arr = (int *)malloc(sizeof(int) * q->size);

    if (isFull(q))
    {
        printf("Queque is Overflow\n");
    }
    else if (isEmpty(q))
    {
        printf("Queque is underflow\n");
    }
    else
    {
        printf("Queque is not empty not full\n");
    }

    EnDEQueue(q, 23); // entering new element at last.

    if (isFull(q))
    {
        printf("Queque is Overflow\n");
    }
    else if (isEmpty(q))
    {
        printf("Queque is underflow\n");
    }
    else
    {
        printf("Queque is not empty not full\n");
    }

    printf("Value removed is : %d\n", DeDEQueue(q)); // removing element at the start.

    if (isFull(q))
    {
        printf("Queque is Overflow\n");
    }
    else if (isEmpty(q))
    {
        printf("Queque is underflow\n");
    }
    else
    {
        printf("Queque is not empty not full\n");
    }

    free(q); // to free memory.
}