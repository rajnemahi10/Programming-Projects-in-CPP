/*Given a 2D matrix of characters, represent it using lists where each node stores one character of this matrix,
right pointer points to the next character, down pointer points to the next row’s character in the same column.
Now implement deletion of a node.*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int val;
    struct Node *down;
    struct Node *right;
};
struct Node *add(int **arr, int i, int j, struct Node **head)

{
    if (i >= (int)((sizeof(arr) / sizeof(arr[0]))) + 1 || j >= (int)((int)(sizeof(arr[0])) / (int)(sizeof(int))) + 1)
        return NULL;

    struct Node *newNode = malloc(sizeof(struct Node));

    if (i == 0 && j == 0)
        *head = newNode;

    newNode->val = arr[i][j];

    struct Node *downlink = add(arr, i + 1, j, head);
    struct Node *rightlink = add(arr, i, j + 1, head);
    newNode->right = rightlink;
    newNode->down = downlink;
    return newNode;
}

int main()
{
    return 0;
}
