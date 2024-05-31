//SHIVAMBU DEV PANDEY
//23BCS123 
//CSE B
//LAB 4
//PROGRAM 3
//08/02/2024
/*3.Write a C program to sort the elements of a Queue data structure. */

/*
Description: 
The sortQueue() function sorts the queue using a simple bubble sort algorithm. It iterates over each element in the queue and 
compares it with every other element, swapping them if they are in the wrong order.
*/

#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

void enQueue(int value) {
    if (rear == SIZE - 1)
        printf("Queue is Full!!\n");
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("Inserted -> %d\n", value);
    }
}

void deQueue() {
    if (front == -1)
        printf("Queue is Empty!!\n");
    else {
        printf("Removed -> %d\n", queue[front]);
        front++;
        if (front > rear)
            front = rear = -1;
    }
}

void display() {
    if (rear == -1)
        printf("Queue is Empty!!!\n");
    else {
        int i;
        printf("Queue elements are:\n");
        for (i = front; i <= rear; i++)
            printf("%d  ", queue[i]);
        printf("\n");
    }
}

void sortQueue() {
    int i, j, temp;
    for (i = front; i <= rear; i++) {
        for (j = i + 1; j <= rear; j++) {
            if (queue[i] > queue[j]) {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
}

int main() {
    enQueue(7);
    enQueue(4);
    enQueue(6);
    enQueue(5);
    printf("Original Queue: ");
    display();
    sortQueue();
    printf("Sorted Queue: ");
    display();
    return 0;
}
