#include <stdio.h>
#include <stdlib.h>

int adj[1005][1005];
int visited[1005];
int n, m;

int dfs(int u, int parent) {
    visited[u] = 1;
    for (int v = 0; v < n; v++) {
        if (adj[u][v]) {
            if (!visited[v]) {
                if (dfs(v, u)) return 1;
            } else if (v != parent) {
                return 1;
            }
        }
    }
    return 0;
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
            adj[v][u] = 1;
        }
    }
    
    int hasCycle = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                hasCycle = 1;
                break;
            }
        }
    }
    
    if (hasCycle) printf("YES\n");
    else printf("NO\n");
    
    return 0;
}
