// write a c program to find the longest palindromic substring using stacks

#include <stdio.h>
#include <string.h>

#define MAX 1000

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = ch;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return '\0';
    } else {
        return stack[top--];
    }
}

int isPalindrome(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}

void findLongestPalindromicSubstring(char str[]) {
    int maxLength = 0;
    char longestPalindrome[MAX] = "";
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            char substring[MAX] = "";
            int subLength = 0;
            for (int k = i; k <= j; k++) {
                push(str[k]);
            }
            while (top != -1) {
                substring[subLength++] = pop();
            }
            substring[subLength] = '\0';
            if (isPalindrome(substring) && subLength > maxLength) {
                maxLength = subLength;
                strcpy(longestPalindrome, substring);
            }
        }
    }
    printf("Longest Palindromic Substring: %s\n", longestPalindrome);
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);
    findLongestPalindromicSubstring(str);
    return 0;
}
