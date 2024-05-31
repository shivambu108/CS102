#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
} Term;

Term* createTerm(int coefficient, int exponent) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    if (newTerm == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

void insertTerm(Term** head, int coefficient, int exponent) {
    Term* newTerm = createTerm(coefficient, exponent);
    if (*head == NULL) {
        *head = newTerm;
    } else {
        Term* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

void displayPolynomial(Term* head) {
    if (head == NULL) {
        printf("Polynomial is empty\n");
        return;
    }

    while (head != NULL) {
        printf("%dx^%d", head->coefficient, head->exponent);
        head = head->next;
        if (head != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    Term* polynomial = NULL;
    int coefficient, exponent;
    char choice;

    do {
        printf("Enter the coefficient and exponent of the term: ");
        scanf("%d %d", &coefficient, &exponent);

        insertTerm(&polynomial, coefficient, exponent);

        printf("Do you want to add another term? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Polynomial expression: ");
    displayPolynomial(polynomial);

    // Free memory
    while (polynomial != NULL) {
        Term* temp = polynomial;
        polynomial = polynomial->next;
        free(temp);
    }

    return 0;
}
