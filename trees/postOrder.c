#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

void postOrder(struct Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

struct Node *createNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void main()
{
    struct Node *root = (struct Node *)malloc(sizeof(struct Node));
    struct Node *c1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *c2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *c3 = createNode(88);

    root->data = 32;
    root->left = c1;
    root->right = c2;

    c1->data = 34;
    c1->left = c3;
    c1->right = NULL;

    c2->data = 54;
    c2->left = NULL;
    c2->right = NULL;

    postOrder(root);
}