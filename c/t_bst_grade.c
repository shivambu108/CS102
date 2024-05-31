#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a node in the student grade tracking BST
typedef struct Student {
    char name[50];
    int grade;
    struct Student* left;
    struct Student* right;
} Student;

// Function to create a new student node
Student* createStudent(const char* name, int grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newStudent->name, name);
    newStudent->grade = grade;
    newStudent->left = NULL;
    newStudent->right = NULL;
    return newStudent;
}

// Function to insert a new student into the student grade tracking BST
Student* insertStudent(Student* root, const char* name, int grade) {
    if (root == NULL) {
        root = createStudent(name, grade);
    } else {
        if (strcmp(name, root->name) < 0)
            root->left = insertStudent(root->left, name, grade);
        else if (strcmp(name, root->name) > 0)
            root->right = insertStudent(root->right, name, grade);
        else
            printf("Student with name '%s' already exists.\n", name);
    }
    return root;
}

// Function to search for a student by name in the student grade tracking BST
Student* searchStudent(Student* root, const char* name) {
    if (root == NULL || strcmp(root->name, name) == 0)
        return root;
    if (strcmp(name, root->name) < 0)
        return searchStudent(root->left, name);
    return searchStudent(root->right, name);
}

// Function to perform in-order traversal of the student grade tracking BST
void inorderTraversal(Student* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("Name: %s, Grade: %d\n", root->name, root->grade);
        inorderTraversal(root->right);
    }
}

// Function to find the highest performing student in the student grade tracking BST
Student* findHighestPerformingStudent(Student* root) {
    if (root == NULL)
        return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

// Function to find the lowest performing student in the student grade tracking BST
Student* findLowestPerformingStudent(Student* root) {
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

int main() {
    Student* studentGradeTracker = NULL;
    int choice, grade;
    char name[50];

    while (1) {
        printf("\n1. Add Student Grade 2. Search Student Grade 3. Display All Students 4. Highest Performing Student 5. Lowest Performing Student 6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student name: ");
                scanf("%s", name);
                printf("Enter student grade: ");
                scanf("%d", &grade);
                studentGradeTracker = insertStudent(studentGradeTracker, name, grade);
                printf("Student grade added successfully.\n");
                break;
            case 2:
                printf("Enter student name to search: ");
                scanf("%s", name);
                Student* result = searchStudent(studentGradeTracker, name);
                if (result != NULL)
                    printf("Name: %s, Grade: %d\n", result->name, result->grade);
                else
                    printf("Student with name '%s' not found.\n", name);
                break;
            case 3:
                printf("All Students and Their Grades:\n");
                inorderTraversal(studentGradeTracker);
                break;
            case 4:
                printf("Highest Performing Student:\n");
                Student* highest = findHighestPerformingStudent(studentGradeTracker);
                if (highest != NULL)
                    printf("Name: %s, Grade: %d\n", highest->name, highest->grade);
                else
                    printf("No students found.\n");
                break;
            case 5:
                printf("Lowest Performing Student:\n");
                Student* lowest = findLowestPerformingStudent(studentGradeTracker);
                if (lowest != NULL)
                    printf("Name: %s, Grade: %d\n", lowest->name, lowest->grade);
                else
                    printf("No students found.\n");
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
