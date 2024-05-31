//SHIVAMBU DEV PANDEY
//23BCS123 
//CSE B
//LAB 
//PROGRAM 
//
//



#include <stdio.h>
#include <stdlib.h>

// Stack implementation for Tower of Hanoi
#define MAX 100
int top = -1, stack[MAX];

void push(int n) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        top = top + 1;
        stack[top] = n;
    }
}

int pop() {
    int popped_element;
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);  // Exit the program in case of underflow
    } else {
        popped_element = stack[top];
        top = top - 1;
        return popped_element;
    }
}

int isStackEmpty() {
    return top == -1;
}

// Tower of Hanoi using stacks
void toh(int disk, char src, char dest, char aux) {
    while (1) {
        if (disk > 0) {
            push(disk);
            push(src);
            push(dest);
            push(aux);

            disk = disk - 1;
            char temp = aux;
            aux = dest;
            dest = temp;
        } else {
            if (isStackEmpty()) {
                break;
            }

            aux = pop();
            dest = pop();
            src = pop();
            disk = pop();

            printf("\nMove disk %d from %c to %c", disk, src, dest);

            disk = disk - 1;
            char temp = src;
            src = aux;
            aux = temp;
        }
    }
}

int main() {
    int num;
    printf("Enter the number of disks: ");
    scanf("%d", &num);

    toh(num, 'S', 'D', 'A');

    return 0;
}
