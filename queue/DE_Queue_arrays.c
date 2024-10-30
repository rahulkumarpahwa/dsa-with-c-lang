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

void enqueueF(struct DEQueue *q, int val)
{
    if (q->f == -1) // for front, f should not be -1.
    {
        printf("DEQueue overflow, can't put! \n");
    }
    else
    {
        q->arr[q->f] = val;
        printf("Element added : %d\n", val);
    }
}

void enqueueR(struct DEQueue *q, int val)
{
    if (isFull(q))
    {
        printf("DEQueue overflow, can't put! \n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        printf("Element added : %d\n", val);
    }
}

int dequeueF(struct DEQueue *q)
{
    int a = -1;
    if (q->f == q->r) // if empty then can't remove from the front, when either f =-1 or the f = r.
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

int dequeueR(struct DEQueue *q)
{
    int a = -1;
    if (q->r == -1)
    {
        printf("DEQueue underflow, can't remove! \n");
    }
    else
    {
        a = q->arr[q->r];
        q->r--;
    }
    return a;
}

void queueTraversal(struct DEQueue *q)
{
    for (int i = q->f+1; i <=q->r; i++)
    {
        printf("Elements in the queue : %d\n", q->arr[i]);
    }
}

void main()
{
    struct DEQueue *q = (struct DEQueue *)malloc(sizeof(struct DEQueue));

    q->size = 100;
    q->f = q->r = -1;
    q->arr = (int *)malloc(sizeof(int) * q->size); // other way : (*q).arr = (int *)malloc(sizeof(int) * q->size);

    // if (isFull(q))
    // {
    //     printf("DEQueque is Overflow\n");
    // }
    // else if (isEmpty(q))
    // {
    //     printf("DEQueque is underflow\n");
    // }
    // else
    // {
    //     printf("DEQueque is not empty not full\n");
    // }

    enqueueR(q, 75);
    enqueueR(q, 65);
    printf("Value removed is : %d\n", dequeueF(q));
    enqueueF(q, 23); // entering new element at start.
    queueTraversal(q);
    // if (isFull(q))
    // {
    //     printf("Queque is Overflow\n");
    // }
    // else if (isEmpty(q))
    // {
    //     printf("Queque is underflow\n");
    // }
    // else
    // {
    //     printf("Queque is not empty not full\n");
    // }

    enqueueR(q, 45);

    queueTraversal(q);

    printf("Value removed is : %d\n", dequeueF(q)); // removing element at the start.

    // if (isFull(q))
    // {
    //     printf("Queque is Overflow\n");
    // }
    // else if (isEmpty(q))
    // {
    //     printf("Queque is underflow\n");
    // }
    // else
    // {
    //     printf("Queque is not empty not full\n");
    // }

    printf("Value removed is : %d\n", dequeueR(q));

    queueTraversal(q);





























    free(q); // to free memory.
}