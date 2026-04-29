#include <stdio.h>
#include <limits.h>

int adj[1005][1005];
int key[1005];
int mstSet[1005];
int n, m;

int minKey() {
    int min = INT_MAX, min_index = -1;
    for (int v = 1; v <= n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int main() {
    if (scanf("%d %d", &n, &m) != 2) return 0;
    
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if (u >= 1 && u <= n && v >= 1 && v <= n) {
            if (adj[u][v] == 0 || w < adj[u][v]) {
                adj[u][v] = w;
                adj[v][u] = w;
            }
        }
    }
    
    key[1] = 0;
    int total_weight = 0;
    
    for (int count = 0; count < n; count++) {
        int u = minKey();
        if (u == -1) break;
        
        mstSet[u] = 1;
        total_weight += key[u];
        
        for (int v = 1; v <= n; v++) {
            if (adj[u][v] && mstSet[v] == 0 && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
            }
        }
    }
    
    printf("%d\n", total_weight);
    return 0;
}
