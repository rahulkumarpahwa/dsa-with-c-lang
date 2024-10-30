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

void stackTraversal(struct Stack *top)
{
    struct Stack *ptr = top;
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// we will push the value at the top as TC is O(1). Similair is for pop.
struct Stack *push(struct Stack *top, int val)
{
    struct Stack *ptr = (struct Stack *)malloc(sizeof(struct Stack));
    if (ptr == NULL) // checking stack is full or not. if full can't push.
    {
        printf("Stack is Overflow. Can't Push\n");
        return ptr;
    }
    else
    {
        ptr->data = val;
        ptr->next = top;
        return ptr;
    }
}

struct Stack *pop(struct Stack *top)
{

    struct Stack *p = top;
    if (isEmpty(top))
    {
        printf("Stack Underflow, Can't pop\n");
        return top;
    }
    else
    {
        printf("Element Popped is %d\n", top->data);
        top = p->next;
        free(p);
        return top;
    }
}

void main()
{
    struct Stack *top = (struct Stack *)malloc(sizeof(struct Stack));
    top = NULL;

    if (isEmpty(top))
    {
        printf("Stack is underflow\n");
    }
    else if (isFull())
    {
        printf("Stack is overflow\n");
    }
    else
    {
        printf("Stack is Not Empty Or Full\n");
    }

    stackTraversal(top);
    top = push(top, 44);
    top = push(top, 454);
    top = push(top, 45664);
    top = push(top, 44634);
    stackTraversal(top);
    top = pop(top);
    stackTraversal(top);
}