#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Adjacency List Node
struct Node
{
    int vertex;
    struct Node *next;
};

// Adjacency List representation
struct Graph
{
    int numVertices;
    struct Node **adjLists;
    int *visited;
};

// Adjacency Matrix representation
int adjMatrix[MAX][MAX];
int visitedMatrix[MAX];

// Function to create a node
struct Node *createNode(int v)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node *));
    graph->visited = malloc(vertices * sizeof(int));
    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Function to add an edge to an adjacency list
void addEdgeList(struct Graph *graph, int src, int dest, int directed)
{
    // Create a new node for the destination vertex
    struct Node *newNode = createNode(dest);
    
    // Insert the new node at the beginning of the adjacency list of the source vertex
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    
    // If the graph is undirected, add an edge from the destination to the source as well
    if (!directed)
    {
        // Create a new node for the source vertex
        newNode = createNode(src);
        
        // Insert the new node at the beginning of the adjacency list of the destination vertex
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
    }
}

// Function to add an edge to an adjacency matrix
void addEdgeMatrix(int src, int dest, int directed)
{
    adjMatrix[src][dest] = 1;
    
    // For undirected graph add edge from dest to src
    if (!directed)
    {
        adjMatrix[dest][src] = 1;
    }
}

// DFS using adjacency list
void DFSList(struct Graph *graph, int vertex)
{
    struct Node *adjList = graph->adjLists[vertex];
    struct Node *temp = adjList;
    graph->visited[vertex] = 1;
    printf("Visited %d \n", vertex + 1);
    while (temp != NULL)
    {
        int connectedVertex = temp->vertex;
        if (graph->visited[connectedVertex] == 0)
        {
            DFSList(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

// DFS using adjacency matrix
void DFSMatrix(int vertices, int startVertex)
{
    visitedMatrix[startVertex] = 1;
    printf("Visited %d\n", startVertex + 1);
    for (int i = 0; i < vertices; i++)
    {
        if (adjMatrix[startVertex][i] == 1 && visitedMatrix[i] == 0)
        {
            DFSMatrix(vertices, i);
        }
    }
}

int main()
{
    int vertices, edges, src, dest, start, choice, directed;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Is the graph directed? (1 for yes, 0 for no): ");
    scanf("%d", &directed);
    struct Graph *graph = createGraph(vertices);
    printf("Enter edges (Source Destination): \n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &src, &dest);
        addEdgeList(graph, src - 1, dest - 1, directed);
        addEdgeMatrix(src - 1, dest - 1, directed);
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    printf("Choose the graph representation:\n1. Adjacency List\n2. Adjacency Matrix\n");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
            DFSList(graph, start - 1);
            break;
        case 2:
            DFSMatrix(vertices, start - 1);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}
