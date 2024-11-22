#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct Node *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

void Enqueue(struct Node *q, int val)
{
    if (q->r == q->size - 1)
    {
        printf("Overflow! can't Enqueue.");
        return;
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int Dequeue(struct Node *q)
{
    int a;
    if (q->f == q->r)
    {
        printf("Underflow! can't dequeue");
        return -1;
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
        return a;
    }
}

void main()
{
    // queue implementation:
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    q->f = q->r = 0;
    q->size = 100;
    q->arr = (int *)malloc(sizeof(int) * q->size);

    // graph implementation:
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

    // BFS:
    int node;
    int i = 0; // source node
    vistedArray[i] = 1;
    Enqueue(q, i);
    printf("%d ", i);

    while (!isEmpty(q))
    {
        node = Dequeue(q);
        for (int j = 0; j < 7; j++)
        {

            if (AdjacentMatrix[node][j] == 1 && vistedArray[j] == 0)
            {
                printf("%d ", j);
                vistedArray[j] = 1;
                Enqueue(q, j);
            }
        }
    }

    printf("\n\n");
    // for DFS go to part B.
}