#include <stdio.h>
#include <stdlib.h>

#define MAX 8

// Adjacency matrix
int adj[MAX][MAX] = {
    {0, 1, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 1, 1, 0},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int visited[MAX];

void BFS(int v) {
    int queue[MAX], front = 0, rear = 0;
    for(int i = 0; i < MAX; i++)
        visited[i] = 0;

    printf("%c ", v+65);
    visited[v] = 1;
    queue[rear++] = v;

    while(front != rear) {
        v = queue[front++];
        for(int i = 0; i < MAX; i++) {
            if(adj[v][i] && !visited[i]) {
                queue[rear++] = i;
                printf("%c ", i+65);
                visited[i] = 1;
            }
        }
    }
}

void DFS(int v) {
    printf("%c ", v+65);
    visited[v] = 1;
    for(int i = 0; i < MAX; i++) {
        if(adj[v][i] && !visited[i])
            DFS(i);
    }
}

int main() {
    printf("BFS Traversal: ");
    BFS(0);
    printf("\nDFS Traversal: ");
    for(int i = 0; i < MAX; i++)
        visited[i] = 0;
    DFS(0);
    return 0;
}



// #include <stdio.h>
// #include <stdlib.h>

// #define MAX 8

// struct Node {
//     int vertex;
//     struct Node* next;
// };

// struct Node* adj[MAX];

// void createEdge(int src, int dest) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->vertex = dest;
//     newNode->next = adj[src];
//     adj[src] = newNode;
// }

// void BFS(int v) {
//     int visited[MAX] = {0};
//     int queue[MAX], front = 0, rear = 0;
//     printf("%c ", v + 65);
//     visited[v] = 1;
//     queue[rear++] = v;

//     while (front != rear) {
//         v = queue[front++];
//         for (struct Node* curr = adj[v]; curr != NULL; curr = curr->next) {
//             int neighbor = curr->vertex;
//             if (!visited[neighbor]) {
//                 printf("%c ", neighbor + 65);
//                 visited[neighbor] = 1;
//                 queue[rear++] = neighbor;
//             }
//         }
//     }
// }

// void DFSUtil(int v, int visited[]) {
//     visited[v] = 1;
//     printf("%c ", v + 65);

//     for (struct Node* curr = adj[v]; curr != NULL; curr = curr->next) {
//         int neighbor = curr->vertex;
//         if (!visited[neighbor]) {
//             DFSUtil(neighbor, visited);
//         }
//     }
// }

// void DFS(int v) {
//     int visited[MAX] = {0};
//     DFSUtil(v, visited);
// }

// int main() {
//     for (int i = 0; i < MAX; i++) {
//         adj[i] = NULL;
//     }

//     createEdge(0, 1);
//     createEdge(0, 3);
//     createEdge(0, 4);
//     createEdge(2, 5);
//     createEdge(3, 2);
//     createEdge(3, 5);
//     createEdge(3, 6);
//     createEdge(4, 2);
//     createEdge(6, 6);

//     printf("BFS Traversal: ");
//     BFS(0);
//     printf("\nDFS Traversal: ");
//     DFS(0);

//     return 0;
// }
