//SHIVAMBU DEV PANDEY
//23BCS123 
//CSE B
//LAB 
//PROGRAM 

/*
Description:
This program is based on the principles of stack operations, the precedence of operators, and the properties of infix and prefix 
expressions.The program first reverses the input infix expression and replaces all ‘(’ with ‘)’ and vice versa. This is because the 
prefix expression is a mirror image of the postfix expression if the infix expression is scanned from right to left.

Then, it treats the reversed infix expression as if converting to postfix but with an operator precedence rule: if the precedence of 
the scanned operator is less than the operator at the top of the stack, the stack operator is popped and added to the postfix expression. 
This process is repeated until the scanned operator has higher precedence than the operator at the top of the stack. Then the scanned operator 
is pushed onto the stack.

Parentheses are handled by pushing ‘(’ onto the stack and popping operators from the stack and adding them to the postfix expression until
‘(’ is encountered when ‘)’ is scanned.After the entire reversed infix expression is scanned, all operators are popped from the stack and 
added to the postfix expression. The resulting postfix expression is then reversed to get the prefix expression.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int top = -1;
char stack[MAX];

void push(char ch) {
    if (top >= MAX - 1) {
        printf("\nStack Overflow.");
    } else {
        stack[++top] = ch;
    }
}

char pop() {
    if (top < 0) {
        printf("\nStack Underflow.");
        return -1;
    } else {
        return stack[top--];
    }
}

int is_operator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int precedence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '^') {
        return 3;
    }
    return -1;
}

void InfixToPostfix(char infix_exp[], char postfix_exp[]) {
    int i, j;
    char item;
    char x;
    push('(');
    strcat(infix_exp, ")");
    i=0;
    j=0;
    item=infix_exp[i];
    while(item != '\0') {
        if(item == '(') {
            push(item);
        } else if( isdigit(item) || isalpha(item)) {
            postfix_exp[j] = item;
            j++;
        } else if(is_operator(item) == 1) {
            x=pop();
            while(is_operator(x) == 1 && ((precedence(x) > precedence(item)) || (precedence(x) == precedence(item) && item != '^'))) {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(item);
        } else if(item == ')') {
            x = pop();
            while(x != '(') {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
        } else {
            printf("\nInvalid infix Expression.\n");
            exit(1);
        }
        i++;
        item = infix_exp[i];
    }
    postfix_exp[j] = '\0';
}

void reverse(char *exp) {
    int length = strlen(exp);
    int start = 0;
    int end = length - 1;
    char temp;
    while (start < end) {
        temp = exp[start];
        exp[start] = exp[end];
        exp[end] = temp;
        start++;
        end--;
    }
}

void replaceParentheses(char *exp) {
    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(') {
            exp[i] = ')';
        } else if (exp[i] == ')') {
            exp[i] = '(';
        }
    }
}

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];

    printf("Enter Infix expression : ");
    scanf("%[^\n]", infix);
    reverse(infix);
    replaceParentheses(infix);
    InfixToPostfix(infix, postfix);
    reverse(postfix);

    strcpy(prefix, postfix);

    printf("Prefix Expression: %s", prefix);

    return 0;
}
