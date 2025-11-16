#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//initialize adj matrix to 0

void initMatrix(int adj[][MAX], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; i <  n; i++){
            adj[i][j] = 0;
        }    
    }
}

void printAdjMatrix(int adj[][MAX], int n) {
    printf("   ");
    for (int j = 0; j < n; ++j) printf("%d ", j);
    printf("\n");
    for (int i = 0; i < n; ++i) {
        printf("%d: ", i);
        for (int j = 0; j < n; ++j) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

void addEdge(int adj[][MAX], int u, int v, int undirected){
    if(u<0 || v<0) return;
    adj[u][v] = 1;
    if(undirected) adj[v][u] = 1;
}


// print neighbours of given vertex
void printNeighbors(int adj[][MAX], int n, int v){
    if(v<0 || v>=n){
        printf("Vertex %d is out of range (0..%d)\n", v, n-1);
        return;
    }
    printf("Neighbors of vertex %d: ", v);
    int found = 0;
    for(int j = 0; j<n; ++j){
        if(adj[v][j]){
            if(found) printf(", ");
            printf("%d", j);
            found = 1;
        }
    }
    if(!found) printf("(none)");
    printf("\n");
}


int main(){
    int n = 5; 
    static int adj[MAX][MAX];
    initMatrix(adj, n);
    printAdjMatrix(adj, n);
    // undirected graph
    /*
    0 --- 1 --- 2
    |     |
    2     3 --- 4
    */
    addEdge(adj, 0, 1, 1);
    addEdge(adj, 0, 2, 1);
    addEdge(adj, 1, 2, 1);
    addEdge(adj, 1, 3, 1);
    addEdge(adj, 3, 4, 1);

    printf("Adjacency Matrix:\n");
    printAdjMatrix(adj, n);
    printf("\n");


    printNeighbors(adj, n, 0); 
    printNeighbors(adj, n, 1); 
    printNeighbors(adj, n, 2); 
    printNeighbors(adj, n, 3); 
    printNeighbors(adj, n, 4);


    /*
    0 → 1 → 3 → 4
    ↓    ↑
    2 ───┘

    */
    int m = 5;
    static int adj1[MAX][MAX];
    initMatrix(adj1, m);

    // ----------- Directed Graph Edges ------------
    addEdge(adj1, 0, 1, 0);  // 0 → 1
    addEdge(adj1, 0, 2, 0);  // 0 → 2
    addEdge(adj1, 2, 1, 0);  // 2 → 1
    addEdge(adj1, 1, 3, 0);  // 1 → 3
    addEdge(adj1, 3, 4, 0);  // 3 → 4
    printf("Directed Graph - Adjacency Matrix:\n");
    printAdjMatrix(adj1, m);
    printf("\n");
    
    // Print outgoing neighbors
    printNeighbors(adj1, m, 0);
    printNeighbors(adj1, m, 1);
    printNeighbors(adj1, m, 2);
    printNeighbors(adj1, m, 3);
    printNeighbors(adj1, m, 4);
    return 0;
}

// space complexity : 0|V^2|
// finding neighbours : {V}
