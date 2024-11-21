#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->left = n->right = NULL;
    n->data = val;
    return n;
}

void inOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf(" %d ", root->data);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf(" %d ", root->data);
    }
}

void main()
{
    struct Node *root = createNode(24);
    struct Node *cl = createNode(12);
    struct Node *cr = createNode(48);

    root->left = cl;
    root->right = cr;

    inOrderTraversal(root);
    printf("\n \n");
    preOrderTraversal(root);
    printf("\n \n");
    postOrderTraversal(root);
}