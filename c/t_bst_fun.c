//SHIVAMBU DEV PANDEY
//23BCS123
//CSE B
//LAB 10
//PROGRAM 1
//Date : 28/03/2024


/*
1.Write a menu driven C program to implement various operations of a Binary
Search Tree such as Insert, Search, Display (in-order) and Deleting a specified key.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int data;
   struct node* left;
   struct node* right;
}node;

node* create(int val) {
   node* newNode = (node*)malloc(sizeof(node));
   if (newNode == NULL) {
       printf("Memory allocation failed.\n");
       exit(1);
   }
   newNode->data = val;
   newNode->left = NULL;
   newNode->right = NULL;
   return newNode;
}

node* insert(node* root, int val) {
   if (root == NULL) {
       root = create(val);
   } else {
       if (val < root->data)
           root->left = insert(root->left, val);
       else
           root->right = insert(root->right, val);
   }
   return root;
}

node* search(node* root, int key) {
   if (root == NULL || root->data == key)
       return root;


   if (root->data < key)
       return search(root->right, key);


   return search(root->left, key);
}

node* minValueNode(node* root) {
   node* current = root;
   while (current && current->left != NULL)
       current = current->left;
   return current;
}

node* deleteNode(node* root, int key) {
   if (root == NULL)
       return root;
   if (key < root->data)
       root->left = deleteNode(root->left, key);
   else if (key > root->data)
       root->right = deleteNode(root->right, key);
   else {
       if (root->left == NULL) {
           node* temp = root->right;
           free(root);
           return temp;
       } else if (root->right == NULL) {
           node* temp = root->left;
           free(root);
           return temp;
       }
       node* temp = minValueNode(root->right);
       root->data = temp->data;
       root->right = deleteNode(root->right, temp->data);
   }
   return root;
}

void inorder(node* root) {
   if (root != NULL) {
       inorder(root->left);
       printf("%d ", root->data);
       inorder(root->right);
   }
}

int main() {
   node* root = NULL;
   int choice, key, data;

   while (1) {
       printf("\n1. Insert 2. Search 3. Delete 4. Display (In-order) 5. Exit\n");
       printf("Enter your choice: ");
       scanf("%d", &choice);

       switch (choice) {
           case 1:
               printf("Enter data to insert: ");
               scanf("%d", &data);
               root = insert(root, data);
               printf("Data inserted successfully.\n");
               break;
           case 2:
               printf("Enter key to search: ");
               scanf("%d", &key);
               node* result = search(root, key);
               if (result)
                   printf("Key %d found in the tree.\n", key);
               else
                   printf("Key %d not found in the tree.\n", key);
               break;
           case 3:
               printf("Enter key to delete: ");
               scanf("%d", &key);
               root = deleteNode(root, key);
               printf("Deleted node with key %d from the binary search tree.\n", key);
               break;
           case 4:
               printf("In-order traversal of the binary search tree: ");
               inorder(root);
               printf("\n");
               break;
           case 5:
               printf("Exiting...\n");
               exit(0);
           default:
               printf("Invalid choice.\n");
       }
       
   }

   return 0;
}
