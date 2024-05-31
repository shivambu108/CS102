//SHIVAMBU DEV PANDEY
//23BCS123
//CSE B
//LAB 10
//PROGRAM 2
//Date : 28/03/2024

/*
2.Write a C program to check if a given binary tree is a valid binary search tree, 
where the values of nodes in the left subtree are less than the node value and 
values in the right subtree are greater.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}node;

node* createNode(int val) {
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

bool checkBST(node* root, int min, int max) {
    if (root == NULL)
        return true;
    
    if (root->data < min || root->data > max)
        return false;
    
    return checkBST(root->left, min, root->data - 1) && checkBST(root->right, root->data + 1, max);
}

int main() {
    
    node* root = createNode(50);
    root->left = createNode(17);
    root->right = createNode(72);
    root->left->left = createNode(12);
    root->left->right = createNode(23);
    root->left->left->left = createNode(9);
    root->left->left->right = createNode(14);
    root->left->right->left = createNode(19);
    root->right->left = createNode(54);
    root->right->right = createNode(76);

    root->right->left->right = createNode(67);

    if (checkBST(root, INT_MIN, INT_MAX))
        printf("The binary tree is a valid BST.\n");
    else
        printf("The binary tree is not a valid BST.\n");

    return 0;
}
