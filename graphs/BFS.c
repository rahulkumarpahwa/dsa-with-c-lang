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
    int a = -1;
    if (isEmpty(q))
    {
        printf("Queue underflow, can't remove! \n");
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

    // structure of the Graph G:
    //    0---1
    //    | \ |
    //    3---2
    //     \ /
    //      4
    //     / \
    //     5  6

    int vistedArray[7] = {0, 0, 0, 0, 0, 0, 0};
    int AdjacentMatrix[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };

    // Queue (Array implementation)
    struct Queue *eq = (struct Queue *)malloc(sizeof(struct Queue)); // eq stands for exploration queue.
    eq->f = eq->r = 0;
    eq->size = 100;
    eq->arr = (int *)malloc(sizeof(int) * eq->size);

    // BFS:
    int node;
    int i = 0; // let zero be the source node. you can give anyone node.
    vistedArray[i] = 1;
    Enqueue(eq, i);   // source node i added for exploration.
    printf("%d ", i); // source node printed.

    while (!isEmpty(eq))
    {
        node = Dequeue(eq);
        for (int j = 0; j < 7; j++)
        {
            if (AdjacentMatrix[node][j] == 1 && vistedArray[j] == 0)
            //  this one means it is neighbour && this one means it is not visited.
            {
                printf("%d ", j);
                vistedArray[j] = 1;
                Enqueue(eq, j);
            }
        }
    }
}