#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void push(struct node **head_ref, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = (*head_ref);
    (*head_ref) = newNode;
}

//Function to get size of the list
int listSize(struct node *node)
{
    int c = 0;
    while (node != NULL)
    {
        c++;
        node = node->next;
    }
    return c;
}

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sortInWave(struct node *head)
{
    struct node *current = head;
    struct node *prev = NULL;
    int i = 0;              // Variable to track even position
    int n = listSize(head); // Size of list

    // Traverse all even positioned nodes
    while (i < n)
    {
        if (i % 2 == 0)
        {
            // If current even element is
            // smaller than previous
            if (i > 0 && (prev->data > current->data))
            {
                swap(&(current->data), &(prev->data));
            }
            // If current even element is
            // smaller than next
            if (i < n - 1 && (current->data < current->next->data))
            {
                swap(&(current->data), &(current->next->data));
            }
        }
        i++;
        prev = current;
        current = current->next;
    }
}

int main()
{
    struct node *start = NULL;
    push(&start, 23);
    push(&start, 5);
    push(&start, 1);
    push(&start, 2);
    push(&start, 49);
    push(&start, 90);
    push(&start, 10);

    sortInWave(start);
    printList(start);

    return 0;
}
