#include <stdio.h>
#include <stdlib.h>

#define MAX 8

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

    printf("%c ", v);
    visited[v] = 1;
    queue[rear++] = v;

    while(front != rear) {
        v = queue[front++];
        for(int i = 0; i < MAX; i++) {
            if(adj[v][i] && !visited[i]) {
                queue[rear++] = i;
                printf("%c ", i);
                visited[i] = 1;
            }
        }
    }
}


int main() {
    printf("BFS Traversal: ");
    BFS(0);

    return 0;
}

