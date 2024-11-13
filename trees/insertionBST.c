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
    n->left = NULL;
    n->right = NULL;
    n->data = val;
}

void inOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d  ", root->data);
        inOrderTraversal(root->right);
    }
}

void insertBST(struct Node *root, int val)
{
    struct Node *prev = NULL;
    // searching until root become NULL or find the duplicate value of the data.
    while (root != NULL)
    {
        prev = root; // prev is the previous root value which is not traversed while every time search happen.
        if (val == root->data)
        {
            printf("Can't Insert, Duplicate value!");
            return;
        }
        else if (val < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    // creation of new node :
    struct Node *n = createNode(val);

    // insertion :

    if (val < prev->data)
    {
        prev->left = n;
    }
    else
    {
        prev->right = n;
    }
}
void main()
{
    // our BST
    //     20
    //    /  \
    // 10      30
    struct Node *root = createNode(20);
    struct Node *c1 = createNode(10);
    struct Node *c2 = createNode(30);
    root->left = c1;
    root->right = c2;

    inOrderTraversal(root);
    printf("\n");
    insertBST(root, 45);
    inOrderTraversal(root);
}