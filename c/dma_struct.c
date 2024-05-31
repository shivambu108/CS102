//SHIVAMBU DEV PANDEY
//23BCS123 
//CSE B
//LAB 
//PROGRAM 
//
//

/*
Description:

*/


/*Write a C program that dynamically allocates memory for a structure representing a book. 
The structure should have members for the title, author, and publication year. Prompt the user to enter the number of book_ptr.
The program should be able to read the information about the specified number of book_ptr and print the information for a book 
and display it before freeing the allocated memory.*/
  
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char title[50];
    char author[50];
    int year;
} Book;

int main() {
    int n, i;
    Book *book_ptr;

    printf("Enter the number of book_ptr: ");
    scanf("%d", &n);

    book_ptr = (Book*) malloc(n * sizeof(Book));

    for(i = 0; i < n; i++) {
        printf("Enter title, author and publication year for book %d: ", i+1);
        scanf("%s %s %d", book_ptr[i].title, book_ptr[i].author, &book_ptr[i].year);
    }

    printf("\nBook Information:\n");
    for(i = 0; i < n; i++) {
        printf("Book %d:\n", i+1);
        printf("Title: %s\n", book_ptr[i].title);
        printf("Author: %s\n", book_ptr[i].author);
        printf("Publication Year: %d\n", book_ptr[i].year);
    }

    free(book_ptr);

    return 0;
}



