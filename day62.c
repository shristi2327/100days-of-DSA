#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    
    Node** adjList = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < n && v >= 0 && v < n) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->vertex = v;
            newNode->next = adjList[u];
            adjList[u] = newNode;
            
            newNode = (Node*)malloc(sizeof(Node));
            newNode->vertex = u;
            newNode->next = adjList[v];
            adjList[v] = newNode;
        }
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        Node* temp = adjList[i];
        while (temp) {
            printf(" %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
    
    return 0;
}
