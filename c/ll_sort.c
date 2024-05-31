//SHIVAMBU DEV PANDEY
//23BCS123
//CSE B
//LAB 5
//PROGRAM 3
//Date : 15/02/2024

/*
3.Write a program to sort the elements of a singly linked list in ascending and descending order.
*/



#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int data;
   struct node *next;
} node;

void traverse(node *head) {
   int count = 1;
   node *p = head;
   while (p != NULL) {
       printf("\nNode_%d _data: %d", count, p->data);
       count++;
       p = p->next;
   }
}

void insert_begin(node **head, int item) {
   node *new_node = (node*) malloc(sizeof(node));
   new_node->data = item;
   new_node->next = *head;
   *head = new_node;
}

void insert_end(node **head, int item) {
   node *new_node = (node*) malloc(sizeof(node));
   new_node->data = item;
   new_node->next = NULL;
   if (*head == NULL) {
       *head = new_node;
       return;
   }
   node *p = *head;
   while(p->next != NULL) {
       p = p->next;
   }
   p->next = new_node;
}

void insert_any_position(node **head, int item, int pos) {
   node *new_node = (node*) malloc(sizeof(node));
   new_node->data = item;
   if (pos == 1) {
       new_node->next = *head;
       *head = new_node;
       return;
   }
   node *p = *head;
   for(int i = 1; i < pos - 1 && p != NULL; i++) {
       p = p->next;
   }
   if (p == NULL) {
       printf("Position out of range\n");
       return;
   }
   new_node->next = p->next;
   p->next = new_node;
}

void delete_begin(node **head) {
   if (*head == NULL) {
       printf("List is empty\n");
       return;
   }
   node *temp = *head;
   *head = (*head)->next;
   free(temp);
}

void delete_end(node **head) {
   if (*head == NULL) {
       printf("List is empty\n");
       return;
   }
   node *p = *head, *q = NULL;
   while(p->next != NULL) {
       q = p;
       p = p->next;
   }
   if (q != NULL) {
       q->next = NULL;
   } else {
       *head = NULL;
   }
   free(p);
}

void delete_any_pos(node **head, int pos) {
   if (*head == NULL) {
       printf("List is empty\n");
       return;
   }
   node *p = *head, *q = NULL;
   if (pos == 1) {
       *head = p->next;
       free(p);
       return;
   }
   for(int i = 1; i < pos && p != NULL; i++) {
       q = p;
       p = p->next;
   }
   if (p == NULL) {
       printf("Position out of range\n");
       return;
   }
   q->next = p->next;
   free(p);
}

void sort_ascending(node **head) {
   node *i, *j;
   int temp;

   for(i = *head; i != NULL; i = i->next) {
       for(j = i->next; j != NULL; j = j->next) {
           if(i->data > j->data) {
               temp = i->data;
               i->data = j->data;
               j->data = temp;
           }
       }
   }
}

void sort_descending(node **head) {
   node *i, *j;
   int temp;

   for(i = *head; i != NULL; i = i->next) {
       for(j = i->next; j != NULL; j = j->next) {
           if(i->data < j->data) {
               temp = i->data;
               i->data = j->data;
               j->data = temp;
           }
       }
   }
}



int main() {
   node *head = NULL;
   int choice, item, pos;

   while(1) {
       printf("\nSingly Linked List\n");
       printf("1. Insert at beginning   ");
       printf("2. Insert at end ");
       printf("3. Insert at any position\n");
       printf("4. Delete from beginning ");
       printf("5. Delete from end ");
       printf("6. Delete from any position\n");
       printf("7. Traverse ");
       printf("8. Sort in ascending order ");
       printf("9. Sort in descending order\n");
       printf("10. Exit   ||");
       printf("Enter your choice: ");
       scanf("%d", &choice);

       switch(choice) {
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
               insert_any_position(&head, item, pos);
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
               delete_any_pos(&head, pos);
               break;
           case 7:
               traverse(head);
               break;
           case 8:
               sort_ascending(&head);
               traverse(head);
               break;
           case 9:
               sort_descending(&head);
               traverse(head);
               break;   
           case 10:
               exit(0);
           default:
               printf("Invalid choice\n");
       }
   }

   return 0;
}

