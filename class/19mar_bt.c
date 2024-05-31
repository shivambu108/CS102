#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(struct Node* root, int position, int data, char side) {
    struct Node* newNode = createNode(data);
    struct Node* current = root;
    struct Node* parent = NULL;

    int found = 0;
    while (current != NULL && !found) {
        if (current->data == position) {
            found = 1;
            if (side == 'L' || side == 'l') {
                parent = current;
                if (parent->left == NULL) {
                    parent->left = newNode;
                    found = 1;
                } else {
                    printf("Left child already exists at position %d.\n", parent->data);
                    free(newNode);
                }
            } else if (side == 'R' || side == 'r') {
                parent = current;
                if (parent->right == NULL) {
                    parent->right = newNode;
                    found = 1;
                } else {
                    printf("Right child already exists at position %d.\n", parent->data);
                    free(newNode);
                }
            } else {
                printf("Invalid side specified. Please enter 'L' or 'R'.\n");
                free(newNode);
            }
        } else {
            if (current->left != NULL)
                current = current->left;
            else
                current = current->right;
        }
    }

    if (!found)
        printf("Position %d not found in the tree.\n", position);
}

void preOrder(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct Node* root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(struct Node* root) {
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int main() {
    int position, data;
    char side;
    struct Node* root = NULL;

    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    while (1) {
        printf("Enter position, data, and side (L/R) to insert node (or enter -1 to stop): ");
        scanf("%d", &position);
        if (position == -1)
            break;
        scanf("%d %c", &data, &side);

        if (root == NULL) {
            root = createNode(data);
        } else {
            insertNode(root, position, data, side);
        }
    }

    printf("\nPre-order traversal: ");
    preOrder(root);
    printf("\n");

    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}
