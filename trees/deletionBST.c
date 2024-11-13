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
    n->data = val;
    n->left = NULL;
    n->right = NULL;
}

void inOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

struct Node *inOrderPredecessor(struct Node *root)
{
    root = root->left;
    while (root->right != NULL) // we are going to most right of the left, until it is null.
    {
        root = root->right;
    }
    return root;
}

struct Node *
deletionBST(struct Node *root, int val)
{
    struct Node *iPrev;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    { // reached leaf node
        free(root);
        return NULL;
    }
    if (val < root->data)
    {
        root->left = deletionBST(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deletionBST(root->right, val);
    }
    else
    { // when root is equal to the node we want to delete.
        iPrev = inOrderPredecessor(root);
        root->data = iPrev->data;
        root->left = deletionBST(root->left, iPrev->data);
    }
    return root; // returning root which we are deleting.
}

void main()
{
    struct Node *root = createNode(20);
    struct Node *c1 = createNode(10);
    struct Node *c2 = createNode(30);
    root->left = c1;
    root->right = c2;

    inOrderTraversal(root);
    printf("\n");
    deletionBST(root, 30);
    inOrderTraversal(root);
}