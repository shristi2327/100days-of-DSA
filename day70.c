#include <stdio.h>
#include <limits.h>

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    
    struct Edge edges[10005];
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    
    int start = 0;
    scanf("%d", &start); // fallback to 0 if not matched, but initialized to 0
    
    int dist[1005];
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[start] = 0;
    
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    
    int negative_cycle = 0;
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            negative_cycle = 1;
            break;
        }
    }
    
    if (negative_cycle) {
        printf("NEGATIVE CYCLE\n");
    } else {
        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX) printf("INF ");
            else printf("%d ", dist[i]);
        }
        printf("\n");
    }
    
    return 0;
}
