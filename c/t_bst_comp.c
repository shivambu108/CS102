//SHIVAMBU DEV PANDEY
//23BCS123
//CSE B
//LAB 10
//PROGRAM 3
//Date : 28/03/2024

/*
3.Write a C program to check whether two BSTs are identical or not.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

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

int idenBST(node* root1, node* root2) {
    if (root1 == NULL && root2 == NULL)
        return 1;
    else if (root1 == NULL || root2 == NULL)
        return 0;
    else if (root1->data != root2->data)
        return 0;
    else
        return idenBST(root1->left, root2->left) && idenBST(root1->right, root2->right);
}

int main() {
    node* root1 = createNode(6);
    root1->left = createNode(4);
    root1->right = createNode(9);
    root1->left->left = createNode(3);
    root1->left->right = createNode(5);

    node* root2 = createNode(6);
    root2->left = createNode(4);
    root2->right = createNode(9);
    root2->left->left = createNode(3);
    root2->left->right = createNode(5);

    if (idenBST(root1, root2))
        printf("BSTs are identical.\n");
    else
        printf("BSTs are not identical.\n");

    return 0;
}
