#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node of the tree
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *AllocNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->left = NULL;
    temp->right = NULL;
    temp->data = data;
    return temp;
}

// Utility function to print the inorder
// traversal of the tree
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Function to make current node right of
// the last node in the list
void flattenBinaryTree(struct node *root, struct node **last)
{
    if (root == NULL)
    {
        return;
    }
    struct node *left = root->left;
    struct node *right = root->right;

    // Avoid first iteration where root is
    // the only node in the list
    if (root != *last)
    {
        (*last)->right = root;
        (*last)->left = NULL;
        *last = root;
    }

    flattenBinaryTree(left, last);
    flattenBinaryTree(right, last);
    if (left == NULL && right == NULL)
    {
        *last = root;
    }
}

int main()
{
    // Build the tree
    struct node *root = AllocNode(1);
    root->left = AllocNode(2);
    root->left->left = AllocNode(3);
    root->left->right = AllocNode(4);
    root->right = AllocNode(5);
    root->right->right = AllocNode(6);

    // Print the inorder traversal of the
    // original tree
    printf("Orignal inorder traversal: ");
    inOrder(root);
    printf("\n");

    // Flatten a binary tree, at the beginning
    // root node is the only and last in the list
    struct node *last = root;
    flattenBinaryTree(root, &last);

    // Print the inorder traversal of the flattened
    // binary tree
    printf("Flattened inorder traversal: ");
    inOrder(root);
    printf("\n");

    return 0;
}
