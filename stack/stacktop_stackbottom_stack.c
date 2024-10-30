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
    if (ptr->top == ptr->size - 1) // minus one because index start with zero.
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

int peek(struct Stack *ptr, int i)
{
    if (ptr->top - i + 1 < 0)
    {
        printf("Invalid position %d\n", i);
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top - i + 1];
    }
}

//topmost element of stack 
int stackTop (struct Stack * ptr){
 return ptr->arr[ptr->top];
}


//bottommost element of stack
int stackBottom(struct Stack * ptr){
    return ptr->arr[0];
}

void main()
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(sizeof(int) * s->size);

    // push the elements:
    push(s, 5446);
    push(s, 56);
    push(s, 756);
    push(s, 56);
    push(s, 67);
    push(s, 569);
    push(s, 596);
    push(s, 56);
    push(s, 56);
    push(s, 56);

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

    for (int j = 1; j <= s->top + 1; j++)
    {
        printf("%d Element is at %d Position\n", peek(s, j), j);
    }

    printf("Top most Element is %d\n", stackTop(s));
    printf("Bottom Most Element is %d\n", stackBottom(s));
}