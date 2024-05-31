// Shivambu Dev Pandey
// 10 feb
// 4. Sort the elements of queue using stack  in c


#include <stdio.h>
#define SIZE 5

int q[SIZE], front = -1, rear = -1;
int stack[SIZE], top = -1;

void enQueue(int value) {
    if (rear == SIZE - 1)
        printf("Queue is Full!!\n");
    else {
        if (front == -1)
            front = 0;
        rear++;
        q[rear] = value;
        printf("Inserted -> %d\n", value);
    }
}

int deQueue() {
    if (front == -1)
        printf("Queue is Empty!!\n");
    else {
        int temp = q[front];
        front++;
        if (front > rear)
            front = rear = -1;
        return temp;
    }
    return 0;
}

void push(int n){
    if(top==SIZE-1){
        printf("Stack overflow\n");
    }
    else{ 
        top++;
        stack[top]=n;
        int i=top;
        while(i>0){
            if(stack[i]>stack[i-1]){
                int temp=stack[i];
                stack[i]=stack[i-1];
                stack[i-1]=temp;
            }
            i--;
        }
    }
}

int pop(){
    if(top==-1){
        printf("Stack underflow\n");
    }
    else{
        int temp = stack[top];
        top--;
        return temp;
    }
    return 0;
}

void displayQueue() {
    if (rear == -1)
        printf("Queue is Empty!!!\n");
    else {
        int i;
        printf("Queue elements are:\n");
        for (i = front; i <= rear; i++)
            printf("%d  ", q[i]);
        printf("\n");
    }
}

void sortQueue() {
    while(front != -1) {
        push(deQueue());
    }
    while(top != -1) {
        enQueue(pop());
    }
}

int main() {
    int i, value;
    printf("Enter 5 elements to be inserted in the queue:\n");
    for(i=0; i<SIZE; i++) {
        scanf("%d", &value);
        enQueue(value);
    }
    printf("Queue before sorting:\n");
    displayQueue();
    sortQueue();
    printf("Queue after sorting:\n");
    displayQueue();
    return 0;
}
