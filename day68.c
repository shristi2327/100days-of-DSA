#include <stdio.h>
#include <stdlib.h>

int adj[1005][1005];
int inDegree[1005];
int queue[1005];
int front = 0, rear = 0;
int result[1005];
int count = 0;
int n, m;

int main() {
    if (scanf("%d %d", &n, &m) != 2) return 0;
    for (int i = 0; i < n; i++) {
        inDegree[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < n && v >= 0 && v < n) {
            if (!adj[u][v]) {
                adj[u][v] = 1;
                inDegree[v]++;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    
    while (front < rear) {
        int u = queue[front++];
        result[count++] = u;
        
        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }
    
    if (count == n) {
        for (int i = 0; i < count; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    } else {
        printf("Cycle detected\n");
    }
    
    return 0;
}
