#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a node in the phonebook BST
typedef struct PhonebookEntry {
    char name[50];
    char phoneNumber[15];
    struct PhonebookEntry* left;
    struct PhonebookEntry* right;
} PhonebookEntry;

// Function to create a new phonebook entry
PhonebookEntry* createEntry(const char* name, const char* phoneNumber) {
    PhonebookEntry* newEntry = (PhonebookEntry*)malloc(sizeof(PhonebookEntry));
    if (newEntry == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newEntry->name, name);
    strcpy(newEntry->phoneNumber, phoneNumber);
    newEntry->left = NULL;
    newEntry->right = NULL;
    return newEntry;
}

// Function to insert a new entry into the phonebook BST
PhonebookEntry* insertEntry(PhonebookEntry* root, const char* name, const char* phoneNumber) {
    if (root == NULL) {
        root = createEntry(name, phoneNumber);
    } else {
        if (strcmp(name, root->name) < 0)
            root->left = insertEntry(root->left, name, phoneNumber);
        else if (strcmp(name, root->name) > 0)
            root->right = insertEntry(root->right, name, phoneNumber);
        else
            printf("Contact with name '%s' already exists.\n", name);
    }
    return root;
}

// Function to search for a contact by name in the phonebook BST
PhonebookEntry* searchEntry(PhonebookEntry* root, const char* name) {
    if (root == NULL || strcmp(root->name, name) == 0)
        return root;
    if (strcmp(name, root->name) < 0)
        return searchEntry(root->left, name);
    return searchEntry(root->right, name);
}

// Function to perform in-order traversal of the phonebook BST
void inorderTraversal(PhonebookEntry* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("Name: %s, Phone Number: %s\n", root->name, root->phoneNumber);
        inorderTraversal(root->right);
    }
}

int main() {
    PhonebookEntry* phonebook = NULL;
    int choice;
    char name[50], phoneNumber[15];

    while (1) {
        printf("\n1. Add Contact 2. Search Contact 3. Display All Contacts 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phoneNumber);
                phonebook = insertEntry(phonebook, name, phoneNumber);
                printf("Contact added successfully.\n");
                break;
            case 2:
                printf("Enter name to search: ");
                scanf("%s", name);
                PhonebookEntry* result = searchEntry(phonebook, name);
                if (result != NULL)
                    printf("Name: %s, Phone Number: %s\n", result->name, result->phoneNumber);
                else
                    printf("Contact with name '%s' not found.\n", name);
                break;
            case 3:
                printf("All Contacts in Phonebook:\n");
                inorderTraversal(phonebook);
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
