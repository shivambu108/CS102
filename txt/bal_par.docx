//SHIVAMBU DEV PANDEY
//23BCS123 
//CSE B
//LAB 
//PROGRAM 

/*
Description:
This program is based on the principles of stack operations and the properties of parentheses in expressions.
When an expression is entered, the program starts scanning it from left to right. If the scanned character is an opening parenthesis 
(i.e., ‘(’, ‘{’, or ‘[’), it is pushed onto the stack. If the scanned character is a closing parenthesis (i.e., ‘)’, ‘}’, or ‘]’), 
the program pops an opening parenthesis from the stack and checks if it matches with the closing parenthesis. If they are not a matching pair, 
the program returns that the expression is not balanced.

This process continues until all characters in the expression have been scanned. After the entire expression is scanned, if the stack is empty, 
it means that all opening parentheses have been closed and the expression is balanced. If the stack is not empty, it means that there are some 
opening parentheses that have not been closed, so the expression is not balanced.
*/


#include <stdio.h>

#define MAX 100

int top = -1;
char stack[MAX];

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack[top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    char data = stack[top];
    top--;
    return data;
}

int isMatchingPair(char character1, char character2) {
   if (character1 == '(' && character2 == ')')
     return 1;
   else if (character1 == '{' && character2 == '}')
     return 1;
   else if (character1 == '[' && character2 == ']')
     return 1;
   else
     return 0;
}

int isBalanced(char *exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (!isMatchingPair(pop(), exp[i])) {
                return 0;
            }
        }
    }
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char exp[MAX];
    printf("Enter an expression: ");
    scanf("%s", exp);
    if (isBalanced(exp)) {
        printf("The expression has balanced parentheses.\n");
    } else {
        printf("The expression does not have balanced parentheses.\n");
    }
    return 0;
}
