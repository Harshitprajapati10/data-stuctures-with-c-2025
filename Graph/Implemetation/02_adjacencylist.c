#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int dest;
    struct Node* next;
} ListNode;


typedef struct Graph{
    int V;
    ListNode **adj; // same as ListNode *adj[0...V]
} Graph;

ListNode* createNode(int dest){
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    if(!node){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->dest = dest;
    node->next = NULL;
    return node;
}

// create graph with empty lists
Graph* createGraph(int V){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if(!graph){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    graph->V = V;
    // alocates and head to graph->adj
    graph->adj = (ListNode**)malloc(V * sizeof(ListNode*));
    if (!graph->adj) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < V; ++i) graph->adj[i] = NULL;
    return graph;
}

void addEdge(Graph *graph, int u, int v, int undirected) {
    if (!graph) return;
    if (u < 0 || u >= graph->V || v < 0 || v >= graph->V) {
        fprintf(stderr, "addEdge: vertex out of range (u=%d, v=%d)\n", u, v);
        return;
    }
    //u src, v dest
    ListNode* node = createNode(v);
    node->next = graph->adj[u];
    graph->adj[u] = node;

    if(undirected){
        ListNode* node2 = createNode(u);
        node2->next = graph->adj[v];
        graph->adj[v] = node2;
    }
}

void printGraph(Graph *graph) {
    if (!graph) return;
    printf("Adjacency List (vertex : neighbours)\n");
    for (int i = 0; i < graph->V; ++i) {
        printf("%d: ", i);
        ListNode *cur = graph->adj[i];
        if (!cur) {
            printf("(none)");
        } else {
            while (cur) {
                printf("%d", cur->dest);
                if (cur->next) printf(" -> ");
                cur = cur->next;
            }
        }
        printf("\n");
    }
}



void printNeighbors(Graph *graph, int v) {
    if (!graph) return;
    if (v < 0 || v >= graph->V) {
        printf("Vertex %d out of range (0..%d)\n", v, graph->V - 1);
        return;
    }

    printf("Neighbors of %d: ", v);
    ListNode *cur = graph->adj[v];
    if (!cur) {
        printf("(none)");
    } else {
        int first = 1;
        while (cur) {
            if (!first) printf(", ");
            printf("%d", cur->dest);
            first = 0;
            cur = cur->next;
        }
    }
    printf("\n");
}


void freeGraph(Graph *graph) {
    if (!graph) return;
    for (int i = 0; i < graph->V; ++i) {
        ListNode *cur = graph->adj[i];
        while (cur) {
            ListNode *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    free(graph->adj);
    free(graph);
}

int main(void) {
    int V = 5;
    Graph *g = createGraph(V);

    /* Sample undirected graph (same as earlier example)
       Edges:
       0 - 1
       0 - 2
       1 - 2
       1 - 3
       3 - 4
    */
    addEdge(g, 0, 1, 1);
    addEdge(g, 0, 2, 1);
    addEdge(g, 1, 2, 1);
    addEdge(g, 1, 3, 1);
    addEdge(g, 3, 4, 1);

    printf("Undirected graph:\n");
    printGraph(g);
    printf("\n");

    printNeighbors(g, 0);
    printNeighbors(g, 1);
    printNeighbors(g, 2);
    printNeighbors(g, 3);
    printNeighbors(g, 4);

    freeGraph(g);
    return 0;
}