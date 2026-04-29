#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    char **names = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        names[i] = (char *)malloc(105 * sizeof(char));
        scanf("%s", names[i]);
    }
    
    qsort(names, n, sizeof(char *), cmp);
    
    int max_votes = 0;
    char winner[105] = "";
    
    int current_votes = 0;
    char current_name[105] = "";
    
    for (int i = 0; i < n; i++) {
        if (i == 0 || strcmp(names[i], current_name) != 0) {
            if (current_votes > max_votes) {
                max_votes = current_votes;
                strcpy(winner, current_name);
            }
            strcpy(current_name, names[i]);
            current_votes = 1;
        } else {
            current_votes++;
        }
    }
    if (current_votes > max_votes) {
        max_votes = current_votes;
        strcpy(winner, current_name);
    }
    
    printf("%s %d\n", winner, max_votes);
    
    for (int i = 0; i < n; i++) {
        free(names[i]);
    }
    free(names);
    return 0;
}
