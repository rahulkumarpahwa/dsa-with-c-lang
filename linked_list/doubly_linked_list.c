// we will create doubly linked list with forward and backword traversal and printing values.
// else commands can be done by self like insertion, deletion and others.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void linkedListTraversalForward(struct Node *head)
{
    struct Node *ptr = head;

    while (ptr->next != NULL) // forward traversal
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("Element : %d\n", ptr->data);
}

void linkedListTraversalBackward(struct Node *head)
{
    struct Node *ptr = head;
    // first move ptr to the last node
    if (head != NULL)
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
    }
    while (ptr != NULL) // backward traversal
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->prev;
    }
}

int deleteAtEnd(struct Node *head)
{
    struct Node *ptr = head;
    if (ptr == NULL)
    {
        printf("Can't Delete, Underflow!\n");
        return -1; // considering -1 is not a value of node.
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    int m = ptr->data;
    ptr->prev->next = ptr->next; // setting the second last node to NULL
    free(ptr);
    return m;
}

struct Node *insertAtStart(struct Node *head, int val)
{
    struct Node *ptr = head;
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Overflow, can't insert!\n");
        return NULL;
    }
    n->data = val;
    n->next = ptr;
    n->prev = ptr->prev;
    ptr->prev = n;
    head = n;
    return head;
}

void main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 44;
    head->next = second;
    head->prev = NULL;

    second->data = 88;
    second->next = third;
    second->prev = head;

    third->data = 888;
    third->next = NULL;
    third->prev = second;

    head = insertAtStart(head, 22);

    linkedListTraversalForward(head);
    printf("\n");
    linkedListTraversalBackward(head);
    printf("\n");
    printf("deleted Node : %d \n", deleteAtEnd(head));
    printf("\n");
    linkedListTraversalForward(head);
    printf("\n");
    linkedListTraversalBackward(head);
}