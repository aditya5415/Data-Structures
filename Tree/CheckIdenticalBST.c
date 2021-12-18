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

int identical(struct node *a, struct node *b)
{
    if (a == NULL && b == NULL)
    {
        return 1;
    }
    else if (a != NULL && b != NULL)
    {
        return (a->key == b->key && identical(a->left, b->left) && identical(a->right, b->right));
    }
    else
    {
        return 0;
    }
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

    struct node *root2 = NULL;
    root2 = insert(root2, 50);
    insert(root2, 30);
    insert(root2, 20);
    insert(root2, 40);
    insert(root2, 70);
    insert(root2, 60);
    insert(root2, 80);

    int res = identical(root, root2);
    if (res == 0)
    {
        printf("Tree are not identical");
    }
    else
    {
        printf("Tree are identical");
    }

    return 0;
}