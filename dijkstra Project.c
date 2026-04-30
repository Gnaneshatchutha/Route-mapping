#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF LLONG_MAX

typedef struct Edge {
    int to;
    int weight;
    struct Edge* next;
} Edge;

typedef struct {
    Edge* head;
} Graph;

// Create graph
Graph* createGraph(int n) {
    Graph* graph = (Graph*)malloc(n * sizeof(Graph));
    for (int i = 0; i < n; i++) {
        graph[i].head = NULL;
    }
    return graph;
}

// Add edge
void addEdge(Graph* graph, int u, int v, int w) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->to = v;
    newEdge->weight = w;
    newEdge->next = graph[u].head;
    graph[u].head = newEdge;
}

// Find minimum distance node
int getMinNode(long long dist[], int visited[], int n) {
    long long min = INF;
    int index = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

// Print path
void printPath(int parent[], int v) {
    if (v == -1) return;
    printPath(parent, parent[v]);
    printf(" %d", v);
}

// Dijkstra
void dijkstra(Graph* graph, int n, int start, int end) {
    long long dist[n];
    int visited[n];
    int parent[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[start] = 0;

    for (int i = 0; i < n; i++) {
        int u = getMinNode(dist, visited, n);
        if (u == -1) break;

        visited[u] = 1;

        Edge* temp = graph[u].head;
        while (temp) {
            int v = temp->to;
            int w = temp->weight;

            if (!visited[v] && dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
            temp = temp->next;
        }
    }

    if (dist[end] == INF) {
        printf("NO_PATH\n");
    } else {
        printf("DISTANCE %lld\n", dist[end]);
        printf("PATH");
        printPath(parent, end);
        printf("\n");
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Graph* graph = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u, v, w);
        addEdge(graph, v, u, w); // undirected
    }

    int s, t;
    while (scanf("%d %d", &s, &t) && s != -1) {
        dijkstra(graph, n, s, t);
    }

    return 0;
}