//SHIVAMBU DEV PANDEY
//23BCS123 
//CSE B
//LAB 
//PROGRAM 

/*
Description:
This program is based on the principles of stack operations and the precedence of operators in expressions.
When an expression is entered, the program starts scanning it from left to right. If the scanned character is an operator 
(i.e., ‘+’, ‘-’, ‘', ‘/’, or ‘^’), the program prints its precedence and pushes it onto the stack. The precedence function assigns a 
value of 3 for ‘^’, 2 for '’ and ‘/’, and 1 for ‘+’ and ‘-’.

This process continues until all characters in the expression have been scanned. After the entire expression is scanned, the program ends. 
This program does not evaluate the expression, it only prints the precedence of each operator in the expression.
*/

#include <stdio.h>

#define MAX 100

int top = -1;
char stack[MAX];

void push(char c) {
    if (top >= (MAX - 1)) {
        printf("Stack Overflow.\n");
    } else {
        stack[++top] = c;
    }
}

char pop() {
    if (top < 0) {
        printf("Stack Underflow.\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int precedence(char c) {
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

int main() {
    char exp[MAX];
    printf("Enter an expression: ");
    scanf("%s", exp);

    for(int i = 0; exp[i]; i++) {
        char c = exp[i];
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            printf("Precedence of %c: %d\n", c, precedence(c));
            push(c);
        }
    }

    return 0;
}
