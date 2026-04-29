#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int m, n;
    if (scanf("%d", &m) != 1) return 0;
    if (scanf("%d", &n) != 1) return 0;
    
    int *table = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) table[i] = -1;
    
    for (int op = 0; op < n; op++) {
        char cmd[10];
        int key;
        if (scanf("%s %d", cmd, &key) != 2) break;
        
        if (strcmp(cmd, "INSERT") == 0) {
            int i = 0;
            while (i < m) {
                int idx = ((key % m) + i * i) % m;
                if (table[idx] == -1 || table[idx] == key) {
                    table[idx] = key;
                    break;
                }
                i++;
            }
        } else if (strcmp(cmd, "SEARCH") == 0) {
            int i = 0;
            int found = 0;
            while (i < m) {
                int idx = ((key % m) + i * i) % m;
                if (table[idx] == key) {
                    found = 1;
                    break;
                }
                if (table[idx] == -1) {
                    break;
                }
                i++;
            }
            if (found) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }
    
    free(table);
    return 0;
}
