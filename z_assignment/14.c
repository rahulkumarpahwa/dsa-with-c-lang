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

struct Node *searchBST(struct Node *root, int val) // recursive search.
{
    if (root != NULL)
    {
        if (root->data == val)
        {
            return root;
        }
        else if (root->data > val)
        {
            return searchBST(root->left, val);
        }
        else
        {
            return searchBST(root->right, val);
        }
    }
    else
    {
        return NULL;
    }
}

struct Node *searchIterBST(struct Node *root, int val)
{
    while (root != NULL)
    {
        if (root->data == val)
        {
            return root;
        }
        else if (root->data > val)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

void insertBST(struct Node *root, int val)
{
    struct Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == val)
        {
            printf("value is Duplicate! can't insert.");
            return;
        }
        else if (root->data < val)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = val;
    new->left = new->right = NULL;
    if (prev->data > val)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

struct Node *inOrderPredecessor(struct Node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct Node *deletionBST(struct Node *root, int val)
{
    struct Node *inPrev;
    // base condition
    if (root == NULL)
    {
        return NULL;
    }
    if (root->right == NULL && root->left == NULL)
    { // reached leaf node
        free(root);
        return NULL;
    }

    // condition:
    if (root->data > val)
    {
        root->left = deletionBST(root->left, val);
    }
    else if (root->data < val)
    {
        root->right = deletionBST(root->right, val);
    }
    else
    { // when root is found to be deleted.
        inPrev = inOrderPredecessor(root);
        root->data = inPrev->data;
        root->left = deletionBST(root->left, inPrev->data);
    }
    return root;
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
    printf("\n \n");
    if (searchBST(root, 24) == NULL)
    {
        printf("The value can't be not found!\n");
    }
    else
    {
        printf("The value has been found!\n");
    }

    printf("\n\n");
    if (searchIterBST(root, 24) == NULL)
    {
        printf("The value can't be not found!\n");
    }
    else
    {
        printf("The value has been found!\n");
    }

    printf("\n\n");
    struct Node *val = deletionBST(root, 48);
    printf("%d", val->data);
    printf("\n");
    inOrderTraversal(root);
}