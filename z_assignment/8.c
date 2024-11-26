#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("Element: %d \n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *insertAtStart(struct Node *head, int val)
{
    struct Node *ptr = head;
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Overflow! can't insert.\n");
        return NULL;
    }
    n->next = ptr;
    n->data = val;
    printf("Valued Added at Start : %d\n", val);
    head = n;
    return head;
}
struct Node *insertAtEnd(struct Node *head, int val)
{
    struct Node *ptr = head;
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Overflow! can't insert.\n");
        return NULL;
    }

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = n;
    n->data = val;
    printf("Valued Added at End : %d\n", val);
    n->next = NULL;
    return head;
}

struct Node *insertAtIndex(struct Node *head, int val, int index)
{
    struct Node *ptr = head;
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = val;
    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->next;
    }
    n->next = ptr->next;
    ptr->next = n;
    return head;
}

struct Node *insertAfterGivenNode(struct Node *head, int val, struct Node *given)
{
    struct Node *ptr = head;
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = val;
    n->next = given->next;
    given->next = n;
    return head;
}

struct Node *deleteAtStart(struct Node *head)

{
    struct Node *ptr = head;
    int a = -1;
    if (head == NULL)
    {
        printf("Underflow! can't delete.\n");
        return NULL;
    }
    a = ptr->data;
    ptr = ptr->next;
    head = ptr;
    printf("Valued deleted at Start : %d\n", a);
    return head;
}

struct Node *deleteAtEnd(struct Node *head)
{

    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;

    for (int i = 0; i < index - 1; i++)
    {
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

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
    return ptr;
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
    third->next = NULL;

    traversal(head);
    printf("\n\n");
    head = insertAtStart(head, 12);
    traversal(head);
    printf("\n\n");
    head = insertAtEnd(head, 192);
    traversal(head);
    printf("\n\n");
    head = deleteAtStart(head);
    traversal(head);
    printf("\n\n");
    int val = 48;
    if (search(head, val) != NULL)
    {
        printf("%d is found!\n", val);
    }
    else
    {
        printf("%d does not found!\n", val);
    }
    printf("\n\n");
    traversal(head);

    head = insertAtIndex(head, 72, 2); // here 2 is the index not position.

    printf("\n\n");
    traversal(head);

    head = insertAfterGivenNode(head, 36, head);
    printf("\n\n");
    traversal(head);

    head = deleteAtEnd(head);
    printf("\n\n");
    traversal(head);

    head = deleteAtIndex(head, 1); // 1 is index here not position
    printf("\n\n");
    traversal(head);
}