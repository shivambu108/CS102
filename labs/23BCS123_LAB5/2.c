// SHIVAMBU DEV PANDEY
// 23BCS123
// CSE B
// LAB 5
// PROGRAM 2
// Date : 15/02/2024
/*
2.Write a C program to demonstrate various circular linked list operations such as insertion, deletion and traversal. The program should be menu driven. The program should allow the user to insert, delete at the beginning, end, and at a specified position in the linked list.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void insert_begin(node **head, int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}

void insert_end(node **head, int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void insert_at_position(node **head, int value, int position)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;

    if (*head == NULL || position <= 1)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    node *temp = *head;
    for (int i = 1; i < position - 1 && temp->next != *head; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void delete_begin(node **head)
{
    if (*head == NULL)
    {
        printf("List is Empty!!! Deletion is not possible\n");
        return;
    }

    node *temp1 = *head, *temp2 = *head;

    if (temp1->next == *head)
    {
        *head = NULL;
        free(temp1);
    }
    else
    {
        while (temp1->next != *head)
        {
            temp1 = temp1->next;
        }

        *head = temp2->next;
        temp1->next = *head;
        free(temp2);
    }
}

void delete_end(node **head)
{
    if (*head == NULL)
    {
        printf("List is Empty!!! Deletion is not possible\n");
        return;
    }

    node *temp1 = *head, *temp2 = *head;

    if (temp1->next == *head)
    {
        *head = NULL;
        free(temp1);
    }
    else
    {
        while (temp1->next != *head)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }

        temp2->next = *head;
        free(temp1);
    }
}

void delete_at_position(node **head, int position)
{
    if (*head == NULL || position < 1)
    {
        printf("Invalid position or empty list\n");
        return;
    }

    if (position == 1)
    {
        node *temp = *head;
        if ((*head)->next == *head)
        {
            free(*head);
            *head = NULL;
        }
        else
        {
            (*head) = temp->next;
            free(temp);
        }
        return;
    }

    node *temp1 = *head, *temp2 = NULL;
    for (int i = 1; i < position && temp1->next != *head; i++)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    if (temp1 == *head)
    {
        printf("Position out of range\n");
        return;
    }

    temp2->next = temp1->next;
    free(temp1);
}

void traverse(node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf(" (head)\n");
}

int main()
{
    node *head = NULL;
    int choice, item, pos;

    while (1)
    {
        printf("\nCircular Linked List Operations\n");
        printf("1. Insert at beginning   ");
        printf("2. Insert at end ");
        printf("3. Insert at any position\n");
        printf("4. Delete from beginning ");
        printf("5. Delete from end ");
        printf("6. Delete from any position\n");
        printf("7. Traverse ");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            insert_begin(&head, item);
            break;
        case 2:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            insert_end(&head, item);
            break;
        case 3:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            printf("Enter the position at which to insert: ");
            scanf("%d", &pos);
            insert_at_position(&head, item, pos);
            break;
        case 4:
            delete_begin(&head);
            break;
        case 5:
            delete_end(&head);
            break;
        case 6:
            printf("Enter the position at which to delete: ");
            scanf("%d", &pos);
            delete_at_position(&head, pos);
            break;
        case 7:
            traverse(head);
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
