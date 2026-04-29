#include <stdio.h>
#include <stdlib.h>

int adj[1005][1005];
int visited[1005];
int stack[1005];
int top = -1;
int n, m;

void dfs(int u) {
    visited[u] = 1;
    for (int v = 0; v < n; v++) {
        if (adj[u][v] && !visited[v]) {
            dfs(v);
        }
    }
    stack[++top] = u;
}

int main() {
    if (scanf("%d %d", &n, &m) != 2) return 0;
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u][v] = 1;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
    
    return 0;
}
