#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
    int height;
} node;

node *createNode(int val) {
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 0; // Initially height of leaf node is set to 0
    return newNode;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(node *root) {
    if (root == NULL)
        return -1; // Height of NULL node is -1
    return max(height(root->left), height(root->right)) + 1;
}

int balanceFactor(node *root) {
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

node *LL_rotation(node *y) {
    node *x = y->left;
    node *T2 = x->right;

    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}
/* LL
      y                   x
     / \                 / \
    x   T3   ----->    T1  y
   / \                     / \
 T1   T2                   T2 T3

*/


node *RR_rotation(node *y) {
    node *x = y->right;
    node *T2 = x->left;

    x->left = y;
    y->right = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

/* RR
    y                    x
   / \                 /   \
  T1  x     ----->    y    T3
     / \             / \
    T2  T3          T1  T2


*/
/* LR

     y                    y                    z
    / \                  / \                 /   \
   x   T4               z   T4   ----->     x     y
  / \                  / \                 / \   / \
 T1   z               x   T3              T1 T2 T3 T4
     / \             / \
    T2  T3          T1 T2


*/

/*RL
     y                    y                    z
    / \                  / \                 /   \
   T1  x               T1  z   ----->      y     x
      / \                 / \             / \   / \
     z   T4              T2  x           T1 T2 T3 T4
    / \                     / \
   T2  T3                  T3 T4


*/

node *minValueNode(node *root) {
    node *current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

node *insert(node *root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    else // Duplicates not allowed 
        return root;

    // Update height of this ancestor node
    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    int balance = balanceFactor(root);

    // Left Left Case
    if (balance > 1 && val < root->left->data)
        return LL_rotation(root);

    // Right Right Case
    if (balance < -1 && val > root->right->data)
        return RR_rotation(root);

    // Left Right Case
    if (balance > 1 && val > root->left->data) {
        root->left = RR_rotation(root->left);
        return LL_rotation(root);
    }

    // Right Left Case
    if (balance < -1 && val < root->right->data) {
        root->right = LL_rotation(root->right);
        return RR_rotation(root);
    }

    return root;
}

void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

node *deleteNode(node *root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL || root->right == NULL) {
            node *temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else // One child case
                *root = *temp; // Copy the contents of the non-empty child

            free(temp);
        } else {
            // Node with two children: Get the inorder successor 
            node *temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    // Update height of the current node
    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    int balance = balanceFactor(root);

    // Left Left Case
    if (balance > 1 && balanceFactor(root->left) >= 0)
        return LL_rotation(root);

    // Right Right Case
    if (balance < -1 && balanceFactor(root->right) <= 0)
        return RR_rotation(root);

    // Left Right Case
    if (balance > 1 && balanceFactor(root->left) < 0) {
        root->left = RR_rotation(root->left);
        return LL_rotation(root);
    }

    // Right Left Case
    if (balance < -1 && balanceFactor(root->right) > 0) {
        root->right = LL_rotation(root->right);
        return RR_rotation(root);
    }

    return root;
}

int main() {
    node *root = NULL;
    int choice, data, key;

    while (1) {
        printf("\n1. Insert 2. Delete 3. Display 4. Exit\n");
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
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("Deleted node with key %d from the AVL tree.\n", key);
                break;
            case 3:
                printf("In-order traversal of the AVL tree: ");
                inorder(root);
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


