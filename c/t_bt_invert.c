/*
1.Given a Binary tree, write a C program to invert the tree, i.e., swap
the left
and right children of every node and display the nodes in the preorder
traversal.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


void invert(Node* node) {
    if (node == NULL)
        return;
    else {
    Node* temp;
    invert(node->left);
    invert(node->right);

    temp = node->left;
    node->left = node->right;
    node->right = temp;
    }
}

void preOrder(Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int main() {

    Node* root = createNode(50);
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
    
    printf("Original tree (pre-order traversal): ");
    preOrder(root);
    printf("\n");
    printf("Original tree (in-order traversal): ");
    inOrder(root);
    printf("\n");
    invert(root);
    printf("\n");
    printf("Inverted tree (pre-order traversal): ");
    preOrder(root);
    printf("\n");
    printf("Inverted tree (in-order traversal): ");
    inOrder(root);
    printf("\n");
    return 0;
}