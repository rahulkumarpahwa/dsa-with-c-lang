#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

void inOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int isBST(struct Node *root)
{
    static struct Node *prev = NULL; // make sure it is static otherwise prev will have different value for each call.
    if (root == NULL)
    {
        return 1; // when tree is NULL, then it is BST.
    }
    // cases:
    if (!isBST(root->left))
    { // when the left subtree is not BST, then whole tree is not BST.
        return 0;
    }
    if (prev != NULL && root->data <= prev->data)
    { // here , initially prev will be set by the root->left case, which is the root value of the left subtree.
        return 0;
    }
    prev = root; // most important line. As when right subtree is searched then prev is main root of the tree.
    return isBST(root->right);
}

struct Node *searchBST(struct Node *root, int val) // here we are doing recursive calling of function.
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
    return NULL;
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

    c1->data = 30;
    c1->left = c1->right = NULL;

    c2->data = 54;
    c2->left = NULL;
    c2->right = c3;

    inOrderTraversal(root);
    printf("\n");

    if (isBST(root))
    {
        printf("The Given Tree is BST!\n");
    }
    else
    {
        printf("NOT a BST!\n");
    }

    int val = 94;
    struct Node *n = searchBST(root, val);

    if (n == NULL)
    {
        printf("NOT Found: %d", val);
    }
    else
    {
        printf("Found : %d ", val);
    }
}