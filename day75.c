#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long sum;
    int index;
} Prefix;

int cmp(const void *a, const void *b) {
    Prefix *pa = (Prefix *)a;
    Prefix *pb = (Prefix *)b;
    if (pa->sum < pb->sum) return -1;
    if (pa->sum > pb->sum) return 1;
    return pa->index - pb->index;
}

int main() {
    int arr[100005];
    int n = 0;
    while (scanf("%d", &arr[n]) == 1) {
        n++;
    }
    if (n == 0) return 0;
    
    Prefix *p = (Prefix *)malloc(n * sizeof(Prefix));
    long long current_sum = 0;
    int max_len = 0;
    
    for (int i = 0; i < n; i++) {
        current_sum += arr[i];
        p[i].sum = current_sum;
        p[i].index = i;
        if (current_sum == 0) {
            if (i + 1 > max_len) max_len = i + 1;
        }
    }
    
    qsort(p, n, sizeof(Prefix), cmp);
    
    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && p[j].sum == p[i].sum) {
            j++;
        }
        if (j - i > 1) {
            int len = p[j - 1].index - p[i].index;
            if (len > max_len) max_len = len;
        }
        i = j;
    }
    
    printf("%d\n", max_len);
    free(p);
    return 0;
}
