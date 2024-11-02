#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *search(struct Node *head, int val)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == val)
        {
            return ptr;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    return ptr; // when no entered in while loop then it will automatically be set to NULL.
}

void main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 23;
    second->data = 46;
    third->data = 67;

    head->next = second;
    second->next = third;
    third->next = NULL;

    struct Node *m = search(head, 213);
    if (m != NULL)
    {
        printf("Element Found : %d", m->data);
    }
    else
    {
        printf("Element Does Not Exist!");
    }
}