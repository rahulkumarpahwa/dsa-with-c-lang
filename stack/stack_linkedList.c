#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int data;
    struct Stack *next;
};

int isEmpty(struct Stack *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    struct Stack *n = (struct Stack *)malloc(sizeof(struct Stack));
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
    struct Stack * top = (struct Stack *)malloc(sizeof(struct Stack));
    top = NULL; // to make the top NULL

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