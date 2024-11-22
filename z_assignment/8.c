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
}