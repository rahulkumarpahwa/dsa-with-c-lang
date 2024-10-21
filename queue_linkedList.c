#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int data;
    struct Queue *next;
};

struct Queue *f = NULL; // defining global variables
struct Queue *r = NULL; // defining global variables

int isFull()
{
    struct Queue *n = (struct Queue *)malloc(sizeof(struct Queue));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if (f == NULL)
    { // when the f is NULL the Queue is Empty.
        return 1;
    }
    else
    {
        return 0;
    }
}

void queueTraversal()
{

    struct Queue *p = f;
    while (p != NULL)
    {
        printf("Element Inserted : %d \n", p->data);
        p = p->next;
    }
}

void Enqueue(int val)
{
    struct Queue *n = (struct Queue *)malloc(sizeof(struct Queue));
    if (n == NULL)
    {
        printf("Queue is Full, can enqueue\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        { // means queue is empty
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int Dequeue()
{
    int value = -1;
    struct Queue *ptr = f;
    if (isEmpty())
    {
        printf("Queue is empty, can't dequeue\n");
        return -1;
    }
    else
    {
        value = ptr->data;
        f = ptr->next;
        free(ptr);
        return value;
    }
}

void main()
{
    queueTraversal();
    printf("The Value removed is : %d\n", Dequeue());
    Enqueue(244);
    Enqueue(354);
    Enqueue(24);
    Enqueue(355);
    queueTraversal();

    printf("The Value removed is : %d\n", Dequeue());
    printf("The Value removed is : %d\n", Dequeue());
    queueTraversal();
}