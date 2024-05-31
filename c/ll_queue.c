//SHIVAMBU DEV PANDEY
//23BCS123
//CSE B
//LAB 7
//PROGRAM 2
//Date : 22/02/2024


/*
2.Write a C program to implement the queue using the singly linked list data structure.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int data;
   struct node *next;
} node;


typedef struct queue{
   node *front;
   node *rear;
} queue;


void create_Q(queue *q) {
   q->front = q->rear = NULL;
}


void enqueue(queue *q, int item) {
   node *new_node = (node*) malloc(sizeof(node));
   if (new_node == NULL) {
       printf("Memory allocation error\n");
       return;
   }
   new_node->data = item;
   new_node->next = NULL;


   if (q->rear == NULL) {      
       q->front = q->rear = new_node;
   } else {
       q->rear->next = new_node;
       q->rear = new_node;
   }
   printf("Enqueued element: %d\n", item);
}


void dequeue(queue *q) {
   if (q->front == NULL) {
      
       printf("Queue is empty\n");
       return;
   }

   node *temp = q->front;
   int del_ele = temp->data;

   if (q->front == q->rear) {      
       q->front = q->rear = NULL;
   } else {
       q->front = q->front->next;
   }

   free(temp);
   printf("Dequeued element: %d\n", del_ele);
}


void display(queue q) {
   if (q.front == NULL) {      
       printf("Queue is empty\n");
       return;
   }
   printf("Queue elements: ");
   node *p = q.front;
   while (p != NULL) {
       printf("%d  ", p->data);
       p = p->next;
   }
   printf("\n");
}


int main() {
   queue q;
   create_Q(&q);
   int choice, item;
   while (1) {
       printf("\nQueue using Linked List\n");
       printf("1. Enqueue  ");
       printf("2. Dequeue  ");
       printf("3. Display  ");
       printf("4. Exit\n");
       printf("Enter your choice: ");
       scanf("%d", &choice);


       switch (choice) {
           case 1:
               printf("Enter the element to enqueue: ");
               scanf("%d", &item);
               enqueue(&q, item);
               break;
           case 2:
               dequeue(&q);
               break;
           case 3:
               display(q);
               break;
           case 4:
               printf("Exiting program\n");
               exit(0);
           default:
               printf("Invalid choice\n");
       }
   }


   return 0;
}
