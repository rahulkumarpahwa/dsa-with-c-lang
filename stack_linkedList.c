#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void main()
{
    struct Node * top = (struct Node *)malloc(sizeof(struct Node));
    top = NULL;

    if (isEmpty(top))
    {
        printf("Stack is underflow");
    }
    else if (isFull())
    {
        printf("Stack is overflow");
    } else {
        printf("Stack is Not Empty Or Full");
    }
}