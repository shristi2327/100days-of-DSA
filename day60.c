#include <stdio.h>

int main() {
    int vals[10000];
    int n = 0;
    while(scanf("%d", &vals[n]) == 1) n++;
    if (n == 0) return 0;
    
    int start = 0;
    if (n > 1 && vals[0] == n - 1) start = 1;
    
    int size = n - start;
    int valid = 1;
    for(int i = 0; i <= (size - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < size && vals[start + i] > vals[start + left]) valid = 0;
        if (right < size && vals[start + i] > vals[start + right]) valid = 0;
    }
    
    if (valid) printf("YES\n");
    else printf("NO\n");
    
    return 0;
}
