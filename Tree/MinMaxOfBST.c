#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
    {
        return newNode(key);
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    return node;
}

int findMin(struct node *root)
{
    if (root == NULL)
    {
        printf("Error: Tree is empty");
        return -1;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->key;
}

int findMax(struct node *root)
{
    if (root == NULL)
    {
        printf("Error: Tree is empty");
        return -1;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->key;
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    inOrder(root);
    printf("\nMinimum element is %d ", findMin(root));
    printf("\nMaximum element is %d ", findMax(root));

    return 0;
}