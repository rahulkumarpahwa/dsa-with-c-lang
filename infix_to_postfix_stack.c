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

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    return 0;
}

int Precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

char stackTop(struct Stack *s)
{
    return s->arr[s->top];
}

char *infixToPostfix(char *infix)
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(sizeof(char) * s->size);

    char *postfix = (char *)malloc(sizeof(char) * (strlen(infix) + 1)); // defining the postfix as same as size of infix. and adding extra one so as for the null string.
    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (Precedence(infix[i]) > Precedence(stackTop(s)))
            {
                push(s, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(s);
                j++;
            }
        }
    }

    while (!isEmpty(s))
    {
        postfix[j] = pop(s);
        j++;
    }

    postfix[j] = '\0'; // at the last element of the postfix we will put the empty string for which we add the add extra one in the size while creating postfix.

return postfix;
}

void main()
{

    char *infix = "x-y/z-k*d";
    printf("The Infix to Postfix is : %s", infixToPostfix(infix));
}