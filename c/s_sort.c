//SHIVAMBU DEV PANDEY
//23BCS123 
//CSE B
//LAB 
//PROGRAM 

/*
Description:
This program sorts the stack in ascending order by repeatedly removing the smallest element from the main stack and pushing it into
the correct position in the temporary stack. This process continues until all elements have been removed from the main stack and pushed
into the temporary stack in sorted order. Then, it moves all elements back from the temporary stack to the main stack, resulting in a 
sorted stack. 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int top = -1;
int stack[MAX];

int isEmpty() {
    if(top == -1)
        return 1;
    else
        return 0;
}

void push(int x) {
    if (top >= MAX - 1) {
        printf("Stack Overflow. Unable to push '%d' into the stack.\n", x);
        exit(1);
    }
    stack[++top] = x;
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow.\n");
        exit(1);
    }
    return stack[top--];
}

int peek() {
    if (isEmpty()) {
        printf("Stack Underflow.\n");
        exit(1);
    }
    return stack[top];
}

/*
Sorting Logic (sortStack function):

Create a temporary stack (tempStack) and initialize its top (topTemp) to -1.
While the main stack is not empty:
Pop an element from the main stack and store it in a variable temp.
While the temporary stack is not empty and the top element of the temporary stack is greater than temp:
Pop elements from the temporary stack and push them back onto the main stack until a suitable position for temp is found.
Push temp onto the temporary stack.
After processing all elements in the main stack, move all elements from the temporary stack back to the main stack.
*/

void sortStack() {
    int tempStack[MAX];
    int topTemp = -1;
    while (!isEmpty()) {
        int temp = pop();
        while (topTemp != -1 && tempStack[topTemp] > temp) {
            push(tempStack[topTemp--]);
        }
        tempStack[++topTemp] = temp;
    }
    while (topTemp != -1) {
        push(tempStack[topTemp--]);
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if (n > MAX) {
        printf("Number of elements exceeds stack size.\n");
        return 0;
    }
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        push(num);
    }
    sortStack();
    printf("Sorted elements: ");
    while (!isEmpty()) {
        printf("%d ", pop());
    }
    return 0;
}
