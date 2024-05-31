//SHIVAMBU DEV PANDEY
//23BCS123 
//CSE B
//LAB 1
//PROGRAM 1
//18 jan 2024
//MENU DRIVEN C PROGRAM TO ILLUSTRATE STACK OPERATIONS SUCH AS PUSH ,POP AND DISPLAY. 

/*
Description: This is a menu-driven C program that illustrates stack operations such as push, pop, and display.
The program uses an array to implement the stack data structure. The 'push' function is used to add an element 
to the top of the stack, the 'pop' function is used to remove an element from the top of the stack, and the
'display' function is used to print all the elements in the stack from top to bottom. The program continues to 
prompt the user to perform these operations until the user chooses to exit.
*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int top = -1 , stack[MAX];

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
        printf("\n popped element is %d", del_ele);
        top=top-1;
    }
}

void display(){
    int i;
    if(top==-1)
        printf("Stack is empty\n");   
    else{
        for(i=top;i>=0;i--)
            printf("  %d",stack[i]);
    } 
}

int main(){
    int choice,n;

    while(1){
        printf("\n1.PUSH");
        printf("\n2.POP");
        printf("\n3.DISPLAY") ;
        printf("\n4.EXIT");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\n Enter an element to push: ");
                scanf("%d", &n);
                push(n);
                break;
            

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("You have exited the program");
                return 0;
                break;
        }
    }



    return 0;
}
