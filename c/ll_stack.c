//SHIVAMBU DEV PANDEY
//23BCS123
//CSE B
//LAB 7
//PROGRAM 1
//Date : 22/02/2024


/*
1.Write a C program to implement the stack using the singly linked list data structure.
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct node {
  int data;
  struct node *next;
} node;


void push(node **top, int item) {
  node *new_node = (node*) malloc(sizeof(node));
  if (new_node == NULL) {
      printf("Memory allocation error\n");
      return;
  }
  new_node->data = item;
  new_node->next = *top;
  *top = new_node;
  printf("Element %d pushed to the stack\n", item);
}


void pop(node **top) {
  if (*top == NULL) {
      printf("Stack underflow\n");
      return;
  }
  node *temp = *top;
  *top = (*top)->next;
  int del_ele = temp->data;
  free(temp);
  printf("Popped element: %d\n", del_ele);
}


void peek(node *top) {
  if (top == NULL) {
      printf("Stack is empty\n");
      return;
  }
  printf("Top element: %d\n", top->data);
}


void display(node *top) {
  if (top == NULL) {
      printf("Stack is empty\n");
      return;
  }
  printf("Stack elements: ");
  while (top != NULL) {
      printf("%d  ", top->data);
      top = top->next;
  }
  printf("\n");
}


int main() {
  node *top = NULL;
  int choice, item;


  while (1) {
      printf("\nStack using Linked List\n");
      printf("1. Push  ");
      printf("2. Pop  ");
      printf("3. Peek  ");
      printf("4. Display  ");
      printf("5. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);


      switch (choice) {
          case 1:
              printf("Enter the element to push: ");
              scanf("%d", &item);
              push(&top, item);
              break;
          case 2:
              pop(&top);
              break;
          case 3:
              peek(top);
              break;
          case 4:
              display(top);
              break;
          case 5:
              printf("Exiting program\n");
              exit(0);
          default:
              printf("Invalid choice\n");
      }
  }


  return 0;
}
