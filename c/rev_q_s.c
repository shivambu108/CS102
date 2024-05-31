//SHIVAMBU DEV PANDEY
//23BCS123 
//CSE B
//LAB 
//PROGRAM 


/*
Reversing first n elements of Queue:
Given a queue and an integer n, reverse the first n elements of the queue using both stack and queue operations.
For example, if the queue initially contains [1, 2, 3, 4, 5] and n is 3, then after reversing, the queue should become [3, 2, 1, 4, 5].
*/


#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int queue[SIZE];
int front = -1;
int rear = -1;

int stack[SIZE];
int top = -1;

int isQueueFull() {
    if (rear == SIZE - 1)
        return 1;
    else
        return 0;
}

int isQueueEmpty() {
    if (rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(int value) {
    if (isQueueFull())
        printf("Queue is full\n");
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
    }
}

int dequeue() {
    int item;
    if (isQueueEmpty()) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
    return item;
}

void push(int value) {
    if (top == SIZE - 1)
        printf("Stack is full\n");
    else {
        top++;
        stack[top] = value;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        int value = stack[top];
        top--;
        return value;
    }
}

void reverseFirstN(int n) {
    if (n > rear + 1) {
        printf("Not enough elements in the queue to reverse\n");
        return;
    }
    
    // Push the first 'n' elements from queue to stack
    for (int i = 0; i < n; i++) {
        push(dequeue());
    }
    
    // Enqueue remaining elements in the queue, if any
    int remainingElements = rear + 1 - n;
    int tempQueue[SIZE];
    for (int i = 0; i < remainingElements; i++) {
        tempQueue[i] = dequeue();
    }
    
    // Pop elements from stack and enqueue them back to queue
    while (top != -1) {
        enqueue(pop());
    }
    
    // Enqueue the remaining elements back to queue
    for (int i = 0; i < remainingElements; i++) {
        enqueue(tempQueue[i]);
    }
}

void display() {
    if (isQueueEmpty())
        printf("Queue is empty\n");
    else {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int numElements, numReverse;
    printf("Enter the number of elements in the queue: ");
    scanf("%d", &numElements);
    printf("Enter the number of elements to reverse: ");
    scanf("%d", &numReverse);
    for (int i = 1; i <= numElements; i++)
        enqueue(i);
    reverseFirstN(numReverse);
    display();
    return 0;
}
