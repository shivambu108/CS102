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
    if (*head == NULL || exponent > (*head)->exponent) {
        newTerm->next = *head;
        *head = newTerm;
    } else {
        Term* current = *head;
        while (current->next != NULL && exponent < current->next->exponent) {
            current = current->next;
        }
        newTerm->next = current->next;
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

Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sumCoeff = poly1->coefficient + poly2->coefficient;
            if (sumCoeff != 0) {
                insertTerm(&result, sumCoeff, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}

int main() {
    Term* poly1 = NULL;
    Term* poly2 = NULL;
    Term* result = NULL;
    int coefficient, exponent;
    char choice;

    printf("Enter the terms of the first polynomial in descending order of exponents:\n");
    do {
        printf("Enter the coefficient and exponent of the term: ");
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly1, coefficient, exponent);

        printf("Do you want to add another term to the first polynomial? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nEnter the terms of the second polynomial in descending order of exponents:\n");
    do {
        printf("Enter the coefficient and exponent of the term: ");
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly2, coefficient, exponent);

        printf("Do you want to add another term to the second polynomial? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nFirst Polynomial: ");
    displayPolynomial(poly1);

    printf("\nSecond Polynomial: ");
    displayPolynomial(poly2);

    result = addPolynomials(poly1, poly2);

    printf("\nResultant Polynomial (Sum): ");
    displayPolynomial(result);

    // Free memory
    while (poly1 != NULL) {
        Term* temp = poly1;
        poly1 = poly1->next;
        free(temp);
    }

    while (poly2 != NULL) {
        Term* temp = poly2;
        poly2 = poly2->next;
        free(temp);
    }

    while (result != NULL) {
        Term* temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}
