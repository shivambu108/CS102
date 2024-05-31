//SHIVAMBU DEV PANDEY
//23BCS123 
//CSE B
//LAB 1
//PROGRAM 2
//18 jan 2024
//C PROGRAM TO DETERMINE IF A GIVEN STRING IS PALINDROME OR NOT USING STACK
/*
Description: This is a C program that determines if a given string is a palindrome or not using a stack.
The program prompts the user to enter a string, and then it pushes each character of the string onto a stack.
It then compares the characters at the top of the stack (the end of the string) and the bottom of the string.
If they are the same, it pops the character from the stack and moves to the next character at the bottom. 
If it finds a mismatch, it declares that the string is not a palindrome. If it successfully compares half 
the string without finding a mismatch, it declares that the string is a palindrome. The program continues 
to prompt the user to check strings until the user chooses to exit.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
int top = -1, bottom = 0;
int stack[MAX];
void push(int n){
    if(top==MAX-1){
        printf("Stack overflow\n");
    }
    else{ 
        top=top+1;
        stack[top]=n;
    }
}
void pop(){
    int del_ele;
    if(top==-1){
        printf("Stack underflow\n");
    }
    else{
        del_ele = stack[top];
        top=top-1;
    }
}
int main()
{
      int i, choice;
      char s[MAX], b;
      
      printf("1.Check string is palindrome. 2.Exit\n");
      
      while (1){
            
            printf("Choose operation : ");
            scanf("%d", &choice);
            switch (choice){
                  case 1:
                        printf("\nEnter string : ");
                        scanf("%s", s);
                        for (i= 0; s[i]!='\0';i++){
                              b = s[i];
                              push(b);
                        }
                        for (i = 0;i <(strlen(s)/ 2);i++){
                              if (stack[top] == stack[bottom]){
                                    pop();
                                    bottom++;
                              }
                              else{
                                    printf("'%s' is not palindrome.\n\n", s);
                                    break;
                              }
                        }
                        if ((strlen(s) / 2)==  bottom)
                              printf("'%s' is palindrome.\n\n",  s);
                        bottom  =  0;
                        top  =  -1;
                        break;
                  case 2:
                        return 0;
                  default: printf("Invalid operation \n");
            }
      }
      return 0;
}
