//SHIVAMBU DEV PANDEY
//23BCS123 
//CSE B
//LAB 
//PROGRAM 
//
//

/* 
Write a program to implement the the first come first serve CPU scheduling algorithm using the queue.
Sample I/O
Input:
Process Burst_time
P1 20
2 7
3 10
Output:
Average waiting time: (0+20+7)/3=9
*/

/*
Description:
This program implements First-Come-First-Serve (FCFS) CPU scheduling algorithm using a queue data structure. It defines 
three main data structures - Process, Node, and Queue. The Process structure holds the name and burst time of each process, while 
the Node structure forms the linked list for the queue, containing a Process and a pointer to the next node. The Queue structure 
contains pointers to the front and rear of the queue.

The program includes enqueue and dequeue functions to add and remove processes from the queue, respectively. The fcfsScheduling function
implements the FCFS scheduling algorithm. It enqueues all the processes, then dequeues them one by one, calculating the waiting time for
each process and printing the process details.

In the main function, the user is prompted to enter the number of processes and the details for each process. The FCFS scheduling function
is then called, and the average waiting time is calculated and printed.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[10];
    int burst_time;
} Process;

typedef struct Node {
    Process data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void enqueue(Queue* q, Process process) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = process;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

Process dequeue(Queue* q) {
    if (q->front == NULL) {
        Process emptyProcess = {"", 0};
        return emptyProcess; 
    }

    Node* temp = q->front;
    Process process = temp->data;

    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL; 
    }

    free(temp);
    return process;
}

void fcfsScheduling(Process processes[], int n) {
    Queue q = {NULL, NULL};
    int waiting_time = 0;

    printf("Process\tBurst Time\tWaiting Time\n");

    for (int i = 0; i < n; ++i) {
        enqueue(&q, processes[i]);
        Process currentProcess = dequeue(&q);
        waiting_time += currentProcess.burst_time;
        printf("%s\t%d\t\t%d\n", currentProcess.name, currentProcess.burst_time, waiting_time);
    }
}

float avgWait(Process processes[], int n) {
    int waiting_time = 0;

    for (int i = 1; i < n; ++i) {
        waiting_time += processes[i - 1].burst_time;
    }

    return (float)waiting_time / n;
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    for (int i = 0; i < n; ++i) {
        printf("Enter name of process %d: ", i + 1);
        scanf("%s", processes[i].name);
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    fcfsScheduling(processes, n);

    float avg_waiting_time = avgWait(processes, n);
    printf("Average waiting time: %.2f\n", avg_waiting_time);

    return 0;
}
