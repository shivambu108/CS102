//SHIVAMBU DEV PANDEY
//23BCS123 
//CSE B
//LAB 
//PROGRAM 

/*
Description:
This program is based on the principles of stack operations and the properties of prefix expressions.
When a prefix expression is entered, the program starts scanning it from right to left. If the scanned character is a digit, 
it is converted to an integer and pushed onto the stack. If the scanned character is an operator, two operands are popped from the stack, 
and the operation is performed. The result of the operation is then pushed back onto the stack.
This process continues until all characters in the prefix expression have been scanned. After the entire prefix expression is scanned, 
the final value of the expression is the only element left in the stack, which is then popped and printed.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int item) {
    if(top >= MAX-1) {
        printf("\nStack Overflow.\n");
    } else {
        stack[++top] = item;
    }
}

int pop() {
    if(top < 0) {
        printf("Stack Underflow.\n");
        exit(1);
    } else {
        return stack[top--];
    }
}

void evaluatePrefix(char* exp) {
    int i, num, op1, op2, value;
    char c;

    for(i = strlen(exp)-1; i >= 0; i--) {
        c = exp[i];

        if(isdigit(c)) {
            num = c - '0';
            while(i > 0 && isdigit(exp[i-1])) {
                i--;
                num = num + (exp[i] - '0') * 10;
            }
            push(num);
        } else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            op1 = pop();
            op2 = pop();

            switch(c) {
                case '+': value = op1 + op2; break;
                case '-': value = op1 - op2; break;
                case '*': value = op1 * op2; break;
                case '/': 
                    if(op2 == 0) {
                        printf("Error: Division by zero.\n");
                        exit(1);
                    }
                    value = op1 / op2; 
                    break;
                case '^': value = pow(op1, op2); break;
            }

            push(value);
        }
    }

    printf("\nValue of prefix expression: %d\n", pop());
}

int main() {
    char exp[MAX];

    printf("Enter a prefix expression: ");
    fgets(exp, MAX, stdin);
    exp[strcspn(exp, "\n")] = 0; // Remove newline character

    evaluatePrefix(exp);

    return 0;
}
