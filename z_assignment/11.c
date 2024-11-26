#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

void traversal()
{
    struct Node *p = f;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int isFull()
{
    if (f == NULL)
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));

    if (q == NULL)
    {
        return 1;
    }
    return 0;
}

void Enqueue(int val)
{
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));

    if (q == NULL)
    {
        printf("Overflow! can't Enqueue.");
        return;
    }
    else
    {
        q->data = val;
        q->next = NULL;
        if (f == NULL)
        {
            f = r = q;
        }
        else
        {
            r->next = q;
            r = q;
        }
    }
}

int Dequeue()
{
    struct Node *ptr = f;
    int a = -1;
    if (f == NULL)
    {
        printf("Underflow! can't dequeue");
        return a;
    }
    else
    {
        a = f->data;
        f = ptr->next;
        free(ptr);
        return a;
    }
}

void main()
{
    Enqueue(24);
    Enqueue(48);
    Enqueue(96);
    traversal();

    Dequeue();
    traversal();
}