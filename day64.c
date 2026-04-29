#include <stdio.h>
#include <stdlib.h>

int adj[1005][1005];
int visited[1005];
int queue[1005];
int front = 0, rear = 0;
int n, m;

int main() {
    if (scanf("%d %d", &n, &m) != 2) return 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
    }
    
    int start = 0;
    scanf("%d", &start);
    
    queue[rear++] = start;
    visited[start] = 1;
    
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        
        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
    printf("\n");
    return 0;
}
