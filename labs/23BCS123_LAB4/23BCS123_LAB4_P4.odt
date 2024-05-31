//SHIVAMBU DEV PANDEY
//23BCS123 
//CSE B
//LAB 4
//PROGRAM 4
//08/02/2024
/*4.Write a program to search for an element using the linear search approach. The program should be able
to allocate the memory for the required number of elements dynamically when the program is under
execution. Use the suitable dynamic memory allocation functions.*/

/*
Description:
This program performs a linear search on an array. It prompts the user to input the array size and elements, and the element to
search for. If the element is found, it prints its location; if not, it indicates that the element wasn’t found. 
The array memory is dynamically allocated and freed after use.
*/


#include <stdio.h>
#include <stdlib.h>

int linear_search(int *arr, int n, int x) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, x, i, index;
    int *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int*) malloc(n * sizeof(int));
    if(arr == NULL) {
        printf("Memory could not be  allocated.\n");
        exit(0);
    }

    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    printf("Enter the element to search: ");
    scanf("%d", &x);

    index = linear_search(arr, n, x);

    if(index != -1) {
        printf("Element found at location: %d\n", index+1);
    } else {
        printf("Element not found in the array.\n");
    }

    free(arr);

    return 0;
}
