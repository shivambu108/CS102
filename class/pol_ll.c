#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Node structure for Polynomial
struct Node {
    int coefficient;
    int power;
    struct Node* next;
};

// Function to create new node
void create_node(int coeff, int pow, struct Node** temp) {
    struct Node *newNode, *lastNode;
    lastNode = *temp;
    if(lastNode == NULL) {
        newNode =(struct Node*)malloc(sizeof(struct Node));
        newNode->coefficient = coeff;
        newNode->power = pow;
        *temp = newNode;
        newNode-> next = (struct Node*)malloc(sizeof(struct Node));
        newNode = newNode->next;
        newNode->next = NULL;
    } else {
        newNode->coefficient = coeff;
        newNode->power = pow;
        newNode->next = (struct Node*)malloc(sizeof(struct Node));
        newNode = newNode->next;
        newNode->next = NULL;
    }
}

// Function Adding two polynomial numbers
void add_polynomials(struct Node *poly1, struct Node *poly2, struct Node *result) {
    while(poly1->next && poly2->next) {
        if(poly1->power > poly2->power) {
            result->power = poly1->power;
            result->coefficient = poly1->coefficient;
            poly1 = poly1->next;
        }
        else if(poly1->power < poly2->power) {
            result->power = poly2->power;
            result->coefficient = poly2->coefficient;
            poly2 = poly2->next;
        }
        else {
            result->power = poly1->power;
            result->coefficient = poly1->coefficient + poly2->coefficient;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        result->next = (struct Node *)malloc(sizeof(struct Node));
        result = result->next;
        result->next = NULL;
    }
}

// Display Linked list
void display_polynomial(struct Node *node, char var) {
    while(node->next != NULL) {
    	printf("%d%c^%d", node->coefficient, var, node->power);
    	node = node->next;
    	if(node->next != NULL) {
    		printf(" + ");
    	}
    }
}

// Evaluate the polynomial
int evaluate_polynomial(struct Node* poly, int x) {
    int sum = 0;
    while(poly->next != NULL) {
        sum += poly->coefficient * pow(x, poly->power);
        poly = poly->next;
    }
    return sum;
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int num_terms, coeff, pow, x;
    char var;
    
    printf("Enter the variable name: ");
    scanf(" %c", &var);
    
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &num_terms);
    printf("Enter the coefficients and powers for the first polynomial:\n");
    for(int i = 0; i < num_terms; i++) {
        printf("Enter coefficient and power: ");
        scanf("%d%d", &coeff, &pow);
        create_node(coeff, pow, &poly1);
    }
    
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &num_terms);
    printf("Enter the coefficients and powers for the second polynomial:\n");
    for(int i = 0; i < num_terms; i++) {
        printf("Enter coefficient and power: ");
        scanf("%d%d", &coeff, &pow);
        create_node(coeff, pow, &poly2);
    }
 
    printf("1st Polynomial: "); 
    display_polynomial(poly1, var);
 
    printf("\n2nd Polynomial: ");
    display_polynomial(poly2, var);
 
    result = (struct Node *)malloc(sizeof(struct Node));
 
    // Function add two polynomial numbers
    add_polynomials(poly1, poly2, result);
 
    // Display resultant List
    printf("\nAdded polynomial: ");
    display_polynomial(result, var);
    
    printf("\n\nEnter a value for %c to evaluate the polynomials: ", var);
    scanf("%d", &x);
    printf("Evaluation of 1st polynomial: %d", evaluate_polynomial(poly1, x));
    printf("\nEvaluation of 2nd polynomial: %d", evaluate_polynomial(poly2, x));
    printf("\nEvaluation of added polynomial: %d", evaluate_polynomial(result, x));
 
return 0;
}
