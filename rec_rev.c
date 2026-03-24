#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *next;
};
void rec_rev(struct node *ptr, struct node *prev, struct node **head)
{
    if (ptr == NULL)
    {
        *head = prev;
        return;
    }
    struct node *temp = ptr->next;
    ptr->next = prev;
    rec_rev(temp, ptr, head);
}

int main()
{

    // Create 7 nodes manually
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->val = 1;

    struct node *second = (struct node *)malloc(sizeof(struct node));
    second->val = 2;

    struct node *third = (struct node *)malloc(sizeof(struct node));
    third->val = 3;

    struct node *fourth = (struct node *)malloc(sizeof(struct node));
    fourth->val = 4;

    struct node *fifth = (struct node *)malloc(sizeof(struct node));
    fifth->val = 5;

    struct node *sixth = (struct node *)malloc(sizeof(struct node));
    sixth->val = 6;

    struct node *seventh = (struct node *)malloc(sizeof(struct node));
    seventh->val = 7;

    // Link them
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = NULL;

    rec_rev(head, NULL, &head);

    // Print list
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}