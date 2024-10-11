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
    if (ptr->top == ptr->size-1) // minus one because index start with zero.
    {
        return 1;
    }
    return 0;
}

void main()
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(sizeof(int) * s->size);
    
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