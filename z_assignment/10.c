#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Node *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct Node *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct Node *s, int val)
{

    s->top++;
    s->arr[s->top] = val;
}

int pop(struct Node *s)
{
    int a = s->arr[s->top];
    s->top--;
    return a;
}

int peek(struct Node *s, int pos)
{
    int a = -1;
    if (s->top - pos + 1 < 0)
    {
        printf("Invalid position.");
        return -1;
    }
    else
    {
        return s->arr[s->top - pos + 1];
    }
}

void main()
{

    struct Node *s = (struct Node *)malloc(sizeof(struct Node));
    s->top = -1;
    s->size = 100;
    s->arr = (int *)malloc(sizeof(int) * s->size);

    if (isEmpty(s))
    {
        printf("The stack is empty.\n");
    }

    if (isFull(s))
    {
        printf("The stack is full.\n");
    }

    push(s, 23);
    printf("%d", peek(s, 1));
    pop(s);
    push(s, 24);
    push(s, 25);
    printf("\n");
    printf("%d", peek(s, 2));
}