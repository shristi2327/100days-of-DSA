#include <stdio.h>

int lower_bound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int upper_bound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 1;

    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    if (scanf("%d", &x) != 1) return 1;

    int lb = lower_bound(arr, n, x);
    int ub = upper_bound(arr, n, x);

    printf("%d %d\n", lb, ub);

    return 0;
}
