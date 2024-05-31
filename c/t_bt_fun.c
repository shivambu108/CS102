#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int count = 0;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        count++;
        return createNode(data);
    } else {
        if (count % 2 == 0)
            root->left = insert(root->left, data);
        else
            root->right = insert(root->right, data);
    }
    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    
    if (root->data < key)
        return search(root->right, key);
    
    return search(root->left, key);
}

void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preOrder(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}


int main() {
    struct Node* root = NULL;
    int choice, key, data;

    while (1) {
        printf("\n1. Insert 2. Search 3. Display (Inorder) 4. Exit\n");
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
                struct Node* result = search(root, key);
                if (result)
                    printf("Key %d found in the tree.\n", key);
                else
                    printf("Key %d not found in the tree.\n", key);
                break;
            case 3:
                printf("Inorder traversal of the binary tree: ");
                inorder(root);
                printf("\n");
                printf("Peorder traversal of the binary tree: ");
                preOrder(root);
                printf("\n"); 
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
