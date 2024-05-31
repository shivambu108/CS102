//SHIVAMBU DEV PANDEY
//23BCS123
//CSE B
//LAB 13
//PROGRAM 3
//Date : 18/04/2024

/*
3.Write a C program to perform the BFS traversal for a given graph
(the program should be able to consider directed and undirected graph)
using the below representations:
a.adjacency list
b.adjacency matrix
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure for BFS
struct Queue {
    int items[MAX];
    int front;
    int rear;
};

// Functions for Queue operations
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(struct Queue* queue) {
    if (queue->rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX - 1)
        printf("Queue is full\n");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

// Adjacency List Node
struct Node {
    int vertex;
    struct Node* next;
};

// Adjacency List representation
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

// Adjacency Matrix representation
int adjMatrix[MAX][MAX];
int visitedMatrix[MAX];

// Function to create a node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Function to add an edge to an adjacency list
void addEdgeList(struct Graph* graph, int src, int dest, int directed) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (for undirected graph)
    if (!directed) {
        newNode = createNode(src);
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
    }
}

// Function to add an edge to an adjacency matrix
void addEdgeMatrix(int src, int dest, int directed) {
    adjMatrix[src][dest] = 1;

    // Add edge from dest to src (for undirected graph)
    if (!directed) {
        adjMatrix[dest][src] = 1;
    }
}

// BFS traversal using adjacency list
void BFSList(struct Graph* graph, int startVertex) {
    struct Queue* queue = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("Visited %d\n", currentVertex + 1);

        struct Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }
}

// BFS traversal using adjacency matrix
void BFSMatrix(int vertices, int startVertex) {
    struct Queue* queue = createQueue();

    visitedMatrix[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("Visited %d\n", currentVertex + 1);

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && visitedMatrix[i] == 0) {
                visitedMatrix[i] = 1;
                enqueue(queue, i);
            }
        }
    }
}

int main() {
    int vertices, edges, src, dest, start, choice, directed;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Is the graph directed? (1 for yes, 0 for no): ");
    scanf("%d", &directed);

    printf("Enter edges (Source Destination): \n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdgeList(graph, src - 1, dest - 1, directed);
        addEdgeMatrix(src - 1, dest - 1, directed);
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    printf("Choose the graph representation:\n1. Adjacency List\n2. Adjacency Matrix\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: BFSList(graph, start - 1);
                break;
        case 2: BFSMatrix(vertices, start - 1);
                break;
        default: printf("Invalid choice!\n");
                 break;
    }

    return 0;
}
