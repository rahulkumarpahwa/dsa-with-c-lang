#include <stdio.h>
#include <stdlib.h>

struct CircularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct CircularQueue *q) // same as normal Queue.
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

int isFull(struct CircularQueue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}

void EnQueue(struct CircularQueue *q, int val)
{
    if (isFull(q))
    {
        printf("CircularQueue overflow, can't put! \n");
    }
    else
    {
        q->r = (q->r + 1) % q->size; // circular increment.
        q->arr[q->r] = val;
        printf("Element enqueue = %d\n", val);
    }
}

int DeQueue(struct CircularQueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("CircularQueue underflow, can't remove! \n");
    }
    else
    {
        q->f = (q->f + 1) % q->size; // circular increment so that after 9 it goes to 0 and not to 10 in queque of size 10.
        a = q->arr[q->f];
    }
    return a;
}

void main()
{
    struct CircularQueue *q = (struct CircularQueue *)malloc(sizeof(struct CircularQueue));

    q->size = 4;
    q->f = q->r = 0; // intial index of f and r should be 0 or (try yourself size-1) and not -1 as linear as it will not make the queue full.
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

    printf("f value: %d\n", q->f);
    printf("r value: %d\n", q->r);

    EnQueue(q, 23); // entering new element at last.
    EnQueue(q, 23); // entering new element at last.
    EnQueue(q, 23); // entering new element at last.

    printf("f value: %d\n", q->f);
    printf("r value: %d\n", q->r);


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

    printf("Value removed is : %d\n", DeQueue(q)); // removing element at the start.

    printf("f value: %d\n", q->f);
    printf("r value: %d\n", q->r);

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

    printf("f value: %d\n", q->f);
    printf("r value: %d\n", q->r);

    free(q); // to free memory.
}