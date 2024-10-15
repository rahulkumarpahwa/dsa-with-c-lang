#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct Queue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void Enqueue(struct Queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue overflow, can't put! \n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int Dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow, can't remove! \n");
    }
    else
    {
        q->f++;
    }
}

void main()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));

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

    Enqueue(q, 23);

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

    Dequeue(q);
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