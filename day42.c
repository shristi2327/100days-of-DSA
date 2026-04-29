#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    int queue[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }
    
    int stack[n];
    int top = -1;
    
    for (int i = 0; i < n; i++) {
        stack[++top] = queue[i];
    }
    for (int i = 0; i < n; i++) {
        queue[i] = stack[top--];
    }
    
    int first = 1;
    for (int i = 0; i < n; i++) {
        if (!first) printf(" ");
        printf("%d", queue[i]);
        first = 0;
    }
    printf("\n");
    return 0;
}
