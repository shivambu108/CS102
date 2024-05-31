//SHIVAMBU DEV PANDEY
//23BCS123 
//CSE B
//LAB 
//PROGRAM 
//
//

/*
Description:

*/


#include<stdio.h>
#define MAX 50

int deque_arr[MAX];
int front = -1;
int rear = -1;

void insert_front(int item) {
    if((front == 0 && rear == MAX-1) || (front == rear+1)) {
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1) {
        front = 0;
        rear = 0;
    } else if(front == 0)
        front = MAX-1;
    else
        front = front-1;
    deque_arr[front] = item;
}

void insert_rear(int item) {
    if((front == 0 && rear == MAX-1) || (front == rear+1)) {
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1) {
        front = 0;
        rear = 0;
    } else if(rear == MAX-1)
        rear = 0;
    else
        rear = rear+1;
    deque_arr[rear] = item;
}

void delete_front() {
    if(front == -1) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted from queue is : %d\n", deque_arr[front]);
    if(front == rear) {
        front = -1;
        rear = -1;
    } else if(front == MAX-1)
        front = 0;
    else
        front = front+1;
}

void delete_rear() {
    if(front == -1) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted from queue is : %d\n", deque_arr[rear]);
    if(front == rear) {
        front = -1;
        rear = -1;
    } else if(rear == 0)
        rear = MAX-1;
    else
        rear = rear-1;
}

void display_queue() {
    int front_pos = front, rear_pos = rear;
    if(front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements :\n");
    if(front_pos <= rear_pos) {
        while(front_pos <= rear_pos) {
            printf("%d ", deque_arr[front_pos]);
            front_pos++;
        }
    } else {
        while(front_pos <= MAX-1) {
            printf("%d ", deque_arr[front_pos]);
            front_pos++;
        }
        front_pos = 0;
        while(front_pos <= rear_pos) {
            printf("%d ", deque_arr[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}

int main() {
    int choice, item;
    while(1) {
        printf("1.Insert at front\n2.Insert at rear\n3.Delete from front\n4.Delete from rear\n5.Display\n6.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Input the element for adding in queue : ");
                scanf("%d", &item);
                insert_front(item);
                break;
            case 2:
                printf("Input the element for adding in queue : ");
                scanf("%d", &item);
                insert_rear(item);
                break;
            case 3:
                delete_front();
                break;
            case 4:
                delete_rear();
                break;
            case 5:
                display_queue();
                break;
            case 6:
                exit(1);
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
