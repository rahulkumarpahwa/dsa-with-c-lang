#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct Stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("The Stack is overflowing, can't add the value %d\n", value);
    }
    else
    {
        ptr->top = ptr->top + 1;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("The Stack is underflow, can't remove the value\n");
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

void main()
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 9;
    s->top = -1;
    s->arr = (int *)malloc(sizeof(int) * s->size);

    // push the elements:
    push(s, 56);
    push(s, 56);
    push(s, 56);
    push(s, 56);
    push(s, 56);
    push(s, 56);
    push(s, 56);
    push(s, 56);
    push(s, 56);
    push(s, 56);
    // push(s, 996); // value overflow at this value addition as size is 9.

    printf("value %d is removed from the stack\n", pop(s));

    if (isEmpty(s))
    {
        printf("stack is underflow\n");
    }
    else if (isFull(s))
    {
        printf("stack is overflow\n");
    }
    else
    {
        printf("stack is not full\n");
    }
}