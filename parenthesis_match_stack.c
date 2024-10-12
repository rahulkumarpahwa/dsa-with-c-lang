// note:
// 1. change the int type arr to char type arr in dynamic allocation.
// 2. set the size of arr such that whole string expression can be putted in it. either set a constant value or find the lenght of string with strlen() method.
// 3. parenthesis match find the parenthesis balance but does n't talk about the mathematical validity of the expression.

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for strlen() method

struct Stack
{
    int size;
    int top;
    char *arr;
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

void push(struct Stack *ptr, char value)
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

char pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("The Stack is underflow, can't remove the value\n");
    }
    else
    {
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}


int parenthesisMatch(char *exp)
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = strlen(exp);
    s->top = -1;
    s->arr = (char *)malloc(sizeof(char) * s->size);

    for (int i = 0; exp[i] != '\0'; i++)
    { // we are taking the value until exp's last character not the size because string may contain less character than the size.
        if (exp[i] == '(')
        {
            push(s, exp[i]);
        }
        else if(exp[i] == ')')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            else
            {
                pop(s);
            }
        }
    }

    if (isEmpty(s))
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

    char *exp = "8)*($$**9)"; 

    if (parenthesisMatch(exp))
    {
        printf("The parenthesis are balanced.");
    }
    else
    {
        printf("The Parenthesis are not balanced.");
    }
}