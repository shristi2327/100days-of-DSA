#include <stdio.h>
#include <stdlib.h>

int adj[1005][1005];
int visited[1005];
int n, m;

void dfs(int u) {
    visited[u] = 1;
    for (int v = 1; v <= n; v++) {
        if (adj[u][v] && !visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    if (scanf("%d %d", &n, &m) != 2) return 0;
    
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u >= 1 && u <= n && v >= 1 && v <= n) {
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
    }
    
    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components++;
            dfs(i);
        }
    }
    
    printf("%d\n", components);
    return 0;
}
