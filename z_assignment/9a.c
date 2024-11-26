#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *head)
{
    struct Node *p = head;
    do
    {
        printf("Element : %d\n", p->data);
        p = p->next;
    } while (p != head);

    printf("\n");
}

struct Node *insertAtStart(struct Node *head, int val)
{
    struct Node *ptr = head;
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = val;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    n->next = ptr->next;
    ptr->next = n;
    head = n;
    return head;
}

struct Node *insertAfterIndex(struct Node *head, int val, int index)
{
    struct Node *ptr = head;
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = val;
    for (int i = 0; i < index && ptr->next != head; i++)
    {
        ptr = ptr->next;
    }
    n->next = ptr->next;
    ptr->next = n;
    return head;
}

struct Node *deleteAtStart(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = head->next;
    free(head);
    return ptr->next;
}

void main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 24;
    head->next = second;

    second->data = 48;
    second->next = third;

    third->data = 96;
    third->next = head; // attach end node to the head.

    traversal(head);

    head = insertAtStart(head, 12);
    traversal(head);

    head = deleteAtStart(head);
    traversal(head);

    head = insertAfterIndex(head, 36, 0); // 0 is here the index and not the position.
    traversal(head);
}
