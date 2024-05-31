#include<stdio.h> 
#include<stdlib.h> 

struct Node
{
  int data;
  struct Node *next;
};

typedef struct Node node;

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

void display (node *node)
{
  printf ("Linked List : \n");
  while (node != NULL)
    {
      printf ("%d ", node->data);
      node = node->next;
    }
  printf ("\n");
}

int size (node *node)
{
  int counter=0;
  while (node != NULL)
    {
      node = node->next;
      counter++;
    }
 return counter;
}

int checkPalindrome (node *head, int counter)
{
    int i = 0, j;
    node *front, *rear;
     while (i != counter / 2)
    {
        front = rear = head;
        for (j = 0; j < i; j++)
        {
            front = front->next;
        }
        for (j = 0; j < counter - (i + 1); j++)
        {
            rear = rear->next;
        }
        if (front->data != rear->data)
        {
            return 0;
        }
        else
        {
            i++;
        }
    }

    return 1;
}

int main ()
{
  node *head = NULL;
  int counter,result, data, n, i;

  printf("Enter the number of elements in the linked list: ");
  scanf("%d", &n);

  printf("Enter the elements: ");
  for(i = 0; i < n; i++)
  {
    scanf("%d", &data);
    insert_end(&head, data);
  }

  display (head);
  counter = size(head);
  result = checkPalindrome (head, counter);

  if (result == 1)
  {
    printf("The linked list is a palindrome.\n");
  }
  else
  {
    printf("The linked list is not a palindrome.\n");
  }
  return 0;
}
