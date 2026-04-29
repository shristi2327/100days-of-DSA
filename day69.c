#include <stdio.h>
#include <limits.h>

int adj[1005][1005];
int dist[1005];
int visited[1005];
int n, m, start;

int minDistance() {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < n; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int main() {
    if (scanf("%d %d", &n, &m) != 2) return 0;
    
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if (u >= 0 && u < n && v >= 0 && v < n) {
            if (adj[u][v] == 0 || w < adj[u][v]) {
                adj[u][v] = w;
                adj[v][u] = w; // Assume undirected unless specified
            }
        }
    }
    
    start = 0;
    scanf("%d", &start);
    
    dist[start] = 0;
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance();
        if (u == -1) break;
        
        visited[u] = 1;
        
        for (int v = 0; v < n; v++) {
            if (!visited[v] && adj[u][v] && dist[u] != INT_MAX && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");
    
    return 0;
}
