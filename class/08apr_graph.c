// Operations on Graph

#include <stdio.h>
#include <stdlib.h>

void creategraph(int **g, int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf("Enter the weight of edge for %d -> %d: ", i + 1, j + 1);
            scanf("%d", &g[i][j]);
        }
    }
}

void display(int **g, int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (g[i][j] != 0)
            {
                printf(" %d -(%d)-> %d ", i, g[i][j], j);
            }
        }
        printf("\n");
    }
}

void delete (int **g, int v)
{
    int a, b;
    printf("Enter the vertex and vertex connection to delete: ");
    scanf("%d %d", &a, &b);

    g[a - 1][b - 1] = 0;
}

int main()
{
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    int g[v][v];

    printf("Choose the graph operations:\n");

    while (1)
    {
        printf("1. Create graph 2. Delete 3. Display 4. Exit: ");
        int choice;
        scanf("%d", &choice);
        int *p = g;
        int **temp = &p;

        switch (choice)
        {
            case 1:
                creategraph(temp, v);
                break;
            case 2:
                delete(temp, v);
                break;
            case 3:
                display(temp, v);
                break;
            case 4:
                printf("\nExiting the loop...\n");
                exit(0);
            default:
                printf("\nInvalid selection.\n");
                break;
        }
    }
}
