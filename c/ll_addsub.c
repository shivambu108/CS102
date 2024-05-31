//SHIVAMBU DEV PANDEY
//23BCS123
//CSE B
//LAB 6
//PROGRAM 4
//Date : 17/02/2024


/*
4.Write a C program to add/subtract two ordered polynomial expressions using the linked list.
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct Term {
   int coeff;
   int power;
   struct Term* next;
} Term;


Term* createTerm(int coeff, int power) {
   Term* newTerm = (Term*)malloc(sizeof(Term));
   if (newTerm == NULL) {
       printf("Memory allocation error\n");
       exit(EXIT_FAILURE);
   }
   newTerm->coeff = coeff;
   newTerm->power = power;
   newTerm->next = NULL;
   return newTerm;
}
void insertTerm(Term** head, int coeff, int power) {
   Term* newTerm = createTerm(coeff, power);
   if (*head == NULL || power > (*head)->power) {
       newTerm->next = *head;
       *head = newTerm;
   } else {
       Term* current = *head;
       while (current->next != NULL && power < current->next->power) {
           current = current->next;
       }
       newTerm->next = current->next;
       current->next = newTerm;
   }
}


void display(Term* head) {
   if (head == NULL) {
       printf("Polynomial is empty\n");
       return;
   }


   while (head != NULL) {
       printf("%dx^%d", head->coeff, head->power);
       head = head->next;
       if (head != NULL) {
           printf(" + ");
       }
   }
   printf("\n");
}


Term* addPol(Term* poly1, Term* poly2) {
   Term* result = NULL;


   while (poly1 != NULL && poly2 != NULL) {
       if (poly1->power > poly2->power) {
           insertTerm(&result, poly1->coeff, poly1->power);
           poly1 = poly1->next;
       } else if (poly1->power < poly2->power) {
           insertTerm(&result, poly2->coeff, poly2->power);
           poly2 = poly2->next;
       } else {
           int sumCoeff = poly1->coeff + poly2->coeff;
           if (sumCoeff != 0) {
               insertTerm(&result, sumCoeff, poly1->power);
           }
           poly1 = poly1->next;
           poly2 = poly2->next;
       }
   }


   while (poly1 != NULL) {
       insertTerm(&result, poly1->coeff, poly1->power);
       poly1 = poly1->next;
   }


   while (poly2 != NULL) {
       insertTerm(&result, poly2->coeff, poly2->power);
       poly2 = poly2->next;
   }


   return result;
}


Term* subPol(Term* poly1, Term* poly2) {
   Term* result = NULL;


   while (poly1 != NULL && poly2 != NULL) {
       if (poly1->power > poly2->power) {
           insertTerm(&result, poly1->coeff, poly1->power);
           poly1 = poly1->next;
       } else if (poly1->power < poly2->power) {
           insertTerm(&result, -poly2->coeff, poly2->power);
           poly2 = poly2->next;
       } else {
           int diffCoeff = poly1->coeff - poly2->coeff;
           if (diffCoeff != 0) {
               insertTerm(&result, diffCoeff, poly1->power);
           }
           poly1 = poly1->next;
           poly2 = poly2->next;
       }
   }


   while (poly1 != NULL) {
       insertTerm(&result, poly1->coeff, poly1->power);
       poly1 = poly1->next;
   }


   while (poly2 != NULL) {
       insertTerm(&result, -poly2->coeff, poly2->power);
       poly2 = poly2->next;
   }


   return result;
}


void freePol(Term* polynomial) {
   while (polynomial != NULL) {
       Term* temp = polynomial;
       polynomial = polynomial->next;
       free(temp);
   }
}


int main() {
   Term* poly1 = NULL;
   Term* poly2 = NULL;
   Term* res_add = NULL;
   Term* res_sub = NULL;
   int coeff, power;
   char choice;


   printf("Enter the terms of the first polynomial in descending order of powers:\n");
   do {
       printf("Enter the coeff and power of the term: ");
       scanf("%d %d", &coeff, &power);
       insertTerm(&poly1, coeff, power);


       printf("Do you want to add another term to the first polynomial? (y/n): ");
       scanf(" %c", &choice);
   } while (choice == 'y' || choice == 'Y');


   printf("\nEnter the terms of the second polynomial in descending order of powers:\n");
   do {
       printf("Enter the coeff and power of the term: ");
       scanf("%d %d", &coeff, &power);
       insertTerm(&poly2, coeff, power);


       printf("Do you want to add another term to the second polynomial? (y/n): ");
       scanf(" %c", &choice);
   } while (choice == 'y' || choice == 'Y');


   printf("\nFirst Polynomial: ");
   display(poly1);


   printf("\nSecond Polynomial: ");
   display(poly2);


   res_add = addPol(poly1, poly2);
   res_sub = subPol(poly1, poly2);


   printf("\nResultant Polynomial (Sum): ");
   display(res_add);


   printf("\nResultant Polynomial (Subtraction): ");
   display(res_sub);


 
   freePol(poly1);
   freePol(poly2);
   freePol(res_add);
   freePol(res_sub);


   return 0;
}





