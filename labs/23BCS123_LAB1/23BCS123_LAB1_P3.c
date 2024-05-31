//SHIVAMBU DEV PANDEY
//23BCS123 
//CSE B
//LAB 1
//PROGRAM 3
//18 jan 2024
//C program to read 5 integer numbers into a Stack of size 10. The program should be able
//compute the sum, average, maximum and minimum of the numbers in the stack and store them in
//the stack at subsequent positions (LIFO order) respectively.
/*
Description: This is a C program that reads 5 integer numbers into a stack of size 10.
The program computes the sum, average, maximum, and minimum of the numbers in the stack. 
This data is then stored in the stack in subsequent positions in LIFO  order. 
The program provides an option to display the contents of the stack, which will include 
the 5 numbers entered by the user, followed by the sum, average, maximum, and minimum of those numbers.
*/

#include <stdio.h>
#define MAX 10

int top = -1;
int stack[MAX];

void push(int num) {
    if(top == MAX-1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = num;
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

int main() {
    int i, num, sum = 0, max, min;
    float avg;

    printf("Enter 5 integer numbers:\n");
    for(i=0; i<5; i++) {
        scanf("%d", &num);
        push(num);
        sum += num;

        if(i == 0){
            max = num;
            min = num;
        } 
        else{
            if(num > max)
                max = num;
            if(num < min)
                min = num;
        }
    }

    avg = (float)sum / 5;

    push(sum);
    push(avg);
    push(max);
    push(min);

    printf("The sum, average, maximum and minimum of the numbers are stored in the stack.\n");

    int choice;

    
        
        printf("\n1.DISPLAY") ;
        printf("\n2.EXIT");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Order: minimum maximum average sum num5 num4 num3 num2 num1\n");

                display();
                break;

            case 2:
                printf("You have exited the program");
                return 0;
                break;
            default:printf("Error");
                return 0;
                break;
        }
    


    return 0;
}
