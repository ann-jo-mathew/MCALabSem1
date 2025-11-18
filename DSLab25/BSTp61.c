/* Adjacency Matrix using arrays
@Ann Jo Mathew
Roll No: 12
23/10/2025 */

#include <stdio.h>
int main() {
    int vertices, edges;
    int src, dest;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    int adjMatrix[vertices][vertices];
        // Initialize all elements to 0
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;     // For undirected graph
    }
        // Display the adjacency matrix
    printf("\nAdjacency Matrix Representation:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}


