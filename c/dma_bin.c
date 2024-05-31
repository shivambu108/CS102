//SHIVAMBU DEV PANDEY
//23BCS123 
//CSE B
//LAB 
//PROGRAM 
//
//

/*
Description:
This program asks the user to enter the number of elements in an array, and then dynamically allocates memory for the array
using malloc. The user is then prompted to enter the elements in ascending order. The program then asks for an element to 
search for in the array. The binary_search function is called with the array, the range of the array (0 to n-1), and the 
element to search for as arguments. If the element is found, its index is printed, otherwise, a message indicating that 
the element was not found is printed. Finally, the allocated memory is freed using free. 
*/


#include <stdio.h>
#include <stdlib.h>

int binary_search(int *arr, int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binary_search(arr, low, mid - 1, x);
        return binary_search(arr, mid + 1, high, x);
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
        printf("Memory not allocated.\n");
        exit(0);
    }

    printf("Enter elements in ascending order: ");
    for(i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    printf("Enter the element to search: ");
    scanf("%d", &x);

    index = binary_search(arr, 0, n - 1, x);

    if(index != -1) {
        printf("Element found at index: %d\n", index);
    } else {
        printf("Element not found in the array.\n");
    }

    free(arr);

    return 0;
}
